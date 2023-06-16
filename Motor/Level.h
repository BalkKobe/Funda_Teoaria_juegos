#pragma once
#include <string>
#include <vector>
#include "SpriteBatch.h"

using namespace std;
const int TILE_WIDTH = 64;
class Level
{
private:
	vector<string> levelData;
	int numHumans;
	int numZombies;
	void parseLevel();
	glm::vec2 playerPosition;
	vector<glm::vec2> zombiesPosition;
	SpriteBatch spriteBatch;
public:
	int getNumHumans()const {
		return numHumans;
	}
	int getNumZombies()const {
		return numZombies;
	}
	glm::vec2 getPlayerPosition()const {
		return playerPosition;
	}
	vector<string> getLevelData() {
		return levelData;
	}
	int getWidth()const {
		return levelData[0].size();
	}
	int getHeight()const {
		return levelData[0].size();
	}
	Level(const string& fileName);
	void draw();
	~Level();
};

