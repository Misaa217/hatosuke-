#pragma once
#include "../Library/SceneBase.h"
#include"Player.h"
#include "Corn.h"
#include "Enemy.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>
class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
	float GetX() const;
	float GetY() const;
	void AddCorn();
private:
	Player* player;
	Enemy* enemy;
	int stimage;
	int cornCount;
	bool gameOver;
};

