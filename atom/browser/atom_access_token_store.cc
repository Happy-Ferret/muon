// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/browser/atom_access_token_store.h"

#include <utility>

#include "atom/common/google_api_key.h"
#include "base/environment.h"
#include "chrome/browser/profiles/profile.h"
#include "chrome/browser/profiles/profile_manager.h"
#include "content/public/browser/browser_thread.h"
#include "device/geolocation/geolocation_provider.h"

using content::BrowserThread;

namespace atom {

namespace {

// Notice that we just combined the api key with the url together here, because
// if we use the standard {url: key} format Chromium would override our key with
// the predefined one in common.gypi of libchromiumcontent, which is empty.
const char* kGeolocationProviderURL =
    GOOGLEAPIS_ENDPOINT
    GOOGLEAPIS_API_KEY;

// Loads access tokens and other necessary data on the UI thread, and
// calls back to the originator on the originating thread.
class TokenLoadingJob : public base::RefCountedThreadSafe<TokenLoadingJob> {
 public:
  explicit TokenLoadingJob(
      const device::AccessTokenStore::LoadAccessTokensCallback& callback)
      : callback_(callback), request_context_getter_(nullptr) {}

  void Run() {
    BrowserThread::PostTaskAndReply(
        BrowserThread::UI,
        FROM_HERE,
        base::Bind(&TokenLoadingJob::PerformWorkOnUIThread, this),
        base::Bind(&TokenLoadingJob::RespondOnOriginatingThread, this));
  }

 private:
  friend class base::RefCountedThreadSafe<TokenLoadingJob>;

  ~TokenLoadingJob() {}

  void PerformWorkOnUIThread() {
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    Profile* profile = ProfileManager::GetPrimaryUserProfile();
    request_context_getter_ = profile->GetRequestContext();
  }

  void RespondOnOriginatingThread() {
    // Equivelent to access_token_map[kGeolocationProviderURL].
    // Somehow base::string16 is causing compilation errors when used in a pair
    // of std::map on Linux, this can work around it.
    device::AccessTokenStore::AccessTokenMap access_token_map;
    std::pair<GURL, base::string16> token_pair;
    token_pair.first = GURL(kGeolocationProviderURL);
    access_token_map.insert(token_pair);

    callback_.Run(access_token_map, request_context_getter_);
  }

  device::AccessTokenStore::LoadAccessTokensCallback callback_;
  net::URLRequestContextGetter* request_context_getter_;
};

}  // namespace

AtomAccessTokenStore::AtomAccessTokenStore() {
  device::GeolocationProvider::GetInstance()->UserDidOptIntoLocationServices();
}

AtomAccessTokenStore::~AtomAccessTokenStore() {
}

void AtomAccessTokenStore::LoadAccessTokens(
    const LoadAccessTokensCallback& callback) {
  scoped_refptr<TokenLoadingJob> job(new TokenLoadingJob(callback));
  job->Run();
}

void AtomAccessTokenStore::SaveAccessToken(const GURL& server_url,
                                           const base::string16& access_token) {
}

}  // namespace atom
