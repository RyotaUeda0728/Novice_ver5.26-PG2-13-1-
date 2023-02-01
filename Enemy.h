#pragma once
#include "Player.h"

class Enemy
{
private:
	int posX_, posY_;
	int speed_;
	int radius_;
public:
	static int isEnemy;
	Enemy(int x,int y,Player* player);
	~Enemy();
	void Update();
	void Draw();

	Player* player_;
};

