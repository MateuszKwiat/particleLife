#include "ParticlesCalculations.h"

ParticlesCalculations::ParticlesCalculations() 
    : maxRadius(100.f) , gen(rd), randFloat(-1, 1), dt(0.2), frictionHalfLife(0.04) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            this->particlesAtractionMatrix[i][j] = randFloat(gen);
}

float ParticlesCalculations::calcDistance(float xDistance, float yDistance) {
    return std::sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

float ParticlesCalculations::distance(sf::CircleShape&& circ1, sf::CircleShape&& circ2, sf::Window* window) {
    this->xDist = abs(circ1.getPosition().x - circ2.getPosition().x);
    this->yDist = abs(circ1.getPosition().y - circ2.getPosition().y);
    
    if (xDist < maxRadius && yDist < maxRadius)
        return calcDistance(xDist, yDist);

    //  X AXIS EDGES CASE
    if (circ1.getPosition().x < maxRadius && circ2.getPosition().x > window->getSize().x - maxRadius) {
        xDist = abs(circ1.getPosition().x + window->getSize().x - circ2.getPosition().x);
    }
    else if (circ2.getPosition().x < maxRadius && circ1.getPosition().x > window->getSize().x - maxRadius) {
        xDist = abs(circ2.getPosition().x + window->getSize().x - circ1.getPosition().x);
    }

    //  Y AXIS EDGES CASE
    if (circ1.getPosition().y < maxRadius && circ2.getPosition().y > window->getSize().y - maxRadius) {
        yDist = abs(circ1.getPosition().y - circ2.getPosition().y + window->getSize().y);
    }
    else if (circ2.getPosition().y < maxRadius && circ1.getPosition().y > window->getSize().y - maxRadius) {
        yDist = abs(circ2.getPosition().y - circ1.getPosition().y + window->getSize().y);
    }

    return calcDistance(xDist, yDist);
}