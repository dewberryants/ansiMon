#include <iostream>

#include "ui.hpp"
#include "game_state.hpp"


namespace game {

    ftxui::Component InventoryUI::GetRenderer() {
        using namespace ftxui;
        if (InventoryDisturbed) {
            auto btn = Button("Add Dummy", [&] {inventory.items.push_back(Item()); InventoryDisturbed = true; std::cerr << "shwoop!";}, ButtonOption::Simple());
            RebuildInternals();
            container->Add(btn);
        }

        return Renderer(container, [&] {
            return hbox({ container->Render() | border | size(WIDTH, EQUAL, 45),
                    text(currentDescription) | border | size(WIDTH, EQUAL, 45)
                });
            });
    }

    void InventoryUI::RebuildInternals() {
        int c = 0;
        container->DetachAllChildren();
        for (auto const& item : inventory.items) {
            auto button = Button(std::to_string(item.id), [&] {
                    currentDescription = std::to_string(item.id);
                    currentSelection = c;
                }, style);
            container->Add(button);
            c++;
        }
    }

    int InventoryUI::GetInventorySize() {
        return inventory.items.size();
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

            for (auto const& item : inventory.items) {
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