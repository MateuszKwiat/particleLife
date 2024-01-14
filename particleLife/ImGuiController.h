#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

class ImGuiController {
private:
	sf::Clock deltaClock;

	void Settings();

public:
	ImGuiController();
	~ImGuiController();
	void initialize(sf::RenderWindow& window);
	void eventProcessing(sf::Event& event);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
};

