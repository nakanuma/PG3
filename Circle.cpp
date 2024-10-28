#include "Circle.h"

void Circle::Size() { 
	size_ = std::numbers::pi_v<float> * radius_ * radius_; 
}

void Circle::Draw() { 
	// –ÊÏ‚ÌŒvZ‚ğs‚Á‚Äo—Í
	Size();
	std::cout << "Circle area:" << size_ << std::endl; 
}
