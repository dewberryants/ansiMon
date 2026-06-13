#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>
#include <game_state.hpp>

namespace game {
    ftxui::Component MakeSettingsTab(bool& musicEnabled, int& volume);
    ftxui::Component MakeInventoryTab(Inventory& inventory);
} // namespace game
