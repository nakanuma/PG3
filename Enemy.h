#pragma once
#include "Vector2.h"
#include "stdint.h"

class Enemy {
public:
	void Init();
	void Update();
	void Draw();

	void OnCollision();
	bool IsDead() { return isDead_; }

	Vector2 GetPosition() { return position_; }
	float GetRadius() { return kRadius_; }

private:
	Vector2 position_;
	const float kRadius_ = 32.0f;
	bool isDead_ = false;

	uint32_t textureEnemy_;
};
