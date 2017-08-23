// Copyright (c) 2017 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/installer/util/google_update_settings.h"

namespace {

// Type for the function pointer to enable and disable crash reporting on
// windows. Needed because the function is loaded from chrome_elf.
typedef void (*SetUploadConsentPointer)(bool);

// The name of the function used to set the uploads enabled state in
// components/crash/content/app/crashpad.cc. This is used to call the function
// exported by the chrome_elf dll.
const char kCrashpadUpdateConsentFunctionName[] = "SetUploadConsentImpl";

const char kConsentToSendStats[] = "Consent To Send Stats";

bool UpdateConsentFile(bool consented) {
  base::FilePath consent_dir;
  PathService::Get(chrome::DIR_USER_DATA, &consent_dir);
  if (!base::DirectoryExists(consent_dir))
    return false;

  base::FilePath consent_file = consent_dir.AppendASCII(kConsentToSendStats);
  if (!consented) {
    return base::DeleteFile(consent_file, false);
  }

  if (base::PathExists(consent_file))
    return true;

  std::string tmp_guid;
  int size = tmp_guid.size();
  return base::WriteFile(consent_file, tmp_guid.c_str(), size) == size;
}

}  // namespace

bool GoogleUpdateSettings::GetCollectStatsConsent() {
  base::FilePath consent_file;
  PathService::Get(chrome::DIR_USER_DATA, &consent_file);
  consent_file = consent_file.Append(kConsentToSendStats);

  if (!base::DirectoryExists(consent_file.DirName()))
    return false;

  std::string tmp_guid;
  return base::ReadFileToString(consent_file, &tmp_guid);
}

bool GoogleUpdateSettings::SetCollectStatsConsent(bool consented) {
  if (UpdateConsentFile(consented)) {
    install_static::SetCollectStatsInSample(consented);

    // Next, get Crashpad to pick up the sampling state for this session.
    // The crash reporting is handled by chrome_elf.dll.
    HMODULE elf_module = GetModuleHandle(chrome::kChromeElfDllName);
    static SetUploadConsentPointer set_upload_consent =
        reinterpret_cast<SetUploadConsentPointer>(
            GetProcAddress(elf_module, kCrashpadUpdateConsentFunctionName));

    if (set_upload_consent) {
      set_upload_consent(consented);
    }
    return true;
  }

  return false;
}
