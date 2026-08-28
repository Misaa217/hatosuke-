#pragma once
#include "../Library/SceneBase.h"
#include"Player.h"
#include "Corn.h"

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
	Player player;
	int stimage;
	int cornCount;
};

