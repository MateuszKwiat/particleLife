#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

#include <cmath>

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
    float radius;
    sf::CircleShape shape;

public:
    Particle() : shape(10.f) {
        radius = 10.f;
        shape.setFillColor(sf::Color(204, 77, 5));
        shape.setOrigin(radius, radius);
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
};

float calcDistance(float xDistance, float yDistance) {
    return std::sqrt(pow(xDistance, 2) + pow(yDistance, 2));
}

bool inRadius(sf::CircleShape& circ1, sf::CircleShape circ2) {
    float xDist = circ1.getPosition().x - circ2.getPosition().x;
    float yDist = circ1.getPosition().y - circ2.getPosition().y;
    float distance = calcDistance(xDist, yDist);

    return distance <= 500.f ? true : false;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    ImGui::SFML::Init(window);

    float circleRadius = 20.f;
    float circleMoveValue = 1.f;
    int circleSegments = 100;
    int halfOfCircleRadius = static_cast<int>(circleRadius / 2);

    sf::CircleShape shape(circleRadius, circleSegments);
    shape.setFillColor(sf::Color(204, 77, 5));
    shape.setOrigin(circleRadius, circleRadius);
    shape.setPosition(400, 400);

    Particle particle;

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
        ImGui::End();

        // screen wrapping
        if (shape.getPosition().x > window.getSize().x + halfOfCircleRadius)
            shape.setPosition(-halfOfCircleRadius, shape.getPosition().y);
        else if (shape.getPosition().x < -halfOfCircleRadius)
            shape.setPosition(window.getSize().x + halfOfCircleRadius, shape.getPosition().y);
        if (shape.getPosition().y > window.getSize().y + halfOfCircleRadius)
            shape.setPosition(shape.getPosition().x, -halfOfCircleRadius);
        else if (shape.getPosition().y < -halfOfCircleRadius)
            shape.setPosition(shape.getPosition().x, window.getSize().y + halfOfCircleRadius);

        if (particle.getPosition().x > window.getSize().x)
            particle.setPosition(0, particle.getPosition().y);
        else if (particle.getPosition().x < 0)
            particle.setPosition(window.getSize().x, particle.getPosition().y);
        if (particle.getPosition().y > window.getSize().y)
            particle.setPosition(particle.getPosition().x, 0);
        else if (particle.getPosition().y < 0)
            particle.setPosition(particle.getPosition().x, window.getSize().y);


        // particle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            shape.setPosition(shape.getPosition().x - circleMoveValue, shape.getPosition().y);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            shape.setPosition(shape.getPosition().x + circleMoveValue, shape.getPosition().y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - circleMoveValue);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + circleMoveValue);

        particle.setPosition(particle.getPosition().x + .05f, particle.getPosition().y + .05f);
        
        bool isInRadius = inRadius(shape, particle.getShape());

        if (isInRadius) {
            shape.setFillColor(sf::Color::Red);
            particle.setFillColor(sf::Color::Red);
        }
        else if (!isInRadius) {
            shape.setFillColor(sf::Color(204, 77, 5));
            particle.setFillColor(sf::Color(204, 77, 5));
        }

        window.clear(sf::Color(18, 33, 43));
        window.draw(shape);
        window.draw(particle.getShape());
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
