#include "Entity.h"

Entity::Entity(const int uid, SDL_Rect ent, SDL_Color color, std::vector<Entity*>& ents, float speed) : UID(uid), ent(ent), color(color), alive(true), ents(ents), speed(speed) {}

SDL_Rect Entity::getEntity() {
	return ent;
}

void Entity::setPosition(int x, int y) {
	ent.x = x;
	ent.y = y;
}

void Entity::draw(SDL_Renderer*& renderer) {
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_RenderFillRect(renderer, &ent);
}

float Entity::getSpeed() {
	return speed;
}

const int Entity::getUID() {
	return UID;
}

void Entity::setSpeed(float s) {
	speed = s;
}

void Entity::setAlive(bool b) {
	alive = b;
}

bool Entity::isAlive() {
	return alive;
}

std::vector<Entity*>& Entity::getEntities() {
	return ents;
}