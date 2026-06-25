#include <gtest/gtest.h>
#include <vector>

#include "state/game_state.hpp"
#include "game/scene.hpp"
#include "game/entity.hpp"

TEST(TestGame, TestLogicStackInit) {
	ASSERT_NO_THROW([] {
		state::GameState state;
		});
}

TEST(TestOverworld, TestInit) {
	ASSERT_NO_THROW([] {
		game::Overworld overworldScene;
		});
}

TEST(TestOverworld, TestMove) {
	game::Overworld overworldScene;
	overworldScene.controller.move(10, 5);
	ASSERT_EQ(overworldScene.controller.x, 10);
	ASSERT_EQ(overworldScene.controller.y, 5);
}