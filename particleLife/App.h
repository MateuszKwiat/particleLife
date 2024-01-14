#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include "Particle.h"

#include <vector>

class App {
private:
	sf::VideoMode videMode;
	sf::RenderWindow* window;
	sf::Event event;

	bool isRunning;
	std::vector<Particle> particlesVector;

	void windowUpdateAndDisplay();

public:
	App();
	~App();

	const bool running() const;
	void pollEvents();
	void render();
};

