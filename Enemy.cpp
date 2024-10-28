#include "Enemy.h"
#include <iostream>

// �t�F�[�Y�̊֐��e�[�u��
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
	// z��-10�ɓ��B������U���t�F�[�Y�ֈڍs�i��O�����ֈړ�������z��j
	position_.z -= kSpeed;
	if (position_.z < -10.0f) {
		phase_ = Phase::FIRE;
	};
}

void Enemy::Fire() { 
	// �e�̔���
	bullet_ -= 1;

	// �c�e�������Ȃ����痣�E�t�F�[�Y�ֈڍs
	if (bullet_ < 0) {
		phase_ = Phase::LEAVE;
	}
}

void Enemy::Leave() {

}

void Enemy::Update() {
	// ���݃t�F�[�Y�̊֐������s
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
