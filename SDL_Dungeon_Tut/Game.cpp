#include "Game.hpp"



Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char *title, int x_pos, int y_pos, int width, int height, bool is_fullscreen) {
	int flags = is_fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialized!" << std::endl;
		_window.reset(SDL_CreateWindow(title, x_pos, y_pos, width, height, flags));
		if (_window.get() != NULL) {
			std::cout << "Window created!" << std::endl;
		}
		_renderer.reset(SDL_CreateRenderer(_window.get(), -1, 0));
		if (_renderer.get() != NULL) {
			SDL_SetRenderDrawColor(_renderer.get(), 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		_is_running = true;
	}
	else {
		std::cout << "Could not initialize SDL!" << std::endl;
		_is_running = false;
	}

	unique_ptr<SDL_Surface, SDL_Deleter> temporary_surface(IMG_Load("main_char.png"));
	if (temporary_surface.get() == NULL) {
		throw std::runtime_error("Could not load player surface. Error: " + std::string(IMG_GetError()));
	}
	_player_texture.reset(SDL_CreateTextureFromSurface(_renderer.get(), temporary_surface.get()));
}

void Game::update() {
	_counter++;
	destination_rect.h = 64;
	destination_rect.w = 64;
	destination_rect.x = _counter;
	std::cout << _counter << std::endl;
}

void Game::render() {
	SDL_RenderClear(_renderer.get());
	SDL_RenderCopy(_renderer.get(), _player_texture.get(), NULL, &destination_rect);
	SDL_RenderPresent(_renderer.get());
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
	_renderer.reset();
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
