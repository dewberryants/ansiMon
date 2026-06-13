#include "ui.hpp"
#include "game_state.hpp"

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
                filler(),
                music_cb->Render() | center,
                volume_sl->Render() | size(WIDTH, EQUAL, 32) | center,
                filler()
                }) | flex;
            }) | size(WIDTH, EQUAL, 64) | center;
    }

    ftxui::Component MakeInventoryTab(Inventory& inventory) {
        using namespace ftxui;

        return Renderer([&inventory] {
            std::string editContent = "...";

            auto container = Container::Vertical({});

            auto style = ButtonOption::Animated(Color::Default, Color::GrayDark, Color::Default, Color::White);

            for (auto const& item : inventory.items) {
                auto button = Button(std::to_string(item.id), [&item, &editContent] {editContent = std::to_string(item.id);}, style);
                container->Add(button);
            }

            return hbox({ container->Render() | border,
                    text(editContent) | border
                });
            });
    }
} // namespace game