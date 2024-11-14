#include "Bullet.h"

void Bullet::Init(const Vector2& position) { 
	position_ = position; 
	velocity_ = {0.0f, -4.0f};
}

void Bullet::Update() { 
	position_ += velocity_; 
}

void Bullet::Draw(uint32_t textureHandle) { 
	if (isDead_) {
		return;
	}

	uint32_t centerPosX = static_cast<int>(position_.x) - static_cast<int>(kRadius_);
	uint32_t centerPosY = static_cast<int>(position_.y) - static_cast<int>(kRadius_);

	Novice::DrawSprite(centerPosX, centerPosY, textureHandle, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}

void Bullet::OnCollision() { 
	isDead_ = true;
}
