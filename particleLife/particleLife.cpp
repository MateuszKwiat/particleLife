#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    ImGui::SFML::Init(window);

    bool circleExists = true;
    bool temp = true;
    float circleRadius = 200.f;
    int circleSegments = 100;
    sf::CircleShape shape(circleRadius, circleSegments);
    sf::CircleShape shape1(circleRadius, 3);
    sf::CircleShape shape2(circleRadius, 4);
    shape.setFillColor(sf::Color(204, 77, 5));
    shape.setOrigin(circleRadius, circleRadius);
    shape.setPosition(400, 400);

    shape1.setFillColor(sf::Color(204, 77, 5));
    shape1.setOrigin(circleRadius, circleRadius);
    shape1.setPosition(400, 400);

    shape2.setFillColor(sf::Color(204, 77, 5));
    shape2.setOrigin(circleRadius, circleRadius);
    shape2.setPosition(400, 400);

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

        static int e = 0;
        ImGui::RadioButton("Circle", &e, 0);
        ImGui::RadioButton("Triangle", &e, 1);
        ImGui::RadioButton("Square", &e, 2);
        ImGui::SliderFloat("Radius", &circleRadius, 100.f, 300.f);
        ImGui::SliderInt("Sides", &circleSegments, 3, 150);
        ImGui::End();

        shape.setRadius(circleRadius);
        shape.setOrigin(circleRadius, circleRadius);
        shape.setPointCount(circleSegments);

        shape1.setRadius(circleRadius);
        shape1.setOrigin(circleRadius, circleRadius);

        shape2.setRadius(circleRadius);
        shape2.setOrigin(circleRadius, circleRadius);

        window.clear(sf::Color(18, 33, 43));
        if (circleExists) {

            if (e == 0) {
                window.draw(shape);
            }
            else if (e == 1) {
                window.draw(shape1);
            }
            else {
                window.draw(shape2);
            }
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
