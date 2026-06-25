#include <iostream>

#include "ui/ui.hpp"
#include "state/game_state.hpp"


namespace UI {

    ftxui::ButtonOption InventoryItemStyle() {
        using namespace ftxui;
        ButtonOption style = ftxui::ButtonOption::Animated(ftxui::Color::Default, ftxui::Color::GrayDark, ftxui::Color::Default, ftxui::Color::White);
        style.transform = [](const EntryState& s) {
            auto element = text(s.label);
            if (s.focused) {
                element |= bold;
            }
            return element | size(HEIGHT, EQUAL, 1);
            };
        return style;
    }

    ftxui::Component InventoryUI::GetRenderer() {
        using namespace ftxui;
        return Renderer(container, [&] {
            return hbox({ container->Render() | vscroll_indicator | frame | border | size(WIDTH, EQUAL, 45),
                    text(currentDescription) | vscroll_indicator | frame | border | size(WIDTH, EQUAL, 45)
                });
            }) | CatchEvent([&](Event event) {
                if (event == Event::Special("InventoryDisturbed")) {
                    std::cerr << "BOO!";
                    RebuildInternals();
                    return true;
                }
                return false;
                });
    }

    void InventoryUI::RebuildInternals() {
        using namespace ftxui;
        int c = 0;
        container->DetachAllChildren();
        auto btn = Button("Add Dummy", [&] {inventory.AddItem(game::Item()); std::cerr << "shwoop!";}, ButtonOption::Simple());
        container->Add(btn);

        for (auto const& item : inventory.GetItems()) {
            auto button = Button(std::to_string(c), [&] {
                    currentDescription = std::to_string(c);
                    currentSelection = c;
                }, InventoryItemStyle());
            container->Add(button);
            c++;
        }
    }

    int InventoryUI::GetInventorySize() {
        return inventory.GetItems().size();
    }

    ftxui::Component SettingsUI::GetRenderer() {
        using namespace ftxui;
        auto volume_sl = Slider("Volume:", &settings.volume, 0, 100, 1);
        auto music_cb = Checkbox("Music", &settings.musicEnabled);
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

    ftxui::Component CreaturesUI::GetRenderer() {
        using namespace ftxui;
        return Renderer([] {
            return text("Creatures...");
            });
    }
} // namespace UI