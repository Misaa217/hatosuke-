#pragma once
#include "../Library/GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void GoRight(float spd);
	
private:
	int image;
	const int CHR_SIZE = 64;

	float posX;
	float posY;
	float x = 20;
	float y = 50;
	int pat = 0; // アニメーションのパターン
	int count = 0; // アニメーションを遅らせるため
	const int DOWN = 3;
	const int LEFT = 1;
	const int UP = 2;
	const int RIGHT = 0;
	int dir; //= DOWN; // 向き
	const int STOP = 0;
	const int WALK = 1;
	int move; //= STOP;

	int remainTime = 10 * 60;
	
};

