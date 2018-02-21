#include "TextureManager.h"

uptr<SDL_Texture> TextureManager::load_texture(std::string file_name) {
	auto temp_surface = uptr<SDL_Surface>(IMG_Load(file_name.c_str()));
	auto texture = uptr<SDL_Texture>(SDL_CreateTextureFromSurface(Game::renderer.get(), temp_surface.get()));
	return texture;
}