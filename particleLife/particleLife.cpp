#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include <cmath>
#include <vector>

// for different settings of particles check if particles of type X can get faster (avg of all X)

class Particle {
private:
    float radiusValue;
    sf::CircleShape shape;
  
public:
    Particle() : shape(10.f) {
        radiusValue = 10.f;
        shape.setFillColor(sf::Color(204, 77, 5));
        shape.setOrigin(radiusValue, radiusValue);
        shape.setPosition(200, 200);
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
    }

    void setFillColor(sf::Color col) {
        shape.setFillColor(col);
    }

    sf::Vector2f getPosition() {
        return shape.getPosition();
    }

    sf::CircleShape getShape() {
        return shape;
    }

    float getRadius() {
        return radiusValue;
    }
};

float calcDistance(float xDistance, float yDistance) {
    return std::sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

bool inRadius(sf::CircleShape&& circ1, sf::CircleShape&& circ2, sf::Window* window) {
    float maxRadius = 200.f;
    float xDist = abs(circ1.getPosition().x - circ2.getPosition().x);
    float yDist = abs(circ1.getPosition().y - circ2.getPosition().y);
    float distance = calcDistance(xDist, yDist);
    
    if (xDist < maxRadius && yDist < maxRadius)
        return calcDistance(xDist, yDist) <= maxRadius;
    
    //  X AXIS EDGES CASE
    if (circ1.getPosition().x < maxRadius && circ2.getPosition().x > window->getSize().x - maxRadius) {
        xDist = abs(circ1.getPosition().x + window->getSize().x - circ2.getPosition().x);
    }
    else if (circ2.getPosition().x < maxRadius && circ1.getPosition().x > window->getSize().x - maxRadius) {
        xDist = abs(circ2.getPosition().x + window->getSize().x - circ1.getPosition().x);
    }

    //  Y AXIS EDGES CASE
    if (circ1.getPosition().y < maxRadius && circ2.getPosition().y > window->getSize().y - maxRadius) {
        yDist = abs(circ1.getPosition().y - circ2.getPosition().y + window->getSize().y);
    }
    else if (circ2.getPosition().y < maxRadius && circ1.getPosition().y > window->getSize().y - maxRadius) {
        yDist = abs(circ2.getPosition().y - circ1.getPosition().y + window->getSize().y);
    }

    return calcDistance(xDist, yDist) <= maxRadius;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    ImGui::SFML::Init(window);

    std::vector<Particle> particlesVec;
    particlesVec.push_back(Particle());
    particlesVec.push_back(Particle());

    float circleMoveValue = .75f;
    float halfOfCircleRadius = particlesVec[0].getRadius() / 2;

    int particleChoice = 0;

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Settings");
        ImGui::End();

        // screen wrapping
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
        
        bool isInRadius = inRadius(particlesVec[0].getShape(), particlesVec[1].getShape(), &window);
        
        if (isInRadius) {
            for (auto& x : particlesVec)
                x.setFillColor(sf::Color::Green);
        }
        else if (!isInRadius) {
            for (auto& x : particlesVec)
                x.setFillColor(sf::Color(204, 77, 5));
        }

        window.clear(sf::Color(18, 33, 43));

        for (auto x : particlesVec)
            window.draw(x.getShape());

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
