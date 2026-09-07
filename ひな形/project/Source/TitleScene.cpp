#include "TitleScene.h"

TitleScene::TitleScene()
{
	bgImage = LoadGraph("data/image/title.png");
	font = CreateFontToHandle("ÇlÇr ÉSÉVÉbÉN", 52, 3);
}

TitleScene::~TitleScene()
{
	DeleteGraph(bgImage);
	DeleteFontToHandle(font);
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawGraph(0, 0, bgImage, FALSE);

	extern const char* Version();
	//DrawString(0, 20, Version(), GetColor(255,255,255));
	//DrawString(0, 0, "TITLE SCENE", GetColor(255,255,255));
	//DrawFormatString(100, 100, GetColor(255,255,255), "%4.1f", 1.0f / Time::DeltaTime());
	DrawStringToHandle(530, 590, "PUSH SPACE", GetColor(220, 170, 0), font);
}
