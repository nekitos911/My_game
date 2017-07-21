#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

int main()
{
    //Initialize a window
    RenderWindow window (VideoMode(640,480),"First_lesson");

    // Creating playerSprite
    Texture playerTexture;
    playerTexture.loadFromFile("Media/Images/Mushroom.png");
    Vector2u size = playerTexture.getSize();
    Sprite player (playerTexture);
    player.setOrigin(size.x / 2,size.y / 2);
    player.setPosition(320,240);

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
        window.draw(player);
        window.display();

    }

    return 0;
}
