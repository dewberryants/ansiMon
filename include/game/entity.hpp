#pragma once

#include <vector>

namespace game {
	struct Item {
		int id;
	};

	enum SpriteType {
		OVERWORLD,
		BATTLE
	};

	class Sprite {
	public:
		std::vector<char> GetCharacters();
		int GetHeight();
		int GetWidth();
	private:
		std::vector<char> chars;
		int height;
		int width;
	};

	class Entity {
	public:
		Sprite GetSprite(SpriteType type);
	};

	class Creature : public Entity {
	private:
		int SpeciesId;
	};
} // namespace game