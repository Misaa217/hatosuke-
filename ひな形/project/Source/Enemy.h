#pragma once

#include "../Library/GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy();
    ~Enemy();

    void Update() override;
    void Draw() override;

    float GetX() const;
    float GetY() const;

private:
    int image[8];

    float x;
    float y;
    float speed;

    // 0 = ¶‚©‚ç‰E
    // 1 = ‰E‚©‚ç¶
    int direction;
    int pat;
    int count;
};
