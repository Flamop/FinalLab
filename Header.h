#pragma once
#include "SFML/Graphics.hpp"

namespace FL
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const int NUM_BALLS = 10;

	struct Ball {
	public:


		sf::CircleShape shape;
		sf::Vector2f velocity;

		Ball(float x, float y) {
			shape.setPosition(x, y);
			shape.setRadius(50.0f);
			shape.setFillColor(sf::Color::Red);
			velocity = sf::Vector2f(100.0f, 100.0f);
		}

		// Обновление состояния шарика
		void update(float dt, std::vector<Ball>& balls) {
			shape.move(velocity * dt);

			// Обработка столкновений с границами окна
			sf::Vector2f pos = shape.getPosition();
			if (pos.x < 0) {
				velocity.x = std::abs(velocity.x);
			}
			if (pos.x + shape.getRadius() * 2 > WINDOW_WIDTH) {
				velocity.x = -std::abs(velocity.x);
			}
			if (pos.y < 0) {
				velocity.y = std::abs(velocity.y);
			}
			if (pos.y + shape.getRadius() * 2 > WINDOW_HEIGHT) {
				velocity.y = -std::abs(velocity.y);
			}

			for (auto& other : balls) {
				if (&other == this) { continue; }; // Игнорируем столкновения с самим собой

				// Проверяем, сталкиваются ли шарики
				float distance = std::sqrt(std::pow(other.shape.getPosition().x - shape.getPosition().x, 2) + std::pow(other.shape.getPosition().y - shape.getPosition().y, 2));
				if (distance < shape.getRadius() + other.shape.getRadius()) {
					// Обмениваем скорости шариков
					sf::Vector2f temp = velocity;
					velocity = other.velocity;
					other.velocity = temp;
				};
			};
		};
	};
};
