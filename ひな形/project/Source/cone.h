#pragma once
#include "../Library/GameObject.h"

class Cone : public GameObject
{
public:
	Cone();
	~Cone();
	void Update() override;
	void Draw() override;
	
private:
	int coneimage;
};

