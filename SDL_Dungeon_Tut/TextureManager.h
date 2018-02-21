#pragma once
#include "Game.hpp"

class TextureManager
{
public:
	static uptr<SDL_Texture> load_texture(std::string file_name);
};

