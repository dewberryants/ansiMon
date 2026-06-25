#pragma once

#include <vector>
#include <ftxui/component/component.hpp>
#include "data/data.hpp"
#include "game/entity.hpp"

namespace game {
	class Scene {
	public:
		virtual ftxui::Component GetRenderer() = 0;
	};

	struct Map {
		data::MapDefinition def;
		std::vector<game::Entity> entities;
	};

	class PlayerController {
	public:
		void move(int dx, int dy) {
			x = x + dx;
			y = y + dy;
		}
		int x = 0;
		int y = 0;
	};

	class Overworld : public Scene {
	public:
		Overworld(size_t worldWdith, size_t worldHeight) : canvas(std::make_unique<ftxui::Canvas>(worldWdith, worldHeight)) {
			canvas.get()->DrawText(0, 0, "Hello WOrld!");
		}
		ftxui::Component GetRenderer();
		PlayerController controller;
		ftxui::Image bg;
	private:
		void Redraw();
		Map currentMap;
		std::unique_ptr<ftxui::Canvas> canvas;
	};
} // namespace game