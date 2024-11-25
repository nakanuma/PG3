#pragma once
#include "IScene.h"
#include <stdint.h>
#include "Enemy.h"
#include "Player.h"
#include <memory>

#include "InputHandler.h"

class StageScene : public IScene {
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	InputHandler* inputHander_ = nullptr;
	ICommand* iCommand_ = nullptr;

	std::unique_ptr<Player> player_;
};
