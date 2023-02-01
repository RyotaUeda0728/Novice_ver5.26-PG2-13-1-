#include "Bullet.h"
#pragma once
typedef struct Transform {
	int x;
	int y;
	int r;
};
const int kBulletMax = 20;
class Player {
private:
	int speed_;
public:
	Player(Transform t, int speed);
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();

	Transform transform_;
	Bullet* bullet_[kBulletMax];
	Bullet bulletInfo_;
};

