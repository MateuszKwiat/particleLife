#include "App.h"

App::App() : isRunning(true) {
	this->videMode = sf::VideoMode(1500, 900);
	this->window = new sf::RenderWindow(this->videMode, "Particle Life");
	this->window->setFramerateLimit(60);
}

App::~App() {
	delete this->window;
}

void App::windowUpdateAndDisplay() {
	this->window->clear(sf::Color(18, 33, 43));
	this->window->display();
}

const bool App::running() const {
	return isRunning;
}

void App::pollEvents() {
	while (this->window->pollEvent(this->event)) {
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
	this->pollEvents();
	this->windowUpdateAndDisplay();
}