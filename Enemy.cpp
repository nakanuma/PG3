#include "Enemy.h"
#include "Novice.h"

void Enemy::Init() { 
	textureEnemy_ = Novice::LoadTexture("./Resources/Images/enemy.png"); 
	position_ = {640.0f, 240.0f};
}

void Enemy::Update() {
	
}

void Enemy::Draw() { 
	if (isDead_) {
		return;
	}

	uint32_t centerPosX = static_cast<int>(position_.x) - static_cast<int>(kRadius_);
	uint32_t centerPosY = static_cast<int>(position_.y) - static_cast<int>(kRadius_);

	Novice::DrawSprite(centerPosX, centerPosY, textureEnemy_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}

void Enemy::OnCollision() { 
	isDead_ = true;
}
