#include "PositionComponent.hpp"



PositionComponent::PositionComponent()
{
	this->init();
}

PositionComponent::PositionComponent(int x, int y) {
	this->set_position(x, y);
}


PositionComponent::~PositionComponent()
{
}


void PositionComponent::init() {
	this->set_position(0, 0);
}

void PositionComponent::update() {
	x_position++;
	y_position++;
}

void PositionComponent::set_position(int x, int y) {
	x_position = x;
	y_position = y;
}
