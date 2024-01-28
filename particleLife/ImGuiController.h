#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

class ImGuiController {
private:
	sf::Clock deltaClock;

	void Settings(int* particlesAmounts, float* beta, float* maxRadius, 
		float* dt, float* forceFactor, bool& start);

public:
	ImGuiController();
	~ImGuiController();
	void initialize(sf::RenderWindow& window);
	void eventProcessing(sf::Event& event);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window, int* particlesAmounts, float* beta, 
		float* maxRadius, float* dt, float* forceFactor, bool& start);
};

