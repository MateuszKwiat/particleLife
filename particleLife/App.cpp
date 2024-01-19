#include "App.h"

App::App() : isRunning(true), particlesAmount(100), start(false), ImGuiController() {
	this->videMode = sf::VideoMode(1500, 900);
	this->window = new sf::RenderWindow(this->videMode, "Particle Life");
	this->window->setFramerateLimit(60);

	ImGuiController::initialize(*this->window);
}

App::~App() {
	ImGuiController::~ImGuiController();
	delete this->window;
}

void App::windowUpdateAndDisplay() {
	this->window->clear(sf::Color(18, 33, 43));
	for (auto x : particlesVector)
		this->window->draw(x->getShape());
	
	ImGuiController::update(*this->window);
	ImGuiController::render(*this->window, &this->particlesAmount, this->start);
	
	this->window->display();
}

void App::vectorInitialize() {

}

const bool App::running() const {
	return isRunning;
}

void App::pollEvents() {
	while (this->window->pollEvent(this->event)) {
		ImGuiController::eventProcessing(this->event);

		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			this->isRunning = false;
			break;

		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape) {
				this->window->close();
				this->isRunning = false;
			}

			break;
		}
	}
}

void App::render() {
	if (start) {
		for (auto x : particlesVector) {
			delete x;
		}
		particlesVector.clear();

		for (int i = 0; i < particlesAmount; i++)
			this->particlesVector.push_back(new Particle());

		start = false;
	}

	this->pollEvents();
	this->windowUpdateAndDisplay();
}