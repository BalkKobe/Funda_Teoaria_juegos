#pragma once
#include "Human.h"

class Zombie : public Human
{
protected:
	glm::vec2 direction;
public:
	Zombie();
	~Zombie();
	void init(glm::vec2 position);
	
};



