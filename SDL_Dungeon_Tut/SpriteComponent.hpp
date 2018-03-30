#pragma once
#include "ECS.h"
#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"

class PositionComponent;
class SpriteComponent :
	public Component
{
public:
	SpriteComponent() = default;
	SpriteComponent(std::string texture_path);
	~SpriteComponent();
	void init() override;
	void update() override;
	void draw() override;

private:
	PositionComponent *_position;
	uptr<SDL_Texture> _texture;
	SDL_Rect _source_rect;
	SDL_Rect _destination_rect;
};

