// Copyright (c) 2016 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/common/importer/chrome_importer_utils.h"

#include <memory>
#include <string>

#include "base/files/file_util.h"
#include "base/json/json_reader.h"
#include "base/values.h"
#include "chrome/common/importer/importer_data_types.h"

base::ListValue* GetChromeSourceProfiles(
  const base::FilePath& user_data_folder) {
  base::ListValue* profiles = new base::ListValue();
  base::FilePath local_state_path =
    user_data_folder.Append(
      base::FilePath::StringType(FILE_PATH_LITERAL("Local State")));
  if (!base::PathExists(local_state_path)) {
      base::DictionaryValue* entry = new base::DictionaryValue();
      entry->SetString("id", "Default");
      entry->SetString("name", "Default");
      profiles->Append(std::unique_ptr<base::DictionaryValue>(entry));
  } else {
    std::string local_state_content;
    base::ReadFileToString(local_state_path, &local_state_content);
    std::unique_ptr<base::Value> local_state =
      base::JSONReader::Read(local_state_content);
    const base::DictionaryValue* local_state_dict;
    const base::DictionaryValue* profile_dict;
    const base::DictionaryValue* info_cache;
    if (!local_state || !local_state->GetAsDictionary(&local_state_dict))
      return profiles;

    if (local_state_dict->GetDictionary("profile", &profile_dict)) {
      if (profile_dict->GetDictionary("info_cache", &info_cache)) {
        for (base::DictionaryValue::Iterator it(*info_cache);
             !it.IsAtEnd(); it.Advance()) {
          const base::DictionaryValue* profile;
          if (!it.value().GetAsDictionary(&profile))
            continue;
          std::string name;
          profile->GetString("name", &name);
          base::DictionaryValue* entry = new base::DictionaryValue();
          entry->SetString("id", it.key());
          entry->SetString("name", name);
          profiles->Append(std::unique_ptr<base::DictionaryValue>(entry));
        }
      }
    }
  }
  return profiles;
}

bool ChromeImporterCanImport(const base::FilePath& profile,
                             uint16_t* services_supported) {
  DCHECK(services_supported);
  *services_supported = importer::NONE;

  base::FilePath bookmarks =
    profile.Append(base::FilePath::StringType(FILE_PATH_LITERAL("Bookmarks")));
  base::FilePath history =
    profile.Append(base::FilePath::StringType(FILE_PATH_LITERAL("History")));
  base::FilePath cookies =
    profile.Append(base::FilePath::StringType(FILE_PATH_LITERAL("Cookies")));

  if (base::PathExists(bookmarks))
    *services_supported |= importer::FAVORITES;
  if (base::PathExists(history))
    *services_supported |= importer::HISTORY;
  if (base::PathExists(cookies))
    *services_supported |= importer::COOKIES;

  return *services_supported != importer::NONE;
}

base::DictionaryValue* GetChromeResources(
  const base::FilePath& profile) {
  base::DictionaryValue* resource = new base::DictionaryValue();
  return resource;
}
