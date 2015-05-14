#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
	Bullet(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed, SDL_Rect target, const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	void tick(float delta);
private:
	const int SCREEN_W, SCREEN_H;
	SDL_Rect target;
};

#endif