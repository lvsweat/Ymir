#include "system_widgets.hpp"

#include <app/events/emu_event_factory.hpp>

#include <util/regions.hpp>
#include <util/i18n.hpp>

#include <imgui.h>

using namespace ymir;

namespace app::ui::widgets {

bool VideoStandardSelector(SharedContext &ctx) {
    bool changed = false;
    core::config::sys::VideoStandard videoStandard = ctx.saturn.GetVideoStandard();
    if (ImGui::RadioButton("NTSC", videoStandard == core::config::sys::VideoStandard::NTSC)) {
        ctx.EnqueueEvent(events::emu::SetVideoStandard(core::config::sys::VideoStandard::NTSC));
        changed = true;
    }
    ImGui::SameLine();
    if (ImGui::RadioButton("PAL", videoStandard == core::config::sys::VideoStandard::PAL)) {
        ctx.EnqueueEvent(events::emu::SetVideoStandard(core::config::sys::VideoStandard::PAL));
        changed = true;
    }
    return changed;
}

bool RegionSelector(SharedContext &ctx) {
    bool changed = false;
    auto areaCode = static_cast<core::config::sys::Region>(ctx.saturn.SMPC.GetAreaCode());
    if (ImGui::BeginCombo("##region", util::RegionToString(areaCode).c_str(),
                          ImGuiComboFlags_WidthFitPreview | ImGuiComboFlags_HeightLargest)) {
        for (auto rgn : {core::config::sys::Region::Japan, core::config::sys::Region::NorthAmerica,
                         core::config::sys::Region::AsiaNTSC, core::config::sys::Region::EuropePAL}) {
            if (ImGui::Selectable(util::RegionToString(rgn).c_str(), rgn == areaCode) && rgn != areaCode) {
                ctx.EnqueueEvent(events::emu::SetAreaCode(static_cast<uint8>(rgn)));
                // TODO: optional?
                ctx.EnqueueEvent(events::emu::HardReset());
                changed = true;
            }
        }

        ImGui::EndCombo();
    }
    return changed;
}

bool LocaleSelector(SharedContext &ctx) {
    bool changed = false;
    i18n::i18n& i18nInstance = i18n::i18n::GetInstance();
    auto currentLocale = ctx.saturn.GetLocale();
    if (ImGui::BeginCombo("##locale", i18n::i18n::LocaleToString(currentLocale).data(),
                          ImGuiComboFlags_WidthFitPreview | ImGuiComboFlags_HeightLargest)) {
        for (core::config::sys::Locale locale : i18nInstance.GetAvailableLocales()) {
            if (ImGui::Selectable(i18n::i18n::LocaleToString(locale).data(), locale == currentLocale) && locale != currentLocale) {
                ctx.EnqueueEvent(events::emu::SetLocale(locale));
                changed = true;
            }
        }

        ImGui::EndCombo();
    }
    return changed;
}

} // namespace app::ui::widgets
