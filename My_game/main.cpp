#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

int main()
{
    //Initialize a window
    RenderWindow window (VideoMode(640,480),"First_lesson");

    // Creating rectangle
    RectangleShape rectangle(Vector2f(128.0f,128.0f));
    rectangle.setFillColor(Color::Red);
    rectangle.setPosition(320,240);
    rectangle.setOrigin(rectangle.getSize().x / 2,rectangle.getSize().y);

    // Game loop
    while (window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed)
                // close the window
                window.close();
        }

        window.clear(Color::Black);
        // Draw here
        window.draw(rectangle);
        window.display();

    }

    return 0;
}
