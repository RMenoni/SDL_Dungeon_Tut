#include "GameObject.hpp"
#include "TextureManager.h"


GameObject::GameObject(std::string texture_sheet, int x, int y)
{
	_texture = TextureManager::load_texture(texture_sheet);
	_x_position = x;
	_y_position = y;
}


GameObject::~GameObject()
{
}


void GameObject::update() {
	_x_position++;

	source_rectangle.h = 32;
	source_rectangle.w = 32;
	source_rectangle.x = 0;
	source_rectangle.y = 0;

	destination_rectangle.x = _x_position;
	destination_rectangle.y = _y_position;
	destination_rectangle.w = source_rectangle.w * 2;
	destination_rectangle.h = source_rectangle.h * 2;
}

void GameObject::render() {
	SDL_RenderCopy(Game::renderer.get(), _texture.get(), &source_rectangle, &destination_rectangle);
}
