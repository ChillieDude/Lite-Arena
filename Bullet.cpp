#include "Bullet.h"
#include <iostream>

Bullet::Bullet(const int uid, SDL_Rect entity, SDL_Color color, std::vector<Entity*>& entities, float speed, SDL_Rect target) : Entity(uid, entity, color, entities, speed), target(target)
{
    timer = SDL_GetTicks();
}

Bullet::~Bullet()
{
    std::cout << "Bullet Destoryed" <<std::endl;
}
void Bullet::tick(float delta) {
    int currentTime = SDL_GetTicks();
    if(currentTime - timer > 500) //If the bullet has been alive for 0.5 seconds...
    {
        setAlive(false);
    }
}
