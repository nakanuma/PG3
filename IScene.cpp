#include "IScene.h"

int IScene::scene = TITLE;

IScene::~IScene() {}

int IScene::GetScene() { return scene; }
