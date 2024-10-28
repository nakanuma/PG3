#include "Rectangle.h"

void RectAngle::Size() {
	size_ = width * height; 
}

void RectAngle::Draw() { 
	// –ÊÏ‚ÌŒvZ‚ğs‚Á‚Äo—Í
	Size(); 
	std::cout << "Rectangle area:" << size_ << std::endl;
}
