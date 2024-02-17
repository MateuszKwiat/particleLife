#include "ImGuiController.h"
#include "ParticlesCalculations.h"

//**************************	TODO: FIX	**************************
void ImGuiController::Settings(int* particlesAmounts, float* beta,
	float* maxRadius, float* dt, float* forceFactor, float** particlesAttraction, bool& start) {
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
	ImGui::BeginChild("Attractions", ImVec2(300, 380));
	ImGui::SliderFloat("Red - Red", &particlesAttraction[0][0], -1.f, 1.f);
	ImGui::SliderFloat("Red - Green", &particlesAttraction[0][1], -1.f, 1.f);
	ImGui::SliderFloat("Red - Blue", &particlesAttraction[0][2], -1.f, 1.f);
	ImGui::SliderFloat("Red - Yellow", &particlesAttraction[0][3], -1.f, 1.f);
	ImGui::SliderFloat("Green - Red", &particlesAttraction[1][0], -1.f, 1.f);
	ImGui::SliderFloat("Green - Green", &particlesAttraction[1][1], -1.f, 1.f);
	ImGui::SliderFloat("Green - Blue", &particlesAttraction[1][2], -1.f, 1.f);
	ImGui::SliderFloat("Green - Yellow", &particlesAttraction[1][3], -1.f, 1.f);
	ImGui::SliderFloat("Blue - Red", &particlesAttraction[2][0], -1.f, 1.f);
	ImGui::SliderFloat("Blue - Green", &particlesAttraction[2][1], -1.f, 1.f);
	ImGui::SliderFloat("Blue - Blue", &particlesAttraction[2][2], -1.f, 1.f);
	ImGui::SliderFloat("Blue - Yellow", &particlesAttraction[2][3], -1.f, 1.f);
	ImGui::SliderFloat("Yellow - Red", &particlesAttraction[3][0], -1.f, 1.f);
	ImGui::SliderFloat("Yellow - Green", &particlesAttraction[3][1], -1.f, 1.f);
	ImGui::SliderFloat("Yellow - Blue", &particlesAttraction[3][2], -1.f, 1.f);
	ImGui::SliderFloat("Yellow - Yellow", &particlesAttraction[3][3], -1.f, 1.f);
	ImGui::EndChild();
	if (ImGui::Button("Start simulation"))
		start = true;

	ImGui::End();
}

// red, green, blue, yellow

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

//**************************	TODO: FIX	**************************
void ImGuiController::render(sf::RenderWindow& window, int* particlesAmounts,
	float* beta, float* maxRadius, float* dt, float* forceFactor, float** particlesAttraction, bool&start) {
	this->Settings(particlesAmounts, beta, maxRadius, dt, forceFactor, particlesAttraction, start);
	ImGui::SFML::Render(window);
}