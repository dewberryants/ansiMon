#include "data.hpp"

char TileSet::get(short id) const {
	return chars[id];
}


char MapDefinition::tileAt(short x, short y, short width) const {
	return tiles.get(layout[y * width + x]);

};