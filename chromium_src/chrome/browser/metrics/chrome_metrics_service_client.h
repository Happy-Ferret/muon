// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_METRICS_CHROME_METRICS_SERVICE_CLIENT_H_
#define CHROME_BROWSER_METRICS_CHROME_METRICS_SERVICE_CLIENT_H_

#include <stdint.h>

#include <memory>

#include "base/callback.h"
#include "base/macros.h"
#include "base/memory/weak_ptr.h"
#include "base/threading/thread_checker.h"
#include "build/build_config.h"
#include "components/metrics/metrics_service_client.h"
#include "components/metrics/metrics_state_manager.h"
#include "content/public/browser/notification_observer.h"
#include "content/public/browser/notification_registrar.h"

// ChromeMetricsServiceClient provides an implementation of MetricsServiceClient
// that depends on chrome/.
class ChromeMetricsServiceClient : public metrics::MetricsServiceClient,
                                   public content::NotificationObserver {
 public:
  ~ChromeMetricsServiceClient() override;

  // Factory function.
  static std::unique_ptr<ChromeMetricsServiceClient> Create(
      metrics::MetricsStateManager* state_manager);

  // Checks if the user has forced metrics collection on via the override flag.
  static bool IsMetricsReportingForceEnabled();

  // dummy implementation
  metrics::MetricsService* GetMetricsService() override { return nullptr; }
  void SetMetricsClientId(const std::string& client_id) override {}
  int32_t GetProduct() override { return 0; }
  std::string GetApplicationLocale() override { return ""; }
  bool GetBrand(std::string* brand_code) override { return false; }
  metrics::SystemProfileProto::Channel GetChannel() override {
    return metrics::SystemProfileProto::CHANNEL_UNKNOWN;
  }
  std::string GetVersionString() override { return ""; }
  void InitializeSystemProfileMetrics(
      const base::Closure& done_callback) override { done_callback.Run(); }
  void CollectFinalMetricsForLog(const base::Closure& done_callback) override {
    done_callback.Run();
  }
  std::unique_ptr<metrics::MetricsLogUploader> CreateUploader(
      base::StringPiece server_url,
      base::StringPiece mime_type,
      metrics::MetricsLogUploader::MetricServiceType service_type,
      const metrics::MetricsLogUploader::UploadCallback& on_upload_complete)
      override { return nullptr; }
  base::TimeDelta GetStandardUploadInterval() override {
    return base::TimeDelta::Max();
  }
 private:
  explicit ChromeMetricsServiceClient(
      metrics::MetricsStateManager* state_manager);
  void Initialize();
  // Registers |this| as an observer for notifications which indicate that a
  // user is performing work. This is useful to allow some features to sleep,
  // until the machine becomes active, such as precluding UMA uploads unless
  // there was recent activity.
  void RegisterForNotifications();

  // content::NotificationObserver:
  void Observe(int type,
               const content::NotificationSource& source,
               const content::NotificationDetails& details) override;

  // Weak pointer to the MetricsStateManager.
  metrics::MetricsStateManager* metrics_state_manager_;

  std::unique_ptr<metrics::MetricsService> metrics_service_;

  content::NotificationRegistrar registrar_;

  DISALLOW_COPY_AND_ASSIGN(ChromeMetricsServiceClient);
};

#endif  // CHROME_BROWSER_METRICS_CHROME_METRICS_SERVICE_CLIENT_H_
