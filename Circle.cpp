#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Circle::Size() { 
	/*size_ = std::numbers::pi_v<float> * radius_ * radius_; */
	size_ = static_cast<float>(M_PI) * radius_ * radius_;
}

void Circle::Draw() { 
	// �ʐς̌v�Z���s���ďo��
	Size();
	std::cout << "Circle area:" << size_ << std::endl; 
}
