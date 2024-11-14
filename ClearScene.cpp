#include "ClearScene.h"
#include "imgui.h"
#include "Novice.h"
#include "Input.h"

void ClearScene::Init() { 
	textureClear_ = Novice::LoadTexture("./Resources/Images/clear.png"); 
}

void ClearScene::Update() { 
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		scene = TITLE;
	}
}

void ClearScene::Draw() {
	Novice::DrawSprite(0, 0, textureClear_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

	ImGui::Begin("Window");
	ImGui::Text("Current Scene = CLEAR");
	ImGui::End();
}
