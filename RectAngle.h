#pragma once
#include "IShape.h"

class RectAngle : public IShape{
public:
	RectAngle(float w, float h) : width(w), height(h) {}

	void Size() override;
	void Draw() override;

private:
	float width;
	float height;
	float size_;
};
