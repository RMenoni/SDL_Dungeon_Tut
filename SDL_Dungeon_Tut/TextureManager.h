#pragma once
#include "Game.hpp"
using std::shared_ptr;

class TextureManager
{
public:
	static unique_ptr<SDL_Texture> load_texture(std::string file_name, shared_ptr<SDL_Renderer> renderer);
};

