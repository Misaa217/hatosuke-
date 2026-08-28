#pragma once

#include "../Library/GameObject.h"

class Corn : public GameObject
{
public:
    Corn();
    ~Corn();

    void Update() override;
    void Draw() override;

private:
    int image;

    float x;
    float y;

    const int SIZE = 64;
};