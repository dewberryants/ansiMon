#pragma once

#include <vector>
#include <ftxui/component/component.hpp>
#include "data/data.hpp"
#include "game/entity.hpp"

namespace game {
	class Scene {
	public:
		ftxui::Component GetRenderer();
	};

	struct Map {
		data::MapDefinition def;
		std::vector<game::Entity> entities;
	};

	class PlayerController {
	public:
		void move(int x, int y);
	private:
		int x;
		int y;
	};

	class Overworld : public Scene {
	public:
		PlayerController controller;
	private:
		Map currentMap;
	};
} // namespace game