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
	float windowWidth;
	float windowHeight;
	sf::RenderWindow* window;
	sf::Event event;

	std::random_device rd;
	std::mt19937 gen;
	std::uniform_real_distribution<> uniDist;

	bool isRunning;
	bool start;

	sf::Color colors[4];
	int particlesAmounts[4];

	std::vector<Particle*> particlesVector;
	std::vector<float> velocitiesX;
	std::vector<float> velocitiesY;
	std::vector<float> positionsX;
	std::vector<float> positionsY;

	float velocityX;
	float velocityY;
	float forceFactor;
	float radiusX;
	float radiusY;
	float distance;
	float functionOutput;

	void windowUpdateAndDisplay();
	void vectorInitialize();
	void calcVelocityAndPosition();
	void updateParticles();

public:
	App();
	~App();

	const bool running() const;
	void pollEvents();
	void render();
};

