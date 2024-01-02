#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include <cmath>
#include <vector>

// radius between two particles on opposite sides of screen
// solution (plane size 1920x1080):
// if |x1 - x2| < 1 or |x1 - x2| > 1919 and (same for y) -> calculate the forces
//        ^ case for       ^ case for 
//        distance in      distance when                |             |     in this case
//        the middle       one particle is        -->   |.           .|     they should
//        of screen        on the left and other        |             |     still attract
//                         on right etc.                |             |     each other

class Particle {
private:
    float radiusValue;
    sf::CircleShape shape;
    sf::CircleShape radiusOutline;

public:
    Particle() : shape(10.f), radiusOutline(200.f) {
        radiusValue = 10.f;
        shape.setFillColor(sf::Color(204, 77, 5));
        shape.setOrigin(radiusValue, radiusValue);
        shape.setPosition(200, 200);


        radiusOutline.setFillColor(sf::Color(255, 255, 255, 256));
        radiusOutline.setOrigin(200.f, 200.f);
        radiusOutline.setPosition(200, 200);
        radiusOutline.setOutlineColor(sf::Color::Red);
        radiusOutline.setOutlineThickness(2.f);
    }

    void setPosition(float x, float y) {
        shape.setPosition(x, y);
        radiusOutline.setPosition(x, y);
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

    sf::CircleShape getRadiusShape() {
        return radiusOutline;
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
        ImGui::SliderFloat("move value", &circleMoveValue, 0.f, 10.f);
        ImGui::RadioButton("particle 1", &particleChoice, 0);
        ImGui::RadioButton("particle 2", &particleChoice, 1);
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

        // particle movement
        int particleIndex = particleChoice ? 0 : 1;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            particlesVec[particleIndex].setPosition(particlesVec[particleIndex].getPosition().x - circleMoveValue,
                particlesVec[particleIndex].getPosition().y);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            particlesVec[particleIndex].setPosition(particlesVec[particleIndex].getPosition().x + circleMoveValue,
                particlesVec[particleIndex].getPosition().y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            particlesVec[particleIndex].setPosition(particlesVec[particleIndex].getPosition().x, 
                particlesVec[particleIndex].getPosition().y - circleMoveValue);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            particlesVec[particleIndex].setPosition(particlesVec[particleIndex].getPosition().x,
                particlesVec[particleIndex].getPosition().y + circleMoveValue);

        
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
            window.draw(x.getRadiusShape());
        for (auto x : particlesVec)
            window.draw(x.getShape());

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
