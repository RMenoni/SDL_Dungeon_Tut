#include "Game.hpp"

Manager manager;
auto &new_player(manager.add_entity());

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
		TextureManager::renderer = std::move(uptr<SDL_Renderer>(SDL_CreateRenderer(_window.get(), -1, 0)));
		if (TextureManager::renderer.get() != NULL) {
			SDL_SetRenderDrawColor(TextureManager::renderer.get(), 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		_is_running = true;
	}
	else {
		std::cout << "Could not initialize SDL!" << std::endl;
		_is_running = false;
	}
	
	_game_map = std::make_unique<GameMap>();

	std::cout << "Gonna create pos comp" << std::endl;
	new_player.add_component<PositionComponent>();
	std::cout << "Gonna create sprite comp" << std::endl;
	new_player.add_component<SpriteComponent>(PLAYER_IMG_FILENAME);
}

void Game::update() {

	manager.update();
}

void Game::render() {
	SDL_RenderClear(TextureManager::renderer.get());
	_game_map->draw_map();
	manager.draw();
	SDL_RenderPresent(TextureManager::renderer.get());
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
	TextureManager::renderer.reset();
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
