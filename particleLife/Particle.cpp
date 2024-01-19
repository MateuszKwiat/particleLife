#include "Particle.h"

void Particle::setFillColor(sf::Color color) {
	this->shape.setFillColor(color);
}

Particle::Particle() : shape(2.f), gen(rd()), disX(0, 1500), disY(0, 900) {
	this->radiusValue = 10.f;
	this->shape.setFillColor(sf::Color(204, 77, 5));
	this->shape.setOrigin(radiusValue, radiusValue);
	this->shape.setPosition(disX(gen), disY(gen));
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