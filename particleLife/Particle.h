#pragma once

#include <SFML/Graphics.hpp>

class Particle {
private:
	sf::CircleShape shape;
	float radiusValue;

	void setFillColor(sf::Color color);

public:
	Particle();
	
	void setPosition(float x, float y);
	
	sf::Vector2f const getPosition() const;
	sf::CircleShape getShape();
	float getRadius();
};

