#include "Rectangle.h"

void RectAngle::Size() {
	size_ = width * height; 
}

void RectAngle::Draw() { 
	// 面積の計算を行って出力
	Size(); 
	std::cout << "Rectangle area:" << size_ << std::endl;
}
