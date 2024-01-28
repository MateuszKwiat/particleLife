#include "App.h"

App::App() 
	: isRunning(true), start(false), ImGuiController(), ParticlesCalculations(), 
	velocityX(0), velocityY(0), forceFactor(10) {
	this->videMode = sf::VideoMode(1600, 900);
	this->window = new sf::RenderWindow(this->videMode, "Particle Life");
	this->window->setFramerateLimit(60);

	ImGuiController::initialize(*this->window);

	this->colors[0] = sf::Color::Red;
	this->colors[1] = sf::Color::Green;
	this->colors[2] = sf::Color::Blue;
	this->colors[3] = sf::Color::Yellow;

	for (auto& x : particlesAmounts)
		x = 100;
}

App::~App() {
	ImGuiController::~ImGuiController();
	delete this->window;
}

void App::updateParticles() {
	for (int i = 0; i < particlesVector.size(); i++) {
		velocityX = 0;
		velocityY = 0;

		for (int j = 0; j < particlesVector.size(); j++) {
			const float radiusX = particlesVector[i]->getPosition().x - particlesVector[j]->getPosition().x;
			const float radiusY = particlesVector[i]->getPosition().y - particlesVector[j]->getPosition().y;
			const float distance = ParticlesCalculations::distance(*particlesVector[i], 
				*particlesVector[j], this->window);
		
			if (distance > 0 && distance < ParticlesCalculations::getMaxRadius()) {
				const float f = ParticlesCalculations::forceFunction(distance / ParticlesCalculations::getMaxRadius(),
					particlesVector[i]->getColorValue(), particlesVector[j]->getColorValue());
				velocityX += (radiusX / distance) * f;
				velocityY += (radiusY / distance) *  f;
			}
		}
		
		velocityX *= ParticlesCalculations::getMaxRadius() * forceFactor;
		velocityY *= ParticlesCalculations::getMaxRadius() * forceFactor;

		velocitiesX[i] *= ParticlesCalculations::getFrictionFactor();
		velocitiesY[i] *= ParticlesCalculations::getFrictionFactor();
	
		velocitiesX[i] += velocityX * ParticlesCalculations::getDt();
		velocitiesY[i] += velocityY * ParticlesCalculations::getDt();
	}

	for (int i = 0; i < particlesVector.size(); i++) {
		particlesVector[i]->setPosition(particlesVector[i]->getPosition().x
			+ velocitiesX[i] * ParticlesCalculations::getDt(),
			particlesVector[i]->getPosition().y + velocitiesY[i] * ParticlesCalculations::getDt());

		if (particlesVector[i]->getPosition().x > window->getSize().x)
			particlesVector[i]->setPosition(0, particlesVector[i]->getPosition().y);
		else if (particlesVector[i]->getPosition().x < 0)
			particlesVector[i]->setPosition(window->getSize().x, particlesVector[i]->getPosition().y);

		if (particlesVector[i]->getPosition().y > window->getSize().y)
			particlesVector[i]->setPosition(particlesVector[i]->getPosition().x, 0);
		else if (particlesVector[i]->getPosition().y < 0)
			particlesVector[i]->setPosition(particlesVector[i]->getPosition().x, window->getSize().y);
	}

}

/*
for (auto& x : particlesVec) {
			if (x.getPosition().x > window.getSize().x + halfOfCircleRadius)
				x.setPosition(-halfOfCircleRadius, x.getPosition().y);
			else if (x.getPosition().x < -halfOfCircleRadius)
				x.setPosition(window.getSize().x + halfOfCircleRadius, x.getPosition().y);

			if (x.getPosition().y > window.getSize().y + halfOfCircleRadius)
				x.setPosition(x.getPosition().x, -halfOfCircleRadius);
			else if (x.getPosition().y < -halfOfCircleRadius)
				x.setPosition(x.getPosition().x, window.getSize().y + halfOfCircleRadius);

		}
*/

void App::windowUpdateAndDisplay() {
	this->updateParticles();
	this->window->clear(sf::Color(18, 33, 43));
	for (auto x : particlesVector)
		this->window->draw(x->getShape());
	
	ImGuiController::update(*this->window);
	ImGuiController::render(*this->window, this->particlesAmounts, ParticlesCalculations::getBetaPointer(), 
		ParticlesCalculations::getMaxRadiusPointer(), ParticlesCalculations::getDTPointer(),
		&forceFactor, this->start);
	
	this->window->display();
}

void App::vectorInitialize() {
	/*TODO*/
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

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < particlesAmounts[i]; j++) {
				this->particlesVector.push_back(new Particle(colors[i], i));
				this->velocitiesX.push_back(0.f);
				this->velocitiesY.push_back(0.f);
			}
		}	

		start = false;
	}

	this->pollEvents();
	this->windowUpdateAndDisplay();
}