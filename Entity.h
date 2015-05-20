#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <vector>

class Enemy;

class Entity {
public:
	Entity(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed);
	virtual ~Entity();
	
	virtual SDL_Rect getEntity();
	virtual void setPosition(int x, int y);
	virtual void tick(float delta)=0;
	virtual float getSpeed();
	virtual void setSpeed(float speed);
	void draw(SDL_Renderer*& renderer);
	std::vector<Entity*>& getEntities();
	bool isAlive();
	void setAlive(bool alive);
	const int getUID();
private:
	const int UID;
	SDL_Rect ent;
	SDL_Color color;
	bool alive;
	std::vector<Entity*>& ents;
	float speed;
};

#endif
