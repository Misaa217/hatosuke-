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

	player = new Player();

	// 敵を3体作る
	enemies.push_back(new Enemy());
	enemies.push_back(new Enemy());
	enemies.push_back(new Enemy());

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

	// すべての敵と当たり判定
	for (Enemy* enemy : enemies)
	{
		float enemyX = enemy->GetX();
		float enemyY = enemy->GetY();

		// 敵の当たり判定
		float enemyHitX = enemyX + 20;
		float enemyHitY = enemyY + 25;
		float enemyHitW = 40;
		float enemyHitH = 85;

		// ハトの当たり判定
		float playerHitX = playerX + 30;
		float playerHitY = playerY + 30;
		float playerHitW = 40;
		float playerHitH = 60;

		if (playerHitX + playerHitW > enemyHitX &&
			playerHitX < enemyHitX + enemyHitW &&
			playerHitY + playerHitH > enemyHitY &&
			playerHitY < enemyHitY + enemyHitH)
		{
			gameOver = true;

			player->SetActive(false);

			for (Enemy* e : enemies)
			{
				e->SetActive(false);
			}

			break;
		}
	}

	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
}


void PlayScene::Draw()
{
	DrawGraph(0, 0, stimage, TRUE);

	// 通常プレイ
	if (!gameOver)
	{
		int font = CreateFontToHandle(NULL, 100, -1, DX_FONTTYPE_NORMAL);
		DrawFormatString(
			50,
			50,
			GetColor(0, 0, 0),
			"コーン：%d個",
			cornCount
		);
	}
	// GAME OVER
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

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		SetFontSize(60);

		DrawString(
			470,
			300,
			"GAME OVER",
			GetColor(255, 0, 0)
		);

		SetFontSize(16);

		DrawString(
			440,
			400,
			"タイトルへ　Tキー",
			GetColor(255, 255, 255)
		);
	}
}


void PlayScene::AddCorn()
{
	cornCount++;
}