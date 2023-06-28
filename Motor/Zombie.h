#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Agent.h"

class Zombie : public Agent {
public:
    Zombie();
    ~Zombie();

    void init(float speed, glm::vec2 position);

    Human* getNearestHuman(std::vector<Human*>& humans);

    void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans, std::vector<Zombie*>& zombies);

    int totalZombies; // Nueva variable agregada

private:
    
};
