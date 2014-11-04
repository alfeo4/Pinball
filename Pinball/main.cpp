#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pinball topview");
	sf::CircleShape circle(20.f);
	circle.setPointCount(500);
	circle.setFillColor(sf::Color::Green);
	
	sf::RectangleShape rectangle(sf::Vector2f(600, 400));
	rectangle.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(rectangle);
		window.draw(circle);
		window.display();
	}

	return 0;
}