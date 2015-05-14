#include "Bullet.h"

Bullet::Bullet(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed, SDL_Rect target, const int SCREEN_W, const int SCREEN_H) : Entity(uid, entity, color, entities, speed), target(target), SCREEN_W(SCREEN_W), SCREEN_H(SCREEN_H){}

void Bullet::tick(float delta) {

}