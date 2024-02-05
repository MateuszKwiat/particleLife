#include "ParticlesCalculations.h"

ParticlesCalculations::ParticlesCalculations() 
    : maxRadius(30.f) , gen(rd()), randFloat(-1, 1), dt(0.02),
    frictionHalfLife(0.4), beta(0.3), frictionFactor(pow(0.5, dt / frictionHalfLife)) {
    for (int i = 0; i < 4; i++) {
        this->particlesAtractionMatrix[i] = new float[4];

        for (int j = 0; j < 4; j++)
            this->particlesAtractionMatrix[i][j] =  randFloat(gen);
    }
}

float ParticlesCalculations::calcDistance(float xDistance, float yDistance) {
    return std::sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

float ParticlesCalculations::distance(const Particle& particle1, const Particle& particle2, sf::Window* window) {
    this->xDist = abs(particle1.getPosition().x - particle2.getPosition().x);
    this->yDist = abs(particle1.getPosition().y - particle2.getPosition().y);
    
    if (xDist < maxRadius && yDist < maxRadius)
        return calcDistance(xDist, yDist);

    ////  X AXIS EDGES CASE
    //if (particle1.getPosition().x < maxRadius && particle2.getPosition().x > window->getSize().x - maxRadius) {
    //    xDist = abs(particle1.getPosition().x + window->getSize().x - particle2.getPosition().x);
    //}
    //else if (particle2.getPosition().x < maxRadius && particle1.getPosition().x > window->getSize().x - maxRadius) {
    //    xDist = abs(particle2.getPosition().x + window->getSize().x - particle1.getPosition().x);
    //}
    //
    ////  Y AXIS EDGES CASE
    //if (particle1.getPosition().y < maxRadius && particle2.getPosition().y > window->getSize().y - maxRadius) {
    //    yDist = abs(particle1.getPosition().y - particle2.getPosition().y + window->getSize().y);
    //}
    //else if (particle2.getPosition().y < maxRadius && particle1.getPosition().y > window->getSize().y - maxRadius) {
    //    yDist = abs(particle2.getPosition().y - particle1.getPosition().y + window->getSize().y);
    //}
    //
    //return calcDistance(xDist, yDist);
}

float ParticlesCalculations::forceFunction(float radius, int i, int j) {
    if (radius < beta)
        return (radius / beta) - 1;
    else if (beta < radius && radius < 1) {
        const float attraction = particlesAtractionMatrix[i][j];

        return attraction * (1 - abs((2 * radius) - 1 - beta) / (1 - beta));
    }
    else
        return 0;
}