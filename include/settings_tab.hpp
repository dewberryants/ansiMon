#pragma once

#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

namespace game {
    ftxui::Component MakeSettingsTab(bool& musicEnabled, int& volume);
} // namespace game
