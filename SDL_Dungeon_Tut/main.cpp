#include <iostream>
#include <memory>
#include "SDL.h"
#include "Game.hpp"

const int FRAMES_PER_SECOND = 60;
const int FRAME_DELAY = 1000 / FRAMES_PER_SECOND;

int main(int argc, char** argv) {
	Game game;
	Uint32 frame_start;
	int frame_time;

	game.init("Tutorial Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game.is_running()) {
		frame_start = SDL_GetTicks();

		game.handle_events();
		game.update();
		game.render();

		frame_time = SDL_GetTicks() - frame_start;

		if (FRAME_DELAY > frame_time) {
			SDL_Delay(FRAME_DELAY - frame_time);
		}
	}

	game.clean();

	return 0;
}