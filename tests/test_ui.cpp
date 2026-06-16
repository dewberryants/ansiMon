#include <gtest/gtest.h>

#include "ui.hpp"

using namespace game;

TEST(TestUISetup, InitSuccessful) {
    EXPECT_NO_THROW([]{
        UIHandler handler;
    });
}

TEST(TestUISetup, AddItems) {
    Inventory MockInventory;
    InventoryUI ui = InventoryUI(MockInventory);

    for (int i = 0; i < 10; i++)
        MockInventory.items.push_back(Item());

    EXPECT_EQ(10, ui.GetInventorySize());
}