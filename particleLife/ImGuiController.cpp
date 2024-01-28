#include "ImGuiController.h"

void ImGuiController::Settings(int* particlesAmounts, float* beta,
	float* maxRadius, float* dt, float* forceFactor, bool& start) {
	ImGui::Begin("Settings");
	ImGui::SliderInt("Red particles amount", &particlesAmounts[0], 1, 1000);
	ImGui::SliderInt("Green particles amount", &particlesAmounts[1], 1, 1000);
	ImGui::SliderInt("Blue particles amount", &particlesAmounts[2], 1, 1000);
	ImGui::SliderInt("Yellow particles amount", &particlesAmounts[3], 1, 1000);
	ImGui::SliderFloat("Beta", beta, 0.f, 1.f);
	ImGui::SliderFloat("Max Radius", maxRadius, 10.f, 100.f);
	ImGui::SliderFloat("DT", dt, 0.0001f, 0.1f);
	ImGui::SliderFloat("Force Factor", forceFactor, 0.f, 20.f);
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

void ImGuiController::render(sf::RenderWindow& window, int* particlesAmounts,
	float* beta, float* maxRadius, float* dt, float* forceFactor, bool&start) {
	this->Settings(particlesAmounts, beta, maxRadius, dt, forceFactor, start);
	ImGui::SFML::Render(window);
}