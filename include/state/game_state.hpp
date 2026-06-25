#pragma once

#include <vector>

#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <iostream>

#include "game/scene.hpp"
#include "game/entity.hpp"

namespace state {
    struct Settings {
        bool musicEnabled = true;
        int volume = 80;
    };

    class Inventory {
    public:
        void AddItem(game::Item item) {
            using namespace ftxui;
            items.push_back(item);
            if (ScreenInteractive::Active())
                ScreenInteractive::Active()->Post(Event::Special("InventoryDisturbed"));
        }
        std::vector<game::Item> GetItems() {
            return items;
        }
    private:
        std::vector<game::Item> items;
    };

    class Player {
    public:
        Inventory inventory;
        std::vector<game::Creature> team;
    };

    class World {
    public:
        std::unique_ptr<game::Scene> currentScene = std::make_unique<game::Overworld>(90, 22);
    };

    class GameState {
    public:
        Settings settings;
        Player player;
        World world;
    };
} // namespace state