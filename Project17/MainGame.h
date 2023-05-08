#pragma once
#include<SDL/SDL.h>
#include<GL/eglew.h>
#include"Sprite.h"
#include"Sprite2.h"

enum class GameState {
	PLAY, EXIT
};
class MainGame
{
private:
	int width, height;
	SDL_Window* window;
	void init();
	Sprite sprite;
	Sprite2 sprite2;
	void processImput();

public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};

