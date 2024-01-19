#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include "Particle.h"
#include "ImGuiController.h"

#include <vector>

class App : private ImGuiController {
private:
	sf::VideoMode videMode;
	sf::RenderWindow* window;
	sf::Event event;

	bool isRunning;
	bool start;
	int particlesAmount;
	std::vector<Particle*> particlesVector;

	void windowUpdateAndDisplay();
	void vectorInitialize();

public:
	App();
	~App();

	const bool running() const;
	void pollEvents();
	void render();
};

