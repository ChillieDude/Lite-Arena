#include "Player.h"
#include "Enemy.h"
#include <iostream>

Player::Player(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed) : Entity(uid, entity, color, entities, speed) {}

void Player::tick(float delta) {

}

void Player::move(int dirX, int dirY, float delta, const int SCREEN_W, const int SCREEN_H) {
	SDL_Rect entity = getEntity();
	int new_x = entity.x + ((dirX * (getSpeed() * delta)) + (dirX > 0 ? 1 : 0));
	int new_y = entity.y + ((dirY * (getSpeed() * delta)) + (dirY > 0 ? 1 : 0));
	SDL_Rect next = {new_x, new_y, entity.w, entity.h};

	for(std::vector<Entity*>::iterator e = getEntities().begin(); e != getEntities().end(); ++e) {
		if((*e)->getUID() == getUID()) continue;

		SDL_Rect temp = (*e)->getEntity(), intersect;
		if(SDL_IntersectRect(&next, &temp, &intersect)) {
			if(dirX == 1) {
				new_x = intersect.x - next.w;
			}else if(dirX == -1)
				new_x = intersect.x + intersect.w;
			else if(dirY == 1)
				new_y = intersect.y - next.h;
			else if(dirY == -1)
				new_y = intersect.y + intersect.h;
		}
	}

	if(new_x < 0) new_x = 0;
	if(new_x + next.w > SCREEN_W) new_x = SCREEN_W - next.w;
	if(new_y < 0) new_y = 0;
	if(new_y + next.h > SCREEN_H) new_y = SCREEN_H - next.h;

	setPosition(new_x, new_y);
}