#pragma once
#include "Vector2.h"
#include "Novice.h"
#include "stdint.h"
#include <list>
#include <memory>

#include "Bullet.h"

class Player {
public:
	void Init();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

	const std::unique_ptr<Bullet>& GetBullet() const { return bullet_; }

private:
	Vector2 position_;
	const float kRadius_ = 16.0f;
	const float kSpeed_ = 4.0f;

	uint32_t texturePlayer_;
	uint32_t textureBullet_;

	std::unique_ptr<Bullet> bullet_;
};
