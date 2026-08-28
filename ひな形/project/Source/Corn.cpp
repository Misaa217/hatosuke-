#include "Corn.h"
#include <DxLib.h>
#include "Screen.h"
#include "Player.h"
#include "PlayScene.h"

Corn::Corn()
{
    // コーンの画像を読み込む
    image = LoadGraph("data/image/corn.png");
   // x = 200;
   // y = 200;
    // ランダムな場所に出現
    x = GetRand(Screen::WIDTH - SIZE);
    y = GetRand(Screen::HEIGHT - SIZE);
}

Corn::~Corn()
{
    DeleteGraph(image);
}

void Corn::Update()
{
    // Playerを探す
    Player* player = FindGameObject<Player>();

    if (player == nullptr)
        return;

    // 鳩の位置を取得
    float px = player->GetX();
    float py = player->GetY();

    // 鳩とコーンが重なったか確認
    if (x < px + 128 &&
        x + SIZE > px &&
        y < py + 160 &&
        y + SIZE > py)
    {
        // 現在のシーンを取得
        PlayScene* scene = GetScene<PlayScene>();

        // コーンの取得数を1増やす
        if (scene != nullptr)
        {
            scene->AddCorn();
        }
        new Corn();
        // コーンを消す
        DestroyMe();
    }
}

void Corn::Draw()
{
    // コーンを表示
    DrawGraph((int)x, (int)y, image, TRUE);
}
