#include "Rectangle.h"

void RectAngle::Size() {
	size_ = width * height; 
}

void RectAngle::Draw() { 
	// �ʐς̌v�Z���s���ďo��
	Size(); 
	std::cout << "Rectangle area:" << size_ << std::endl;
}
