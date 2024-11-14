#include "StageScene.h"
#include "imgui.h"
#include "Novice.h"
#include <cmath>

void StageScene::Init() { 
	textureStage_ = Novice::LoadTexture("./Resources/Images/stage.png"); 

	player_ = std::make_unique<Player>();
	player_->Init();

	enemy_ = std::make_unique<Enemy>();
	enemy_->Init();
}

void StageScene::Update() { 
	player_->Update();

	enemy_->Update();

	CheckCollision();

	if (enemy_->IsDead()) {
		scene = CLEAR;
	}
}

void StageScene::Draw() {
	Novice::DrawSprite(0, 0, textureStage_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

	player_->Draw();

	enemy_->Draw();

	ImGui::Begin("Window");
	ImGui::Text("Current Scene = STAGE");
	ImGui::End();
}

void StageScene::CheckCollision() { 
	if (player_->GetBullet() != nullptr) {
		Vector2 enemyPos = enemy_->GetPosition();
		float enemyRadius = enemy_->GetRadius();

		Vector2 bulletPos = player_->GetBullet()->GetPosition();
		float bulletRadius = player_->GetBullet()->GetRadius();

		float distance = std::powf(bulletPos.x - enemyPos.x, 2) + std::powf(bulletPos.y - enemyPos.y, 2);
		float conbinedRadius = std::powf(bulletRadius + enemyRadius, 2);

		if (distance <= conbinedRadius) {
			enemy_->OnCollision();
			player_->GetBullet()->OnCollision();
		}
	}
}
