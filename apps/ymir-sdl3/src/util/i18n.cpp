#include <util/i18n.hpp>

#include <nlohmann/json.hpp>

#include <fstream>


namespace i18n {

std::unique_ptr<i18n> i18n::instance = nullptr;
std::mutex i18n::_mtx;

void i18n::LoadLocale(std::string_view locale) {
    std::ifstream fileStream(fmt::format("locales/{}.json", locale));
    nlohmann::json jsonData = nlohmann::json::parse(fileStream);

    localeDict["welcomeTitle"] = jsonData["welcomeTitle"];
    localeDict["welcomeMessage"] = jsonData["welcomeMessage"];
    localeDict["welcomeRequiresIPL"] = jsonData["welcomeRequiresIPL"];
    localeDict["welcomeAutomaticIPLLoad"] = jsonData["welcomeAutomaticIPLLoad"];
    localeDict["welcomeAltIPL"] = jsonData["welcomeAltIPL"];
    localeDict["welcomeManualIPLSelect"] = jsonData["welcomeManualIPLSelect"];
    localeDict["welcomeOrIPL"] = jsonData["welcomeOrIPL"];
    localeDict["welcomeManageROMSettings"] = jsonData["welcomeManageROMSettings"];
    localeDict["welcomeNotScanning"] = jsonData["welcomeNotScanning"];
    localeDict["welcomeScanInstructions"] = jsonData["welcomeScanInstructions"];
    localeDict["welcomeStartScan"] = jsonData["welcomeStartScan"];
    localeDict["welcomeBadIPLROM"] = jsonData["welcomeBadIPLROM"];
    localeDict["welcomeBadIPLROMReason"] = jsonData["welcomeBadIPLROMReason"];
    localeDict["welcomeOpenIPLROMDir"] = jsonData["welcomeOpenIPLROMDir"];
    localeDict["welcomeSelectIPLROM"] = jsonData["welcomeSelectIPLROM"];
    localeDict["welcomeOpenIPLSettings"] = jsonData["welcomeOpenIPLSettings"];
    localeDict["welcomeSelectIPLROMDialog"] = jsonData["welcomeSelectIPLROMDialog"];

    localeDict["menuFile"] = jsonData["menuFile"];
    localeDict["menuFileLoadDiscImage"] = jsonData["menuFileLoadDiscImage"];
    localeDict["menuFileToggleTray"] = jsonData["menuFileToggleTray"];
    localeDict["menuFileEjectDisc"] = jsonData["menuFileEjectDisc"];
    localeDict["menuFileOpenProfileDir"] = jsonData["menuFileOpenProfileDir"];
    localeDict["menuFileOpenSaveStatesDir"] = jsonData["menuFileOpenSaveStatesDir"];
    localeDict["menuFileBackupMemManager"] = jsonData["menuFileBackupMemManager"];
    localeDict["menuFileExit"] = jsonData["menuFileExit"];

    localeDict["menuView"] = jsonData["menuView"];
    localeDict["menuViewIntegerScaling"] = jsonData["menuViewIntegerScaling"];
    localeDict["menuViewAspectRatio"] = jsonData["menuViewAspectRatio"];
    localeDict["menuViewFullScreen"] = jsonData["menuViewFullScreen"];
    localeDict["menuViewAutoFitWindow"] = jsonData["menuViewAutoFitWindow"];
    localeDict["menuViewFitWindow"] = jsonData["menuViewFitWindow"];
    localeDict["menuViewWindowedOutput"] = jsonData["menuViewWindowedOutput"];

    localeDict["menuSystem"] = jsonData["menuSystem"];
    localeDict["menuSystemState"] = jsonData["menuSystemState"];
    localeDict["menuSystemSoftReset"] = jsonData["menuSystemSoftReset"];
    localeDict["menuSystemHardReset"] = jsonData["menuSystemHardReset"];
    localeDict["menuSystemLocale"] = jsonData["menuSystemLocale"];
    localeDict["menuSystemLocaleTip"] = jsonData["menuSystemLocaleTip"];
    localeDict["menuSystemVideoStandard"] = jsonData["menuSystemVideoStandard"];
    localeDict["menuSystemRegion"] = jsonData["menuSystemRegion"];
    localeDict["menuSystemRegionTip"] = jsonData["menuSystemRegionTip"];
    localeDict["menuSystemCartPort"] = jsonData["menuSystemCartPort"];
    localeDict["menuSystemInsertBackupRAM"] = jsonData["menuSystemInsertBackupRAM"];
    localeDict["menuSystemInsert8BitDRAM"] = jsonData["menuSystemInsert8BitDRAM"];
    localeDict["menuSystemInsert32BitDRAM"] = jsonData["menuSystemInsert32BitDRAM"];
    localeDict["menuSystemInsert16BitROM"] = jsonData["menuSystemInsert16BitROM"];
    localeDict["menuSystemRemoveCart"] = jsonData["menuSystemRemoveCart"];

    localeDict["menuEmulation"] = jsonData["menuEmulation"];
    localeDict["menuEmulationPauseResume"] = jsonData["menuEmulationPauseResume"];
    localeDict["menuEmulationForwardFrame"] = jsonData["menuEmulationForwardFrame"];
    localeDict["menuEmulationReverseFrame"] = jsonData["menuEmulationReverseFrame"];
    localeDict["menuEmulationRewindBuffer"] = jsonData["menuEmulationRewindBuffer"];

    localeDict["menuSettings"] = jsonData["menuSettings"];
    localeDict["menuSettingsGeneral"] = jsonData["menuSettingsGeneral"];
    localeDict["menuSettingsHotkeys"] = jsonData["menuSettingsHotkeys"];
    localeDict["menuSettingsSystem"] = jsonData["menuSettingsSystem"];
    localeDict["menuSettingsInput"] = jsonData["menuSettingsInput"];
    localeDict["menuSettingsVideo"] = jsonData["menuSettingsVideo"];
    localeDict["menuSettingsAudio"] = jsonData["menuSettingsAudio"];
    localeDict["menuSettingsCart"] = jsonData["menuSettingsCart"];
    localeDict["menuSettingsCDBlock"] = jsonData["menuSettingsCDBlock"];

    localeDict["menuDebug"] = jsonData["menuDebug"];
    localeDict["menuDebugEnableTracing"] = jsonData["menuDebugEnableTracing"];
    localeDict["menuDebugOpenMemViewer"] = jsonData["menuDebugOpenMemViewer"];

    localeDict["menuMemViewers"] = jsonData["menuMemViewers"];
    localeDict["menuMemViewersIter"] = jsonData["menuMemViewersIter"];

    localeDict["menuDumpMem"] = jsonData["menuDumpMem"];

    localeDict["menuHostSH"] = jsonData["menuHostSH"];
    localeDict["menuWorkerSH"] = jsonData["menuWorkerSH"];

    localeDict["menuSHMenuDebugger"] = jsonData["menuSHMenuDebugger"];
    localeDict["menuSHMenuInterrupts"] = jsonData["menuSHMenuInterrupts"];
    localeDict["menuSHMenuInterruptTrace"] = jsonData["menuSHMenuInterruptTrace"];
    localeDict["menuSHMenuCache"] = jsonData["menuSHMenuCache"];
    localeDict["menuSHMenuDivUnit"] = jsonData["menuSHMenuDivUnit"];
    localeDict["menuSHMenuTimer"] = jsonData["menuSHMenuTimer"];
    localeDict["menuSHMenuDMA"] = jsonData["menuSHMenuDMA"];
    localeDict["menuSHMenuDMATrace"] = jsonData["menuSHMenuDMATrace"];

    localeDict["menuSCURegisters"] = jsonData["menuSCURegisters"];
    localeDict["menuSCUDMATrace"] = jsonData["menuSCUDMATrace"];
    localeDict["menuSCUInterruptTrace"] = jsonData["menuSCUInterruptTrace"];

    localeDict["menuVDPLayers"] = jsonData["menuVDPLayers"];
    localeDict["menuVDPSprite"] = jsonData["menuVDPSprite"];

    localeDict["menuVDPDebugOutput"] = jsonData["menuVDPDebugOutput"];

    localeDict["menuHelp"] = jsonData["menuHelp"];
    localeDict["menuHelpOpenWelcomeWin"] = jsonData["menuHelpOpenWelcomeWin"];
    localeDict["menuHelpImGuiWin"] = jsonData["menuHelpImGuiWin"];
    localeDict["menuHelpAbout"] = jsonData["menuHelpAbout"];
}

std::string_view i18n::LocaleToString(ymir::core::config::sys::Locale locale) {
    switch (locale) {
        case ymir::core::config::sys::Locale::en: return "en";
        case ymir::core::config::sys::Locale::pt: return "pt";
        default: return "en";
    }
}

std::vector<ymir::core::config::sys::Locale> i18n::GetAvailableLocales() {
    return availableLocales;
}

std::string_view i18n::GetCurrentLocaleAsString() {
    return LocaleToString(currentLocale);
}

ymir::core::config::sys::Locale i18n::GetCurrentLocale() {
    return currentLocale;
}

void i18n::SetLocale(ymir::core::config::sys::Locale locale) {
    currentLocale = locale;
    LoadLocale(LocaleToString(locale));
}

std::string_view i18n::GetPhrase(std::string_view keyword) {
    if (localeDict.find(keyword) == localeDict.end())
        return "i18n phrase not found";

    return localeDict[keyword];
}


} // namespace i18n