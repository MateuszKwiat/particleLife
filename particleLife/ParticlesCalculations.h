#pragma once

#include "Particle.h"

#include <cmath>
#include <random>
#include <array>

class ParticlesCalculations {
private:

    const float frictionHalfLife;
    const float frictionFactor;
	
    float* particlesAtractionMatrix[4];
    float attraction;
    float dt;
    float maxRadius;
    float beta;

    float xDist;
    float yDist;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> randFloat;


public:
    ParticlesCalculations();
    float distance(const Particle& particle1, const Particle& particle2, sf::Window* window);
    float forceFunction(float radius, int i, int j);
    float getDt() { return dt; }
    float getMaxRadius() { return maxRadius; }
    float getFrictionFactor() { return frictionFactor; }
    float* getDTPointer() { return &dt; }
    float* getBetaPointer() { return &beta; }
    float* getMaxRadiusPointer() { return &maxRadius; }
    float** getMatrixPointer() { return particlesAtractionMatrix; }
};

