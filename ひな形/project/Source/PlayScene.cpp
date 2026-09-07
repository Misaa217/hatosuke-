#include "PlayScene.h"
#include "Player.h"
#include <DxLib.h>
#include "Screen.h"
#include <dxgi.h>
#include "Corn.h"
#include "Enemy.h"


PlayScene::PlayScene()
{
	stimage = LoadGraph("data/image/stage.png");
	//new Player();
	player = new Player();
	enemy = new Enemy();
	cornCount = 0;
	gameOver = false;
	new Corn();
	
	
}

PlayScene::~PlayScene()
{
	DeleteGraph(stimage);
}



void PlayScene::Update()
{
	if (gameOver)
	{
		if (CheckHitKey(KEY_INPUT_T))
		{
			SceneManager::ChangeScene("TITLE");
		}

		return;
	}

	float playerX = player->GetX();
	float playerY = player->GetY();

	float enemyX = enemy->GetX();
	float enemyY = enemy->GetY();

	if (playerX < enemyX + 64 &&
		playerX + 64 > enemyX &&
		playerY < enemyY + 160 &&
		playerY + 80 > enemyY)
	{
		gameOver = true;

		player->SetActive(false);
		enemy->SetActive(false);
	}

	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	
	DrawGraph(0, 0, stimage, TRUE);


	// --------------------
	// 通常プレイ
	// --------------------

	if (!gameOver)
	{
		DrawString(
			0,
			0,
			"PLAY SCENE",
			GetColor(255, 255, 255)
		);

		DrawFormatString(
			100,
			100,
			GetColor(255, 255, 255),
			"コーン：%d個",
			cornCount
		);
	}


	// --------------------
	// GAME OVER
	// --------------------

	else
	{
		// 画面を暗くする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);

		DrawBox(
			0,
			0,
			1280,
			720,
			GetColor(0, 0, 0),
			TRUE
		);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);


		DrawString(
			500,
			300,
			"GAME OVER",
			GetColor(255, 0, 0)
		);

		DrawString(
			440,
			400,
			"Push [T] Key To Title",
			GetColor(255, 255, 255)
		);
	}
}

void PlayScene::AddCorn()
{
	cornCount++;
}
