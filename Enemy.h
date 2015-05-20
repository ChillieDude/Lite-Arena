#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
public:
	Enemy(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed);
	~Enemy();
	void tick(float delta);
private:

};

#endif
