#include "Game.hpp"

uptr<SDL_Renderer> Game::renderer = nullptr;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const std::string &title, int x_pos, int y_pos, int width, int height, bool is_fullscreen) {
	int flags = is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!" << std::endl;
		_window.reset(SDL_CreateWindow(title.c_str(), x_pos, y_pos, width, height, flags));
		if (_window.get() != NULL) {
			std::cout << "Window created!" << std::endl;
		}
		renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0));
		if (renderer.get() != NULL) {
			SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		_is_running = true;
	}
	else {
		std::cout << "Could not initialize SDL!" << std::endl;
		_is_running = false;
	}

	_player = std::make_unique<GameObject>(PLAYER_IMG_FILENAME, 0, 0);
	_enemy = std::make_unique<GameObject>(ENEMY_IMG_FILENAME, 50, 50);
}

void Game::update() {
	_player->update();
	_enemy->update();
}

void Game::render() {
	SDL_RenderClear(renderer.get());
	_player->render();
	_enemy->render();
	SDL_RenderPresent(renderer.get());
}

void Game::handle_events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			_is_running = false;
			break;
		default:
			break;
	}
}

void Game::clean() {
	_window.reset();
	renderer.reset();
	_player.reset();
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
