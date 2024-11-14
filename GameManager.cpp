#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager() { 
	sceneArr_[TITLE] = std::make_unique<TitleScene>();
	sceneArr_[STAGE] = std::make_unique<StageScene>();
	sceneArr_[CLEAR] = std::make_unique<ClearScene>();

	currentSceneNo_ = TITLE;
	prevSceneNo_ = -1;

	input_ = Input::GetInstance();
	input_->Initialize();
}

GameManager::~GameManager() {}

void GameManager::Run() { 
	while (Novice::ProcessMessage() == 0) {

		Novice::BeginFrame();

		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetScene();

		if (prevSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Init();
		}

		sceneArr_[currentSceneNo_]->Update();

		sceneArr_[currentSceneNo_]->Draw();

		prevSceneNo_ = currentSceneNo_;

		Novice::EndFrame();

		if (input_->TriggerKey(DIK_ESCAPE)) {
			break;
		}
	}
}
