#pragma once

#include <SFML/Graphics.hpp>

class Particle {
private:
	sf::CircleShape shape;
	float radiusValue;

	int colorValue;

public:
	Particle(sf::Color color, int colorValue);
	
	void setPosition(float x, float y);
	
	sf::Vector2f const getPosition() const;
	sf::CircleShape getShape();
	float getRadius();
	float getColorValue() { return colorValue; }
};

