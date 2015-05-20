#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
	Bullet(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed, SDL_Rect target);
	~Bullet();
	void tick(float delta);
private:
	SDL_Rect target;
};

#endif
