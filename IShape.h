#pragma once
#include <numbers>
#include <cmath>
#include <iostream>

class IShape {
public:
	// 仮想デストラクタ
	virtual ~IShape() = default;

	// 純粋仮想関数
	virtual void Size() = 0;
	virtual void Draw() = 0;
};
