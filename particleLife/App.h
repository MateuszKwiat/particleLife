#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include "Particle.h"
#include "ImGuiController.h"
#include "ParticlesCalculations.h"

#include <vector>

class App : private ImGuiController, private ParticlesCalculations {
private:
	sf::VideoMode videMode;
	sf::RenderWindow* window;
	sf::Event event;

	bool isRunning;
	bool start;

	sf::Color colors[4];
	int particlesAmounts[4];

	std::vector<Particle*> particlesVector;

	void windowUpdateAndDisplay();
	void vectorInitialize();
	void updateParticles();

public:
	App();
	~App();

	const bool running() const;
	void pollEvents();
	void render();
};

