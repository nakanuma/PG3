#include "IScene.h"

int IScene::scene = STAGE;

IScene::~IScene() {}

int IScene::GetScene() { return scene; }
