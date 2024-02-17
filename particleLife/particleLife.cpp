#include "App.h"

// **************************   TODO: make tests for all particles combinations    **************************

int main() {
    App app;

    while (app.running())
        app.render();
}

/*

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

*/