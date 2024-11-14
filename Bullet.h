#pragma once
#include "Novice.h"
#include "stdint.h"
#include "Vector2.h"

class Bullet {
public:
	void Init(const Vector2& position);
	void Update();
	void Draw(uint32_t textureHandle);

	void OnCollision();
	bool IsDead() { return isDead_; }

	Vector2 GetPosition() { return position_; }
	float GetRadius() { return kRadius_; }

private:
	Vector2 position_;
	Vector2 velocity_;
	const float kRadius_ = 16.0f;

	bool isDead_ = false;
};
