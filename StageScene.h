#pragma once
#include "IScene.h"
#include <stdint.h>
#include "Enemy.h"
#include "Player.h"
#include <memory>

class StageScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

	void CheckCollision();

private:
	uint32_t textureStage_;

	std::unique_ptr<Enemy> enemy_;
	std::unique_ptr<Player> player_;
};
