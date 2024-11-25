#include "StageScene.h"
#include "imgui.h"
#include "Novice.h"
#include <cmath>

void StageScene::Init() { 
	inputHander_ = new InputHandler();

	inputHander_->AssignMoveRightCommand2PressKeyD();
	inputHander_->AssignMoveLeftCommand2PressKeyA();

	player_ = std::make_unique<Player>();
	player_->Init();
}

void StageScene::Update() { 
	iCommand_ = inputHander_->HandleInput();

	if (this->iCommand_) {
		iCommand_->Exec(*player_.get());
	}

	player_->Update();
}

void StageScene::Draw() {
	player_->Draw();

	ImGui::Begin("Window");
	ImGui::Text("Current Scene = STAGE");
	ImGui::End();
}