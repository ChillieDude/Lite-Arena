#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
	Player(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed);
	void tick(float delta);
	void move(int x, int y, float delta);
	void HandleState(const Uint8* state);
private:
    	int xMove, yMove;
};

#endif
