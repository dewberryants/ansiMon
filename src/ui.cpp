#include <iostream>

#include "ui.hpp"
#include "game_state.hpp"


namespace game {

    ftxui::ButtonOption InventoryItemStyle() {
        using namespace ftxui;
        ButtonOption style = ftxui::ButtonOption::Animated(ftxui::Color::Default, ftxui::Color::GrayDark, ftxui::Color::Default, ftxui::Color::White);
        style.transform = [](const EntryState& s) {
            auto element = text(s.label);
            if (s.focused) {
                element |= bold;
            }
            return element | center | borderEmpty | size(HEIGHT, EQUAL, 3);
            };
        return style;
    }

    ftxui::Component InventoryUI::GetRenderer() {
        using namespace ftxui;
        return Renderer(container, [&] {
            return hbox({ container->Render() | border | size(WIDTH, EQUAL, 45) | vscroll_indicator,
                    text(currentDescription) | border | size(WIDTH, EQUAL, 45)
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
        auto btn = Button("Add Dummy", [&] {inventory.AddItem(Item()); std::cerr << "shwoop!";}, ButtonOption::Simple());
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

            for (auto const& item : inventory.GetItems()) {
                auto button = Button(std::to_string(item.id), [&item, &editContent] {editContent = std::to_string(item.id);}, style);
                container->Add(button);
            }

            return hbox({ container->Render() | border | size(WIDTH, EQUAL, 45),
                    text(editContent) | border | size(WIDTH, EQUAL, 45)
                });
            });
    }

    ftxui::Component GameCanvas(GameState& state) {
        using namespace ftxui;
        return Renderer([] {
            Canvas c = Canvas(90, 22);
            c.DrawText(0, 0, "This is the game renderer!");
            return canvas(std::move(c));
            });
    }
} // namespace game