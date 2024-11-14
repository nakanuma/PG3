#pragma once
#include "IScene.h"
#include <stdint.h>

class ClearScene : public IScene{
	void Init() override;
	void Update() override;
	void Draw() override;

private:
	uint32_t textureClear_;
};
