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
	// 敵のインスタンスを作成
	std::unique_ptr<Enemy> enemy_;
	enemy_ = std::make_unique<Enemy>();

	// 前回フェーズの保存
	Enemy::Phase previousPhase = static_cast<Enemy::Phase>(-1);

	// ゲームループ
	while (true) {
		enemy_->Update();

		// 現在のフェーズを取得
		Enemy::Phase currentPhase = enemy_->GetCurrentPhase();

		// フェーズ変更が行われた際のみフェーズを表示
		if (currentPhase != previousPhase) {
			std::cout << "Current Phase:" << enemy_->GetPhaseName() << std::endl;
			previousPhase = currentPhase;
		}

		// Approachフェーズのときに座標を表示
		if (currentPhase == Enemy::APPROACH) {
			const Vector3& pos = enemy_->GetPosition();
			std::cout << "position.z:" << pos.z << std::endl;
		}

		// Fireフェーズのときに残弾を表示
		if (currentPhase == Enemy::FIRE) {
			const int32_t& leftBullet = enemy_->GetLeftBullet();
			std::cout << "leftBullet:" << leftBullet << std::endl;
		}

		// 確認しやすいように長めに遅延
		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}

	return 0;
}