#include <gtest/gtest.h>
#include <vector>

#include "data.hpp"

TEST(TestMapDefinition, LoadsCorrectTile) {
    MapDefinition map;
    TileSet tiles{ std::vector<char>{'A', 'B', 'C'} };

    map.tiles = tiles;
    map.layout = { 0, 1, 2 };

    EXPECT_EQ(map.tileAt(0, 0, 3), 'A');
    EXPECT_EQ(map.tileAt(1, 0, 3), 'B');
    EXPECT_EQ(map.tileAt(2, 0, 3), 'C');
}