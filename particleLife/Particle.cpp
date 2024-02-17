#include "Particle.h"

//sf::Color(204, 77, 5)

Particle::Particle(sf::Color color, int colorValue) : 
	shape(2.f), colorValue(colorValue) {
	this->radiusValue = 10.f;
	this->shape.setFillColor(color);
	this->shape.setOrigin(radiusValue, radiusValue);
}

void Particle::setPosition(float x, float y) {
	this->shape.setPosition(x, y);
}

sf::Vector2f const Particle::getPosition() const {
	return this->shape.getPosition();
}

sf::CircleShape Particle::getShape() {
	return this->shape;
}

float Particle::getRadius() {
	return this->radiusValue;
}