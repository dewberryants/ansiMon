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