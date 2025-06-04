#include <SFML/Graphics.hpp>

int main()
{
    // Create the window with resolution 1920x1080 and title
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Green Circle Example");
    window.setFramerateLimit(144);

    // Create a circle shape with radius 100 pixels
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);  // Set color to green

    // Position circle in the center of the window
    circle.setPosition({ (1920.f - circle.getRadius() * 2) / 2, (1080.f - circle.getRadius() * 2) / 2 });

    const int gravity = 9.81;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);  // Clear window with black color
        window.draw(circle);              // Draw the green circle
        window.display();                // Display the frame
    }

    return 0;
}
