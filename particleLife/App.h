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
	std::vector<float> velocitiesX;
	std::vector<float> velocitiesY;

	float velocityX;
	float velocityY;
	float forceFactor;

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

