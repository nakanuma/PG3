#include "Circle.h"

void Circle::Size() { 
	size_ = std::numbers::pi_v<float> * radius_ * radius_; 
}

void Circle::Draw() { 
	// �ʐς̌v�Z���s���ďo��
	Size();
	std::cout << "Circle area:" << size_ << std::endl; 
}
