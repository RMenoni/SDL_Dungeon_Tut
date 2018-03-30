#include "SpriteComponent.hpp"



SpriteComponent::SpriteComponent(std::string texture_path) {
	_texture = TextureManager::load_texture(texture_path);
}


SpriteComponent::~SpriteComponent()
{
}


void SpriteComponent::init() {
	_position = &entity->get_component<PositionComponent>();
	if (!entity->has_component<PositionComponent>()) { throw std::runtime_error("No Position Component!"); }
	PositionComponent& p = entity->get_component<PositionComponent>();
	_source_rect.x = _source_rect.y = 0;
	_source_rect.w = _source_rect.h = 32;
	_destination_rect.w = _destination_rect.h = 64;
}

void SpriteComponent::update() {
	_destination_rect.x = _position->x();
	_destination_rect.y = _position->y();
}

void SpriteComponent::draw() {
	TextureManager::draw(_texture, _source_rect, _destination_rect);
}