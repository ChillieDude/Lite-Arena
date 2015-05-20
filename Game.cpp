#include "Game.h"
#include <iostream>

Game::Game(const int w, const int h) : SCREEN_W(w), SCREEN_H(h), running(false), INIT_SDL(false), INIT_IMG(false), INIT_TTF(false), INIT_MIXER(false) {}

Game::~Game() {
	if(window)
		SDL_DestroyWindow(window);
	if(renderer)
		SDL_DestroyRenderer(renderer);

	window = nullptr;
	renderer = nullptr;

	if(INIT_IMG)
		IMG_Quit();
	if(INIT_TTF)
		TTF_Quit();
	if(INIT_MIXER)
		Mix_CloseAudio();
	if(INIT_SDL)
		SDL_Quit();
}

void Game::run() {
	if(!init()) {
		return;
	}

	running = true;
	play();
}

bool Game::isRunning() {
	return running;
}

bool Game::init() {
	//Load SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return false;
	}
	INIT_SDL = true;

	//Load Image Library
	if(IMG_Init(IMG_INIT_PNG) == 0) {
		std::cout << "Failed to initialize SDL_image library: " << IMG_GetError() << std::endl;
		return false;
	}
	INIT_IMG = true;

	//Load TTF Library
	if(TTF_Init() == -1) {
		std::cout << "Failed to initialize SDL_ttf library: " << TTF_GetError() << std::endl;
		return false;
	}
	INIT_TTF = true;

	//Load Mixer library
	if(Mix_OpenAudio(44050, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
		std::cout << "Failed to initialize SDL_mixer library: " << Mix_GetError() << std::endl;
		return false;
	}
	INIT_MIXER = true;

	//Create window
	window = SDL_CreateWindow("Lite Arena", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);

	if(!window) {
		std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
		return false;
	}

	//Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(!renderer) {
		std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

void Game::play() {
	int prevTime = 0, curTime = 0;
	float frameCount = 0.0f, delta = 0.0f;

	//Speeds
	float human_speed = 200.0f, bullet_speed = human_speed * 2;
	int UID_Count = 0;

	Player* player = new Player(UID_Count++, {0, 0, 50, 50}, {32, 162, 227, 255}, entities, human_speed);

	entities.push_back(player);
	entities.push_back(new Enemy(UID_Count++, {SCREEN_W/2-(50/2), SCREEN_H/2-(50/2), 50, 50}, {0, 0, 0, 255}, entities, human_speed));
	entities.push_back(new Enemy(UID_Count++, {100, 100, 50, 50}, {0, 0, 0, 255}, entities, human_speed));

	SDL_Event e;
	const Uint8* state;

	while(isRunning()) {
		prevTime = curTime;
		curTime = SDL_GetTicks();

		delta = (curTime - prevTime) / 1000.0f;

		frameCount += delta;

		while(SDL_PollEvent(&e) == 1) {
			switch(e.type) {
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
					switch(e.key.keysym.sym) {
						case SDLK_ESCAPE:
							running = false;
							break;
					}
					break;
				case SDL_MOUSEBUTTONDOWN:
					if(e.button.button = SDL_BUTTON_LEFT) {
						//SDL_Rect ply = player->getEntity();
						int x = e.button.x, y = e.button.y;
						SDL_Rect b_model = {x, y, 10, 10};

						Bullet* b = new Bullet(UID_Count++, b_model, {255, 0, 0, 255}, entities, bullet_speed, {x, y, 0, 0}, SCREEN_W, SCREEN_H);
						entities.push_back(b);
					}
					break;
				default:
					//Nothing yet
					break;
			}
		}
		
		//Handle the state before calling tick
		state = SDL_GetKeyboardState(NULL);
		player->HandleState(state)


		//Call tick() for all entities
		for(std::vector<Entity*>::iterator e = entities.begin(); e != entities.end(); ++e) {
			(*e)->tick(delta);
		}

		//Remove all dead entities
		for(int i = 0; i < entities.size(); i++) {
			if(!entities[i]->isAlive()) {
				entities.erase(entities.begin() + i);
			}
		}

		//Clear renderer, and draw white canvas
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		//Draw
		for(std::vector<Entity*>::iterator e = entities.begin(); e != entities.end(); ++e) {
			(*e)->draw(renderer);
		}

		SDL_RenderPresent(renderer);
	}
	for(int i = 0; i < entities.size(); i++) {
		delete entities[i];
	}
	entities.clear();
}
