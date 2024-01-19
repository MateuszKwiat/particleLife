#pragma once

#include <SFML/Graphics.hpp>

#include <random>

class Particle {
private:
	sf::CircleShape shape;
	float radiusValue;

	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> disX;
	std::uniform_real_distribution<> disY;

	sf::Color color;

public:
	Particle(sf::Color color);
	
	void setPosition(float x, float y);
	
	sf::Vector2f const getPosition() const;
	sf::CircleShape getShape();
	float getRadius();
};

