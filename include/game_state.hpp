#pragma once

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
    std::vector<Item> items;
    std::string currentDescription = "Hi!";
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