#include "MainGame.h"
#include"Error.h"
#include<iostream>
using namespace std;

MainGame::MainGame() {
	window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;

}

MainGame::~MainGame() {

}
void MainGame::processImput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			cout << event.motion.x << " , " << event.motion.y << endl;
			break;
		}
	}

}

void MainGame::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Prueba", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		fatalError("SDL not initialized");
		//validar si falla para mostrar mensaje	
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//validar si falla para mostrar mensaje
		fatalError("GLEW not initialized");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(1.5f, 0.0f,2.0f,1.0f);
}

void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sprite.draw();
	sprite2.draw();
	//SI TENGO ELEMENTOS ACTUALIZO
	SDL_GL_SwapWindow(window);
}

void MainGame::run() {
	init();
	sprite.init(1, 1, -1, -1); 
	sprite2.init(-1, -1, 1, 1);
	update();
}

void MainGame::update() {
	while (gameState != GameState::EXIT) {
		draw();
		processImput();
	}

}