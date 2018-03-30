#pragma once
#include "Components.h"
class PositionComponent :
	public Component
{
public:
	PositionComponent();
	PositionComponent(int x, int y);
	~PositionComponent();
	void init() override;
	void update() override;
	void set_position(int x, int y);
	int x() { return x_position; }
	int y() { return y_position; }

private:
	int x_position;
	int y_position;
};

