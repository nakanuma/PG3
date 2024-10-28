#pragma once
#include <stdint.h>
#include "Vector3.h"

class Enemy {
public:
	enum Phase {
		APPROACH,
		FIRE, 
		LEAVE
	};

public:
	Enemy();
	~Enemy();

	// 接近
	void Approach();
	// 射撃
	void Fire();
	// 離脱
	void Leave();

	// 更新
	void Update();

	// 現在フェーズの名前を取得
	const char* GetPhaseName() const;
	// 現在フェーズを取得
	Phase GetCurrentPhase() const { return phase_; }
	// 座標を取得
	Vector3 GetPosition() const { return position_; }
	// 残弾数を取得
	uint32_t GetLeftBullet() const { return bullet_; }

private:
	// メンバ関数ポインタのテーブル
	static void (Enemy::*spFuncTable[])();

	// 現在フェーズ
	Phase phase_;

	// 座標
	Vector3 position_;

	// 弾
	int32_t bullet_;
};
