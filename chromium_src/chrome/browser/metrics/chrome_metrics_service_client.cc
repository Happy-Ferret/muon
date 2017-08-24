// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/metrics/chrome_metrics_service_client.h"

#include "base/memory/ptr_util.h"
#include "build/build_config.h"
#include "chrome/browser/chrome_notification_types.h"
#include "content/public/browser/notification_service.h"

ChromeMetricsServiceClient::ChromeMetricsServiceClient(
    metrics::MetricsStateManager* state_manager) {
  RegisterForNotifications();
}

ChromeMetricsServiceClient::~ChromeMetricsServiceClient() {}

// static
std::unique_ptr<ChromeMetricsServiceClient> ChromeMetricsServiceClient::Create(
    metrics::MetricsStateManager* state_manager) {
  return std::unique_ptr<ChromeMetricsServiceClient>(
      new ChromeMetricsServiceClient(state_manager));
}

// static
bool ChromeMetricsServiceClient::IsMetricsReportingForceEnabled() {
  return false;
}

void ChromeMetricsServiceClient::RegisterForNotifications() {
  registrar_.Add(this, chrome::NOTIFICATION_BROWSER_OPENED,
                 content::NotificationService::AllBrowserContextsAndSources());
  // Observe history deletions for all profiles.
  registrar_.Add(this, chrome::NOTIFICATION_PROFILE_ADDED,
                 content::NotificationService::AllBrowserContextsAndSources());
  registrar_.Add(this, chrome::NOTIFICATION_PROFILE_DESTROYED,
                 content::NotificationService::AllBrowserContextsAndSources());
}

void ChromeMetricsServiceClient::Observe(
    int type,
    const content::NotificationSource& source,
    const content::NotificationDetails& details) {
  switch (type) {
    case chrome::NOTIFICATION_BROWSER_OPENED:
    case chrome::NOTIFICATION_PROFILE_ADDED:
    case chrome::NOTIFICATION_PROFILE_DESTROYED:
      // May have closed last incognito window.
      UpdateRunningServices();
      break;

    default:
      NOTREACHED();
  }
}
