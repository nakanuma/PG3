#include "Enemy.h"
#include <iostream>

// フェーズの関数テーブル
void (Enemy::*Enemy::spFuncTable[])() 
= {
	&Enemy::Approach, 
	&Enemy::Fire, 
	&Enemy::Leave
};

Enemy::Enemy() { 
	phase_ = Phase::APPROACH; 
	position_ = {0.0f, 0.0f, 0.0f};
	bullet_ = 5;
}

Enemy::~Enemy() {}

void Enemy::Approach() { 
	const float kSpeed = 1.0f; 
	// zが-10に到達したら攻撃フェーズへ移行（手前方向へ移動させる想定）
	position_.z -= kSpeed;
	if (position_.z < -10.0f) {
		phase_ = Phase::FIRE;
	};
}

void Enemy::Fire() { 
	// 弾の発射
	bullet_ -= 1;

	// 残弾が無くなったら離脱フェーズへ移行
	if (bullet_ < 0) {
		phase_ = Phase::LEAVE;
	}
}

void Enemy::Leave() {

}

void Enemy::Update() {
	// 現在フェーズの関数を実行
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

const char* Enemy::GetPhaseName() const { 
	switch (phase_) {
	case APPROACH:
		return "Approach";
	case FIRE:
		return "Fire";
	case LEAVE:
		return "Leave";
	default:
		return "Null";
	}
}
