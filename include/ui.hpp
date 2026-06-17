#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <game_state.hpp>

namespace game {
    class InventoryUI {
    public:
        InventoryUI::InventoryUI(Inventory& inv) : inventory(inv), currentSelection(0), container(ftxui::Container::Vertical({})) {
            RebuildInternals();
        }
        ftxui::Component GetRenderer();
        void RebuildInternals();
        int GetInventorySize();
    private:
        ftxui::Component container;
        std::string currentDescription;
        int currentSelection = 0;
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
