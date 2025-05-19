#pragma once

#include <mutex>
#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

#include <fmt/std.h>

#include <ymir/core/configuration_defs.hpp>
#include <app/events/emu_event_factory.hpp>


namespace i18n {

	class i18n {
	public:
        static std::string_view LocaleToString(ymir::core::config::sys::Locale locale);

        static i18n& GetInstance() {
            std::lock_guard<std::mutex> lock(_mtx);
			if (!instance)
			{
                instance.reset(new i18n());
			}
            return *instance;
		}

        std::vector<ymir::core::config::sys::Locale> GetAvailableLocales();
        ymir::core::config::sys::Locale GetCurrentLocale();
        std::string_view GetCurrentLocaleAsString();
        void SetLocale(ymir::core::config::sys::Locale locale);
        std::string_view GetPhrase(std::string_view keyword);


	private:
        i18n() {
            SetLocale(ymir::core::config::sys::Locale::en);
        }
        i18n(const i18n&) = delete;
        i18n& operator=(const i18n&) = delete;

        static std::unique_ptr<i18n> instance;
        static std::mutex _mtx;

        std::unordered_map<std::string_view, std::string> localeDict = {};
        ymir::core::config::sys::Locale currentLocale = ymir::core::config::sys::Locale::en;
        std::vector<ymir::core::config::sys::Locale> availableLocales = {ymir::core::config::sys::Locale::en,
                                                                         ymir::core::config::sys::Locale::pt};

        void LoadLocale(std::string_view locale);
	};

} // namespace i18n