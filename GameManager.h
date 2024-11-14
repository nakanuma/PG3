#pragma once
#include <memory>
#include "IScene.h"
#include "StageScene.h"
#include "TitleScene.h"
#include "ClearScene.h"

#include "Input.h"

class GameManager {
private:
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;

	Input* input_ = nullptr;

public:
	GameManager();
	~GameManager();

	void Run();
};
