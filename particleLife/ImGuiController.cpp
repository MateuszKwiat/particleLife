#include "ImGuiController.h"

void ImGuiController::Settings(int* particlesAmount, bool& start) {
	ImGui::Begin("Settings");
	ImGui::SliderInt("Particles amount", particlesAmount, 1, 1000);
	if (ImGui::Button("Start simulation"))
		start = true;

	ImGui::End();
}

ImGuiController::ImGuiController() {
}

ImGuiController::~ImGuiController() {
	ImGui::SFML::Shutdown();
}

void ImGuiController::initialize(sf::RenderWindow& window) {
	ImGui::SFML::Init(window);
}

void ImGuiController::eventProcessing(sf::Event& event) {
	ImGui::SFML::ProcessEvent(event);
}

void ImGuiController::update(sf::RenderWindow& window) {
	ImGui::SFML::Update(window, this->deltaClock.restart());
}

void ImGuiController::render(sf::RenderWindow& window, int* particlesAmount, bool&start) {
	this->Settings(particlesAmount, start);
	ImGui::SFML::Render(window);
}