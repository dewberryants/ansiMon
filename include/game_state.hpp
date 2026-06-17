#pragma once

#include <ftxui/component/event.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include <vector>
#include <data.hpp>

struct Settings {
    bool musicEnabled = true;
    int volume = 80;
};

struct Item {
    int id;
};

struct Map {
    MapDefinition def;
};

class Inventory {
public:
    void AddItem(Item item) {
        using namespace ftxui;
        items.push_back(item);
        ScreenInteractive::Active()->Post(Event::Special("InventoryDisturbed"));
    }
    std::vector<Item> GetItems() {
        return items;
    }
private:
    std::vector<Item> items;
};

class Player {
public:
    Inventory inventory;
};

class World {
public:
    Map currentMap;
};

class GameState {
public:
    Settings settings;
    Player player;
};