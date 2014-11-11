#include "PinballTable.h"
#include "Ball.h"
#include "Vector.h"

#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pinball topview");
	sf::CircleShape circle(20.f);
	circle.setPointCount(500);
	circle.setFillColor(sf::Color::Green);
	

	sf::RectangleShape rectangle(sf::Vector2f(600, 400));
	rectangle.setFillColor(sf::Color::White);

    Vector ballCenter = {0., 0., 0.};
    Vector ballSpeed = {0.1, 0.2, 0.3};
    Ball ball = {ballCenter, 0.1, ballSpeed};
    PinballTable("test.obj", ball);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(circle);
		window.draw(rectangle);
		window.display();
	}

	return 0;
}