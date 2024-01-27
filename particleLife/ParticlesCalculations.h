#pragma once

#include "Particle.h"

#include <cmath>
#include <random>

class ParticlesCalculations {
private:
	float particlesAtractionMatrix[4][4];

    const float dt;
    const float maxRadius;
    const float frictionHalfLife;

    float xDist;
    float yDist;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> randFloat;

public:
    ParticlesCalculations();
    float calcDistance(float xDistance, float yDistance);
    float distance(sf::CircleShape&& circ1, sf::CircleShape&& circ2, sf::Window* window);
};

