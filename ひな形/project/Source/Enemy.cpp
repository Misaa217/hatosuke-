#include "Enemy.h"
#include <DxLib.h>

Enemy::Enemy()
{
    LoadDivGraph(
        "data/image/enemy.png",
        8,
        4,
        2,
        64,
        160,
        image
    );

    direction = GetRand(1);

    // 左から右へ飛ぶ
    if (direction == 0)
    {
        x = -100;
    }
    // 右から左へ飛ぶ
    else
    {
        x = 1280;
    }

    y = 300;

    speed = 4.0f;
    pat = 0;
    count = 0;
}

Enemy::~Enemy()
{
   
    for (int i = 0; i < 8; i++)
    {
        DeleteGraph(image[i]);
    }
}

void Enemy::Update()
{
        if (direction == 0)
        {
            x += speed;
        }
        else
        {
            x -= speed;
        }


        // 羽ばたきアニメーション
        count++;

        if (count >= 10)
        {
            count = 0;

            pat++;

            if (pat >= 4)
            {
                pat = 0;
            }
        }


        // 画面外に出たら再出現
        if (x > 1280 || x < -100)
        {
            // 左右をランダムに決める
            direction = GetRand(1);

           
            if (direction == 0)
            {
                x = -100;
            }
           
            else
            {
                x = 1280;
            }

            pat = 0;
            count = 0;
        }
}

void Enemy::Draw()
{
    int graph;

   
    if (direction == 0)
    {
       graph = 4 + pat;
    }
   
    else
    {
        graph = pat;
    }

    DrawGraph(
        (int)x,
        (int)y,
        image[graph],
        TRUE
    );
}

float Enemy::GetX() const
{
    return x;
}

float Enemy::GetY() const
{
    return y;
}