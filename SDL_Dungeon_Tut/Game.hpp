#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "SDL_Deleter.cpp"
using std::unique_ptr;

class Game
{
public:
	Game();
	~Game();

	void init(const char *title, int x_pos, int y_pos, int width, int height, bool is_fullscreen);
	
	void handle_events();
	void update();
	void render();
	void clean();

	bool is_running() { return _is_running; }

private:
	int _counter = 0;
	bool _is_running;
	unique_ptr<SDL_Window, SDL_Deleter> _window;
	unique_ptr<SDL_Renderer, SDL_Deleter> _renderer;
	unique_ptr<SDL_Texture, SDL_Deleter> _player_texture;
	SDL_Rect source_rect;
	SDL_Rect destination_rect;
};

