#pragma once
#include "SDL_Ptr.cpp"
#include <string>

class TextureManager
{
public:
	TextureManager(uptr<SDL_Renderer> renderer);
	~TextureManager();
	uptr<SDL_Texture> load_texture(std::string file_name);
	void draw(const uptr<SDL_Texture> &texture, SDL_Rect source, SDL_Rect destination);
	uptr<SDL_Renderer> renderer;
};

