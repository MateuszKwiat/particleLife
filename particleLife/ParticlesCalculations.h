#pragma once

#include "Particle.h"

#include <cmath>
#include <random>

class ParticlesCalculations {
private:
	float particlesAtractionMatrix[4][4];

    float dt;
    float maxRadius;
    const float frictionHalfLife;
    const float frictionFactor;
    float beta;

    float xDist;
    float yDist;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> randFloat;

public:
    ParticlesCalculations();
    float calcDistance(float xDistance, float yDistance);
    float distance(const Particle& particle1, const Particle& particle2, sf::Window* window);
    float forceFunction(float radius, int i, int j);
    float getDt() { return dt; }
    float getMaxRadius() { return maxRadius; }
    float getFrictionFactor() { return frictionFactor; }
    float* getDTPointer() { return &dt; }
    float* getBetaPointer() { return &beta; }
    float* getMaxRadiusPointer() { return &maxRadius; }
};

