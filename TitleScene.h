#pragma once
#include "IScene.h"

#include <memory>

#include "Sprite.h"
#include "TextureManager.h"

class TitleScene : public IScene{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	uint32_t textureTitle_;
};
