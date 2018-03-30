#pragma once
#include "SDL_Ptr.cpp"
#include <string>

class TextureManager
{
public:
	static uptr<SDL_Texture> load_texture(std::string file_name);
	static void draw(const uptr<SDL_Texture> &texture, SDL_Rect source, SDL_Rect destination);
	static uptr<SDL_Renderer> renderer;
private:
	TextureManager() {}
};

