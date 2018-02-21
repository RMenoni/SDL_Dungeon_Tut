#include "TextureManager.h"

unique_ptr<SDL_Texture> TextureManager::load_texture(std::string file_name, shared_ptr<SDL_Renderer> renderer) {
	auto temp_surface = unique_ptr<SDL_Surface, SDL_Deleter>(IMG_Load(file_name.c_str()));
}