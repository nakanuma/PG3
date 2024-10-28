#include <Windows.h>
#include <stdio.h>
#include <random>
#include <functional>
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

#include "IShape.h"
#include "Circle.h"
#include "RectAngle.h"

int main() {
	std::vector<std::unique_ptr<IShape>> shapes;
	shapes.push_back(std::make_unique<Circle>(5.0f));
	shapes.push_back(std::make_unique<RectAngle>(4.0f, 6.0f));

	for (const auto& shape : shapes) {
		shape->Draw();
	}

	return 0;
}