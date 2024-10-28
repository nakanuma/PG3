#pragma once
#include <numbers>
#include <cmath>
#include <iostream>

class IShape {
public:
	// ���z�f�X�g���N�^
	virtual ~IShape() = default;

	// �������z�֐�
	virtual void Size() = 0;
	virtual void Draw() = 0;
};
