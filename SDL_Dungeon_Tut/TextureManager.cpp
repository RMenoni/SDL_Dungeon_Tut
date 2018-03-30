#include "TextureManager.h"
#include <iostream>

uptr<SDL_Renderer> TextureManager::renderer = nullptr;

uptr<SDL_Texture> TextureManager::load_texture(std::string file_name) {
	auto temp_surface = uptr<SDL_Surface>(IMG_Load(file_name.c_str()));
	auto texture = uptr<SDL_Texture>(SDL_CreateTextureFromSurface(renderer.get(), temp_surface.get()));
	return texture;
}

void TextureManager::draw(const uptr<SDL_Texture> &texture, SDL_Rect source,  SDL_Rect destination) {
	SDL_RenderCopy(renderer.get(), texture.get(), &source, &destination);
}