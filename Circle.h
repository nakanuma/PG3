#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
	Circle(float r) : radius_(r) {}

	void Size() override;
	void Draw() override;

private: 
	float radius_;
	float size_;
};
