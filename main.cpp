#include <Windows.h>
#include <stdio.h>
#include <random>
#include <functional>
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>

#include "Enemy.h"

int main() {
	// �G�̃C���X�^���X���쐬
	std::unique_ptr<Enemy> enemy_;
	enemy_ = std::make_unique<Enemy>();

	// �O��t�F�[�Y�̕ۑ�
	Enemy::Phase previousPhase = static_cast<Enemy::Phase>(-1);

	// �Q�[�����[�v
	while (true) {
		enemy_->Update();

		// ���݂̃t�F�[�Y���擾
		Enemy::Phase currentPhase = enemy_->GetCurrentPhase();

		// �t�F�[�Y�ύX���s��ꂽ�ۂ̂݃t�F�[�Y��\��
		if (currentPhase != previousPhase) {
			std::cout << "Current Phase:" << enemy_->GetPhaseName() << std::endl;
			previousPhase = currentPhase;
		}

		// Approach�t�F�[�Y�̂Ƃ��ɍ��W��\��
		if (currentPhase == Enemy::APPROACH) {
			const Vector3& pos = enemy_->GetPosition();
			std::cout << "position.z:" << pos.z << std::endl;
		}

		// Fire�t�F�[�Y�̂Ƃ��Ɏc�e��\��
		if (currentPhase == Enemy::FIRE) {
			const int32_t& leftBullet = enemy_->GetLeftBullet();
			std::cout << "leftBullet:" << leftBullet << std::endl;
		}

		// �m�F���₷���悤�ɒ��߂ɒx��
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	return 0;
}