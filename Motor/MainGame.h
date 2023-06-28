#pragma once

#include <SDL/SDL.h>
#include <GL/eglew.h>
#include <vector>
#include "Sprite.h"
#include "HLSLProgram.h"
#include "Window.h"
#include "Camera2D.h"
#include "InputManager.h"
#include "Level.h"
#include "Player.h"
#include "Human.h"
#include "Bullet.h"
#include "Zombie.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"

enum class GameState {
    PLAY, EXIT
};

class MainGame {
private:
    int width;
    int height;
    SpriteFont* spriteFont;
    SpriteBatch spriteBatch;
    SpriteBatch hudBatch;
    std::vector<Level*> levels;
    std::vector<Bullet*> bullets;
    std::vector<Human*> humans;
    std::vector<Zombie*> zombies;
    Player* player;
    int currentLevel;
    Window window;
    HLSLProgram program;
    Sprite sprite;
    Camera2D camera2D;
    InputManager inputManager;
    void init();
    void initLevel();
    void processInput();
    void initShaders();
    void handleInput();
    void updateElements();
    void createBullet();
    int totalHumanos;
    int totalZombies;


public:
    MainGame();
    ~MainGame();
    GameState gameState;

    void run();
    void draw();
    void drawHud();
    void update();
};

