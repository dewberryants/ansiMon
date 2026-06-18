#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <game_state.hpp>

namespace UI {
    class InventoryUI {
    public:
        InventoryUI(Inventory& inv) : inventory(inv), currentSelection(0), container(ftxui::Container::Vertical({})) {
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

    class SettingsUI {
    public:
        SettingsUI(Settings& gameSettings) : settings(gameSettings) {}
        ftxui::Component GetRenderer();
    private:
        Settings& settings;
    };

    class CreaturesUI {
    public:
        CreaturesUI(std::vector<Creature>& creatures) : team(creatures) {}
        ftxui::Component GetRenderer();
    private:
        std::vector<Creature>& team;
    };

    class UIHandler {
    public:
        InventoryUI inventory = InventoryUI(state.player.inventory);
        SettingsUI settings = SettingsUI(state.settings);
        CreaturesUI creatures = CreaturesUI(state.player.team);
    private:
        GameState state;
    };

    ftxui::Component GameCanvas(GameState& state);
} // namespace UI
