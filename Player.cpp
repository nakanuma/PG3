#include "Player.h"
#include "Input.h"

void Player::Init() {
	texturePlayer_ = Novice::LoadTexture("./Resources/Images/player.png");
	position_ = {640.0f, 480.0f};

	textureBullet_ = Novice::LoadTexture("./Resources/Images/bullet.png");
}

void Player::Update() { 
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		bullet_ = std::make_unique<Bullet>();
		bullet_->Init(this->position_);
	}

	if (bullet_) {
		bullet_->Update();
	}
}

void Player::Draw() {
	if (bullet_) {
		bullet_->Draw(textureBullet_);
	}

	uint32_t centerPosX = static_cast<int>(position_.x) - static_cast<int>(kRadius_);
	uint32_t centerPosY = static_cast<int>(position_.y) - static_cast<int>(kRadius_);

	Novice::DrawSprite(centerPosX, centerPosY, texturePlayer_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
