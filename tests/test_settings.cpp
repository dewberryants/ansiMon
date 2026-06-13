#include <iostream>
#include "game_state.hpp"

int main() {
	Settings testSettings;
	if (!testSettings.musicEnabled ||
		testSettings.volume != 80) {
		std::cerr << "Default values in Settings have changed!";
		return 1;
	}
	return 0;
}