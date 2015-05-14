#include "Enemy.h"

Enemy::Enemy(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed) : Entity(uid, entity, color, entities, speed) {}

void Enemy::tick(float delta) {

}