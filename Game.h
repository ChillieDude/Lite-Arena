#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

class Game {
public:
	Game(const int SCREEN_WIDTH, const int SCREEN_HEIGHT);
	~Game();
	void run();
	
	static const SCREEN_WIDTH = 640;
	static const SCREEN_HEIGHT = 480;
private:
	void play();
	bool init();
	bool isRunning();

	const int SCREEN_W, SCREEN_H;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running, INIT_SDL, INIT_IMG, INIT_TTF, INIT_MIXER;
	std::vector<Entity*> entities;
};

#endif
