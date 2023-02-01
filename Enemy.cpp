#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(int x, int y, Player* player) {
	posX_ = x;
	posY_ = y;
	player_ = player;
	speed_ = 4;
	radius_ = 30;
};

Enemy::~Enemy() {

};

void Enemy::Update()
{
	posX_ += speed_;
	if (posX_ > 1280 - radius_ || posX_ < radius_ ) {
		speed_ *= -1;
	}
	for (int i = 0; i < kBulletMax; i++) {
		if (abs(player_->bullet_[i]->bullet_.x - posX_) < radius_ + player_->bullet_[i]->bullet_.r &&
			abs(player_->bullet_[i]->bullet_.y - posY_) < radius_ + player_->bullet_[i]->bullet_.r) {
			isEnemy = 0;
		}
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0, RED, kFillModeSolid);
}