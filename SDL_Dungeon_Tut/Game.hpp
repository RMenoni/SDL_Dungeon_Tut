#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include "SDL_Ptr.cpp"
#include "TextureManager.h"
#include "GameObject.hpp"
#include "GameMap.hpp"

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


private:
	const std::string PLAYER_IMG_FILENAME = "assets/main_char.png";
	const std::string ENEMY_IMG_FILENAME =  "assets/enemy.png";
	int _counter = 0;
	bool _is_running;
	uptr<SDL_Window> _window;
	std::shared_ptr<TextureManager> _texture_manager;
	std::unique_ptr<GameMap> _game_map;
	std::unique_ptr<GameObject> _player;
	std::unique_ptr<GameObject> _enemy;
};

