#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "SDL_Ptr.cpp"
#include "TextureManager.h"
#include "GameObject.hpp"

class Game
{
public:
	Game();
	~Game();

	void init(const std::string &title, int x_pos, int y_pos, int width, int height, bool is_fullscreen);
	void handle_events();
	void update();
	void render();
	void clean();
	bool is_running() { return _is_running; }

	static uptr<SDL_Renderer> renderer;


private:
	const std::string PLAYER_IMG_FILENAME = "main_char.png";
	const std::string ENEMY_IMG_FILENAME = "enemy.png";
	int _counter = 0;
	bool _is_running;
	uptr<SDL_Window> _window;
	std::unique_ptr<GameObject> _player;
	std::unique_ptr<GameObject> _enemy;
};

