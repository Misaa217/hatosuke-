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
       
        PlayScene* scene = GetScene<PlayScene>();

      
        if (scene != nullptr)
        {
            scene->AddCorn();
        }
        new Corn();
       
        DestroyMe();
    }
}

void Corn::Draw()
{
    
    DrawGraph((int)x, (int)y, image, TRUE);
}
