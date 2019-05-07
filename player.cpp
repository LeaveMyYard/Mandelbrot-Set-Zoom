#include "pch.h"
#include <SFML/Graphics.hpp>

int main()
{

	const unsigned int W = 1920;
	const unsigned int H = 1080; // you can change this to full window size later

	sf::RenderWindow window(sf::VideoMode(W, H), "Mandelbrot Set Zoom!", sf::Style::Fullscreen);
	window.setFramerateLimit(30);

	int iter = 1, step = 1;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Texture texture;
		std::string load = ("pic/set" + std::to_string(iter) + ".png");
		if (!texture.loadFromFile(load)) {
			step *= -1;
			iter--;
			continue;
		}

		sf::Sprite sprite(texture); // needed to draw the texture on screen

		window.clear();
		window.draw(sprite);
		window.display();
		iter+=step;
		if (iter < 1) {
			step *= -1;
			iter = 1;
		}
	}

	return 0;
}