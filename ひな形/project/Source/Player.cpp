#include "Player.h"
#include <DxLib.h>
#include "Screen.h"


Player::Player()
{
	image = LoadGraph("data/image/hato.png");
	x = 20;
	y = 50;
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
	if (x > Screen::WIDTH - CHR_SIZE) {
		x = Screen::WIDTH - CHR_SIZE;
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
		if (y > Screen::HEIGHT - CHR_SIZE) {
			y = Screen::HEIGHT - CHR_SIZE;
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
	DrawRectGraph(x, y, CHR_SIZE * pat, CHR_SIZE * dir,
		CHR_SIZE, CHR_SIZE, image, 1);
}
