#include "PlayScene.h"
#include "Player.h"
#include <DxLib.h>
#include "Screen.h"
#include <dxgi.h>


PlayScene::PlayScene()
{
	stimage = LoadGraph("data/image/stage.png");
	new Player();
	
}

PlayScene::~PlayScene()
{
	DeleteGraph(stimage);
}



void PlayScene::Update()
{
	player.Update();
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	
	DrawGraph(0, 0, stimage, TRUE);
	player.Draw();


	DrawString(0, 0, "PLAY SCENE", GetColor(255, 255, 255));
	DrawString(100, 400, "Push [T]Key To Title", GetColor(255, 255, 255));
}
