#include "PinballTable.h"
#include "Ball.h"
#include "Vector.h"

#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pinball topview");
    
    Vector ballCenter = {0., 0., 0.};
    Vector ballSpeed = {0.1, 0.2, 0.3};
    Ball ball = {ballCenter, 0.1, ballSpeed};
    PinballTable table{"test.obj", ball};

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
        table.render(window);
		window.display();
	}

	return 0;
}