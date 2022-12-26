#include "Header.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(FL::WINDOW_WIDTH, FL::WINDOW_HEIGHT), "Ball Simulation");

	std::vector<FL::Ball> balls;
	for (int i = 0; i < FL::NUM_BALLS; i++) {
		balls.emplace_back(float(std::rand() % FL::WINDOW_WIDTH), float(std::rand() % FL::WINDOW_HEIGHT));
	}

	sf::Clock clock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		float dt = clock.restart().asSeconds();
		for (auto& ball : balls) {
			ball.update(dt, balls);
		}

		window.clear();
		for (auto& ball : balls) {
			window.draw(ball.shape);
		}
		window.display();
	}

	return 0;
}