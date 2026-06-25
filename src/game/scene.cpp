#include "game/scene.hpp"

using namespace game;

ftxui::Component Overworld::GetRenderer() {
	Redraw();
	return ftxui::Renderer([=] {
		return ftxui::canvas(canvas.get());
		});
}

void Overworld::Redraw() {

	canvas.get()->DrawBlock();
}