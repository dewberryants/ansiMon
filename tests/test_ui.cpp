#include <gtest/gtest.h>

#include "ui/ui.hpp"

using namespace UI;


TEST(TestUISetup, InitSuccessful) {
    EXPECT_NO_THROW([]{
        UIHandler handler;
    });
}

TEST(TestInventoryUI, AddItems) {
    using namespace state;
    Inventory MockInventory;
    InventoryUI ui = InventoryUI(MockInventory);

    for (int i = 0; i < 10; i++)
        MockInventory.AddItem(game::Item());

    EXPECT_EQ(10, ui.GetInventorySize());
}