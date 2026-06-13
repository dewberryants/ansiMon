#pragma once

#include <vector>

struct Settings {
    bool musicEnabled = true;
    int volume = 80;
};

struct Item {
    int id;
};

class Inventory {
public:
    std::vector<Item> items;
};

class Player {
public:
    Inventory inventory;
};

class GameState {
public:
    Settings settings;
    Player player;
};