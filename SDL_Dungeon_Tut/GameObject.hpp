#pragma once
#include <string>
#include "SDL_Ptr.cpp"

class GameObject
{
public:
	GameObject(std::string texture_sheet, int x, int y);
	~GameObject();
	void update();
	void render();
private:
	int _x_position;
	int _y_position;
	uptr<SDL_Texture> _texture;
	SDL_Rect source_rectangle;
	SDL_Rect destination_rectangle;
};

