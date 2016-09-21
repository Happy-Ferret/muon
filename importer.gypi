{
  'variables': {
    'importer_js_sources': [
      'lib/browser/api/importer.js',
    ],
    'importer_sources': [
      'atom/browser/api/atom_api_importer.cc',
      'atom/browser/api/atom_api_importer.h',
      'atom/browser/importer/profile_writer.cc',
      'atom/common/importer/chrome_importer_utils.cc',
      'atom/common/importer/chrome_importer_utils.h',
      'atom/common/importer/chrome_importer_utils_mac.mm',
      'atom/common/importer/chrome_importer_utils_linux.cc',
      'atom/common/importer/chrome_importer_utils_win.cc',
      'atom/common/importer/imported_cookie_entry.cc',
      'atom/common/importer/imported_cookie_entry.h',
      'atom/utility/importer/chrome_importer.cc',
      'atom/utility/importer/chrome_importer.h',
      'chromium_src/chrome/browser/importer/external_process_importer_client.cc',
      'chromium_src/chrome/browser/importer/external_process_importer_client.h',
      'chromium_src/chrome/browser/importer/external_process_importer_host.cc',
      'chromium_src/chrome/browser/importer/external_process_importer_host.h',
      'chromium_src/chrome/browser/importer/firefox_profile_lock.cc',
      'chromium_src/chrome/browser/importer/firefox_profile_lock.h',
      'chromium_src/chrome/browser/importer/firefox_profile_lock_posix.cc',
      'chromium_src/chrome/browser/importer/firefox_profile_lock_win.cc',
      'chromium_src/chrome/browser/importer/importer_list.cc',
      'chromium_src/chrome/browser/importer/importer_list.h',
      'chromium_src/chrome/browser/importer/importer_lock_dialog.h',
      'chromium_src/chrome/browser/importer/importer_progress_observer.h',
      'chromium_src/chrome/browser/importer/importer_uma.cc',
      'chromium_src/chrome/browser/importer/importer_uma.h',
      'chromium_src/chrome/browser/importer/in_process_importer_bridge.cc',
      'chromium_src/chrome/browser/importer/in_process_importer_bridge.h',
      'chromium_src/chrome/browser/importer/profile_writer.h',
      'chromium_src/chrome/common/common_param_traits_macros.h',
      'chromium_src/chrome/common/importer/edge_importer_utils_win.cc',
      'chromium_src/chrome/common/importer/edge_importer_utils_win.h',
      'chromium_src/chrome/common/importer/firefox_importer_utils.cc',
      'chromium_src/chrome/common/importer/firefox_importer_utils.h',
      'chromium_src/chrome/common/importer/firefox_importer_utils_linux.cc',
      'chromium_src/chrome/common/importer/firefox_importer_utils_mac.mm',
      'chromium_src/chrome/common/importer/firefox_importer_utils_win.cc',
      'chromium_src/chrome/common/importer/ie_importer_utils_win.cc',
      'chromium_src/chrome/common/importer/ie_importer_utils_win.h',
      'chromium_src/chrome/common/importer/imported_bookmark_entry.cc',
      'chromium_src/chrome/common/importer/imported_bookmark_entry.h',
      'chromium_src/chrome/common/importer/importer_autofill_form_data_entry.cc',
      'chromium_src/chrome/common/importer/importer_autofill_form_data_entry.h',
      'chromium_src/chrome/common/importer/importer_bridge.cc',
      'chromium_src/chrome/common/importer/importer_bridge.h',
      'chromium_src/chrome/common/importer/importer_data_types.cc',
      'chromium_src/chrome/common/importer/importer_data_types.h',
      'chromium_src/chrome/common/importer/importer_test_registry_overrider_win.cc',
      'chromium_src/chrome/common/importer/importer_test_registry_overrider_win.h',
      'chromium_src/chrome/common/importer/importer_types.h',
      'chromium_src/chrome/common/importer/importer_url_row.cc',
      'chromium_src/chrome/common/importer/importer_url_row.h',
      'chromium_src/chrome/common/importer/profile_import_process_messages.cc',
      'chromium_src/chrome/common/importer/profile_import_process_messages.h',
      'chromium_src/chrome/common/importer/profile_import_process_param_traits_macros.h',
      'chromium_src/chrome/common/importer/pstore_declarations.h',
      'chromium_src/chrome/common/importer/safari_importer_utils.h',
      'chromium_src/chrome/common/importer/safari_importer_utils.mm',
      'chromium_src/chrome/common/ini_parser.cc',
      'chromium_src/chrome/common/ini_parser.h',
      'chromium_src/chrome/utility/importer/bookmark_html_reader.cc',
      'chromium_src/chrome/utility/importer/bookmark_html_reader.h',
      'chromium_src/chrome/utility/importer/bookmarks_file_importer.cc',
      'chromium_src/chrome/utility/importer/bookmarks_file_importer.h',
      'chromium_src/chrome/utility/importer/edge_database_reader_win.cc',
      'chromium_src/chrome/utility/importer/edge_database_reader_win.h',
      'chromium_src/chrome/utility/importer/edge_importer_win.cc',
      'chromium_src/chrome/utility/importer/edge_importer_win.h',
      'chromium_src/chrome/utility/importer/external_process_importer_bridge.cc',
      'chromium_src/chrome/utility/importer/external_process_importer_bridge.h',
      'chromium_src/chrome/utility/importer/favicon_reencode.cc',
      'chromium_src/chrome/utility/importer/favicon_reencode.h',
      'chromium_src/chrome/utility/importer/firefox_importer.cc',
      'chromium_src/chrome/utility/importer/firefox_importer.h',
      'chromium_src/chrome/utility/importer/ie_importer_win.cc',
      'chromium_src/chrome/utility/importer/ie_importer_win.h',
      'chromium_src/chrome/utility/importer/importer.cc',
      'chromium_src/chrome/utility/importer/importer.h',
      'chromium_src/chrome/utility/importer/importer_creator.cc',
      'chromium_src/chrome/utility/importer/importer_creator.h',
      'chromium_src/chrome/utility/importer/nss_decryptor.cc',
      'chromium_src/chrome/utility/importer/nss_decryptor.h',
      'chromium_src/chrome/utility/importer/nss_decryptor_mac.h',
      'chromium_src/chrome/utility/importer/nss_decryptor_mac.mm',
      'chromium_src/chrome/utility/importer/nss_decryptor_win.cc',
      'chromium_src/chrome/utility/importer/nss_decryptor_win.h',
      'chromium_src/chrome/utility/importer/safari_importer.h',
      'chromium_src/chrome/utility/importer/safari_importer.mm',
      'chromium_src/chrome/utility/profile_import_handler.cc',
      'chromium_src/chrome/utility/profile_import_handler.h',
    ],
  },
  'conditions': [
    ['OS=="mac"', {
      'variables': {
        'importer_libraries': [
          '<(libchromiumcontent_dir)/libbookmarks_browser.a',
          '<(libchromiumcontent_dir)/libcomponent_metrics_proto.a',
          '<(libchromiumcontent_dir)/libfavicon_base.a',
          '<(libchromiumcontent_dir)/libgoogle_apis.a',
          '<(libchromiumcontent_dir)/libgoogle_core_browser.a',
          '<(libchromiumcontent_dir)/libhistory_core_browser.a',
          '<(libchromiumcontent_dir)/libquery_parser.a',
          '<(libchromiumcontent_dir)/liburl_formatter.a',
          # '<(libchromiumcontent_dir)/libsearch_engines.a',
        ],
        'importer_include_dir': [
          '<(libchromiumcontent_dir)/gen/components/strings',
        ],
      }
    }],
    ['OS=="linux"', {
      'variables': {
        'importer_sources': [
          'chromium_src/chrome/utility/importer/nss_decryptor_system_nss.cc',
          'chromium_src/chrome/utility/importer/nss_decryptor_system_nss.h',
        ],
        'importer_libraries': [
          '<(libchromiumcontent_dir)/libbookmarks_browser.a',
          '<(libchromiumcontent_dir)/libcomponent_metrics_proto.a',
          '<(libchromiumcontent_dir)/libfavicon_base.a',
          '<(libchromiumcontent_dir)/libgoogle_apis.a',
          '<(libchromiumcontent_dir)/libgoogle_core_browser.a',
          '<(libchromiumcontent_dir)/libhistory_core_browser.a',
          '<(libchromiumcontent_dir)/libquery_parser.a',
          '<(libchromiumcontent_dir)/liburl_formatter.a',
          # '<(libchromiumcontent_dir)/libsearch_engines.a',
        ],
        'importer_include_dir': [
          '<(libchromiumcontent_dir)/gen/components/strings',
          '/usr/local/include/nss',
          '/usr/local/include/nspr',
        ],
      }
    }],
    ['OS=="win"', {
      'variables': {
        'importer_libraries': [
          '<(libchromiumcontent_dir)/bookmarks_browser.lib',
          '<(libchromiumcontent_dir)/component_metrics_proto.lib',
          '<(libchromiumcontent_dir)/favicon_base.lib',
          '<(libchromiumcontent_dir)/google_apis.lib',
          '<(libchromiumcontent_dir)/google_core_browser.lib',
          '<(libchromiumcontent_dir)/history_core_browser.lib',
          '<(libchromiumcontent_dir)/query_parser.lib',
          '<(libchromiumcontent_dir)/url_formatter.lib',
          # '<(libchromiumcontent_dir)/search_engines.lib',
          '-lesent.lib',
        ],
        'importer_include_dir': [
          '<(libchromiumcontent_dir)/gen/components/strings',
        ],
      },
    }],
  ],
  'target_defaults': {
    'defines': [
      'GOOGLE_PROTOBUF_NO_RTTI'
    ],
  },
}