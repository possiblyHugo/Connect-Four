#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::CircleShape> circles;
    std::vector<sf::RectangleShape> bars;

    sf::RenderWindow window(sf::VideoMode(920, 720), "SFML works!");

    // Background
    sf::RectangleShape background(sf::Vector2f(920,720));
    background.setFillColor(sf::Color(255, 165, 0));

    // Vertical Bars
    sf::Vector2f barOffset(50.f,0);
    for (int i = 0; i < 5; ++i) {
        sf::RectangleShape bar(sf::Vector2f(100, 720));
        bar.setFillColor(sf::Color(245, 194, 66));

        bar.move(barOffset);
        barOffset += sf::Vector2f(200.f, 0);

        bars.push_back(bar);
    }

    // Horizontal

    // Circles


    sf::CircleShape shape(75.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(background);
        
        for (auto bar : bars) {
            window.draw(bar);
        }

        window.draw(shape);
        window.display();
    }

    return 0;
}