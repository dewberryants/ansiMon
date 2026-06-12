#include "settings_tab.hpp"

namespace game {
    ftxui::Component MakeSettingsTab(bool& musicEnabled, int& volume) {
        using namespace ftxui;

        auto volume_sl = Slider("Volume:", volume, 0, 100, 1);
        auto music_cb = Checkbox("Music", &musicEnabled);

        auto container = Container::Vertical({
            music_cb,
            volume_sl
            });

        return Renderer(container, [music_cb, volume_sl] {
            return vbox({
                text("Settings") | bold | center,
                filler(),
                music_cb->Render() | center,
                volume_sl->Render() | size(WIDTH, EQUAL, 32) | center,
                filler()
                }) | flex;
            }) | size(WIDTH, EQUAL, 64) | center;
    }
} // namespace game
