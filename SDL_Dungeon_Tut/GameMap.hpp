#pragma once
#include <vector>
#include <string>
#include "TextureManager.h"
using std::vector;

class GameMap
{
public:
	GameMap();
	~GameMap();
	void load_map(vector<vector <int>> map);
	void draw_map();

private:
	const std::string DIRT_IMG_FILENAME  = "assets/dirt.png";
	const std::string GRASS_IMG_FILENAME = "assets/grass.png";
	const std::string WATER_IMG_FILENAME = "assets/water.png";
	static const int WATER_TILE  = 0;
	static const int GRASS_TILE  = 1;
	static const int DIRT_TILE   = 2;
	static const int TILE_WIDTH  = 32;
	static const int TILE_HEIGHT = 32;
	SDL_Rect _source_rectangle;
	SDL_Rect _destination_rectangle;
	uptr<SDL_Texture> _dirt;
	uptr<SDL_Texture> _grass;
	uptr<SDL_Texture> _water;
	vector<vector<int>> _map;
};
