#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 900), "SFML works!");
    ImGui::SFML::Init(window);

    float circleRadius = 20.f;
    int circleSegments = 100;

    sf::CircleShape shape(circleRadius, circleSegments);
    shape.setFillColor(sf::Color(204, 77, 5));
    shape.setOrigin(circleRadius, circleRadius);
    shape.setPosition(400, 400);

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

        // particle movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            shape.setPosition(shape.getPosition().x - 1, shape.getPosition().y);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            shape.setPosition(shape.getPosition().x + 1, shape.getPosition().y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            shape.setPosition(shape.getPosition().x, shape.getPosition().y - 1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            shape.setPosition(shape.getPosition().x, shape.getPosition().y + 1);

        window.clear(sf::Color(18, 33, 43));
        window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
