#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <game_state.hpp>

namespace game {
    class InventoryUI {
    public:
        InventoryUI::InventoryUI(Inventory& inv) : inventory(inv), currentSelection(0), InventoryDisturbed(true), container(ftxui::Container::Vertical({})) {};
        ftxui::Component GetRenderer();
        void RebuildInternals();
        int GetInventorySize();
    private:
        ftxui::Component container;
        std::string currentDescription;
        int currentSelection = 0;
        bool InventoryDisturbed = false;
        ftxui::ButtonOption style = ftxui::ButtonOption::Animated(ftxui::Color::Default, ftxui::Color::GrayDark, ftxui::Color::Default, ftxui::Color::White);
        Inventory& inventory;
    };

    class UIHandler {
    public:
        InventoryUI inventory = InventoryUI(state.player.inventory);
    private:
        GameState state;
    };

    ftxui::Component MakeSettingsTab(bool& musicEnabled, int& volume);
    ftxui::Component MakeInventoryTab(Inventory& inventory);
    ftxui::Component GameCanvas(GameState& state);
} // namespace game
