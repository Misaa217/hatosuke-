#include "Player.h"
#include <DxLib.h>
#include "Screen.h"


Player::Player()
{
	image = LoadGraph("data/image/hato.png");
	x = (Screen::WIDTH - 100) / 2;
	y = (Screen::HEIGHT - 125) / 2;

	pat = 0;
	count = 0;
	dir = DOWN;
	move = STOP;
}

Player::~Player()
{
	
}

void Player::GoRight(float spd)
{
	x += spd;
	if (x > Screen::WIDTH - 100) {
		x = Screen::WIDTH - 100;
	}
	dir = RIGHT;
	move = WALK;
}



void Player::Update()
{
	posX += 1;
	float speed = 3;

	move = STOP;
	if (CheckHitKey(KEY_INPUT_D)) { // Dキーを押したので、右に行く
		GoRight(speed);
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		x -= speed;
		if (x < 0) {
			x = 0;
		}
		dir = LEFT;
		move = WALK;
	}
	if (CheckHitKey(KEY_INPUT_W)) {
		y -= speed;
		if (y < 0) {
			y = 0;
		}
		dir = UP;
		move = WALK;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		y += speed;
		if (y > Screen::HEIGHT - 125) {
			y = Screen::HEIGHT - 125;
		}
		dir = DOWN;
		move = WALK;
	}

	count += 1;

	if (count >= 10) {
		count = 0;
		if (move == WALK) {
			pat = (pat + 1) % 4;
		}
		else {
			pat = 0;
		}
	}

	
}

void Player::Draw()
{
	
	
	DrawRectExtendGraph(
			(int)x, (int)y,
			(int)x + 100, (int)y + 125,
			64 * pat, 80 * dir,
			64, 80,
			image,
			TRUE
		);
	
}


float Player::GetX() const
{
	return x;
}

float Player::GetY() const
{
	return y;
}