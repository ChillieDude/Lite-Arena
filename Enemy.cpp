#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed) : Entity(uid, entity, color, entities, speed) {}

Enemy::~Enemy()
{
  std::cout << "Enemy Destroyed" <<std::endl;
}

void Enemy::tick(float delta) {

}
