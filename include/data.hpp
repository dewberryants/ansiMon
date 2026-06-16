#pragma once

#include <vector>

class TileSet {
public:
	TileSet () {
		chars = std::vector<char>{};
	}

	TileSet(std::vector<char> characters) {
		chars = characters;
	}
		
	char get(short id) const;
private:
	std::vector<char> chars;
};

class MapDefinition {
public:
	TileSet tiles;
	std::vector<short> layout;

	char tileAt(short x, short y, short width) const;
};