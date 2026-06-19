#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <state/game_state.hpp>

namespace UI {

    class InventoryUI {
    public:
        InventoryUI(state::Inventory& inv) : inventory(inv), currentSelection(0), container(ftxui::Container::Vertical({})) {
            RebuildInternals();
        }
        ftxui::Component GetRenderer();
        void RebuildInternals();
        int GetInventorySize();
    private:
        ftxui::Component container;
        std::string currentDescription;
        int currentSelection = 0;
        state::Inventory& inventory;
    };

    class SettingsUI {
    public:
        SettingsUI(state::Settings& gameSettings) : settings(gameSettings) {}
        ftxui::Component GetRenderer();
    private:
        state::Settings& settings;
    };

    class CreaturesUI {
    public:
        CreaturesUI(std::vector<game::Creature>& creatures) : team(creatures) {}
        ftxui::Component GetRenderer();
    private:
        std::vector<game::Creature>& team;
    };

    class UIHandler {
    public:
        InventoryUI inventory = InventoryUI(state.player.inventory);
        SettingsUI settings = SettingsUI(state.settings);
        CreaturesUI creatures = CreaturesUI(state.player.team);
    private:
        state::GameState state;
    };

    ftxui::Component GameCanvas(state::GameState& state);
} // namespace UI
