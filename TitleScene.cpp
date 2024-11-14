#include "TitleScene.h"
#include "imgui.h"
#include "Input.h"
#include "Novice.h"

#include "TextureManager.h"

void TitleScene::Init() { 
	textureTitle_ = Novice::LoadTexture("./Resources/Images/title.png"); 
}

void TitleScene::Update() { 

	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		scene = STAGE;
	}
}

void TitleScene::Draw() {
	Novice::DrawSprite(0, 0, textureTitle_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

	ImGui::Begin("Window");
	ImGui::Text("Current Scene = TITLE");
	ImGui::End();
}
