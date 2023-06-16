#include "Zombie.h"


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(glm::vec2 position)
{
	this->path = "Textures/circle.png";
	this->position = position;
	color.set(0, 255, 0, 255);
}


