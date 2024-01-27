#include "App.h"
// for different settings of particles check if particles of type X can get faster (avg of all X)

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