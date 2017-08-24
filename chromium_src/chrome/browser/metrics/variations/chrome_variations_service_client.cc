// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/metrics/variations/chrome_variations_service_client.h"

#include "base/bind.h"
#include "base/threading/sequenced_worker_pool.h"
#include "build/build_config.h"
#include "chrome/browser/browser_process.h"
#include "chrome/common/channel_info.h"
#include "components/version_info/version_info.h"
#include "content/public/browser/browser_thread.h"

namespace {

base::Version GetVersionForSimulation() {
  return base::Version(version_info::GetVersionNumber());
}

}  // namespace

ChromeVariationsServiceClient::ChromeVariationsServiceClient() {}

ChromeVariationsServiceClient::~ChromeVariationsServiceClient() {}

std::string ChromeVariationsServiceClient::GetApplicationLocale() {
  return g_browser_process->GetApplicationLocale();
}

base::SequencedWorkerPool* ChromeVariationsServiceClient::GetBlockingPool() {
  return content::BrowserThread::GetBlockingPool();
}

base::Callback<base::Version(void)>
ChromeVariationsServiceClient::GetVersionForSimulationCallback() {
  return base::Bind(&GetVersionForSimulation);
}

net::URLRequestContextGetter*
ChromeVariationsServiceClient::GetURLRequestContext() {
  return g_browser_process->system_request_context();
}

network_time::NetworkTimeTracker*
ChromeVariationsServiceClient::GetNetworkTimeTracker() {
  return g_browser_process->network_time_tracker();
}

version_info::Channel ChromeVariationsServiceClient::GetChannel() {
  return version_info::Channel::UNKNOWN;
}

bool ChromeVariationsServiceClient::OverridesRestrictParameter(
    std::string* parameter) {
  return false;
}

void ChromeVariationsServiceClient::OnInitialStartup() {}
