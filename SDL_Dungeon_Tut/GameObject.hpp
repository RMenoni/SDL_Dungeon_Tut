#pragma once
#include <string>
#include "SDL_Ptr.cpp"
#include "TextureManager.h"

class GameObject
{
public:
	GameObject(std::string texture_sheet, std::shared_ptr<TextureManager> texture_manager, int x, int y);
	~GameObject();
	void update();
	void render();
private:
	int _x_position;
	int _y_position;
	uptr<SDL_Texture> _texture;
	std::shared_ptr<TextureManager> _texture_manager;
	SDL_Rect source_rectangle;
	SDL_Rect destination_rectangle;
};

