#include "ImGuiController.h"
#include "ParticlesCalculations.h"

void ImGuiController::Settings(int* particlesAmounts, float* beta,
	float* maxRadius, float* dt, float* forceFactor, bool& start) {
	ImGui::Begin("Settings");
	ImGui::Text("Amounts");
	ImGui::BeginChild("Amounts", ImVec2(300, 100));
	ImGui::SliderInt("Red", &particlesAmounts[0], 1, 1000);
	ImGui::SliderInt("Green", &particlesAmounts[1], 1, 1000);
	ImGui::SliderInt("Blue", &particlesAmounts[2], 1, 1000);
	ImGui::SliderInt("Yellow", &particlesAmounts[3], 1, 1000);
	ImGui::EndChild();
	ImGui::Text("Parameters");
	ImGui::BeginChild("Parameters", ImVec2(300, 100));
	ImGui::SliderFloat("Beta", beta, 0.f, 1.f);
	ImGui::SliderFloat("Max Radius", maxRadius, 10.f, 100.f);
	ImGui::SliderFloat("DT", dt, 0.0001f, 0.1f);
	ImGui::SliderFloat("Force Factor", forceFactor, 0.f, 100.f);
	ImGui::EndChild();
	ImGui::Text("Attractions");
	ImGui::BeginChild("Attractions", ImVec2(300, 200));
	//ImGui::SliderFloat("Red - Red", &(particlesAttractions[0][0]), -1.f, 1.f);
	ImGui::EndChild();
	if (ImGui::Button("Start simulation"))
		start = true;

	ImGui::End();
}

// red, green, blue

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