#include "Algorithms.hpp"
#include "unistd.h"

Algorithms::Algorithms()
{}

void Algorithms::sorter(std::vector<int> numbers, sf::RenderWindow& window)
{
	for (size_t i = 0; i < numbers.size(); i++)
	{
		int lowestSoFar = i;
		for (size_t j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[j] < numbers[lowestSoFar])
				lowestSoFar = j;
		}
		int temp = numbers[lowestSoFar];
		numbers[lowestSoFar] = numbers[i];
		numbers[i] = temp;

		sf::VertexArray lines(sf::Lines);

		for (size_t i = 0; i < numbers.size(); i++)
		{
			lines.append(sf::Vertex(sf::Vector2f(i, window.getSize().y)));
			lines.append(sf::Vertex(sf::Vector2f(i, window.getSize().y - numbers[i])));
		}

		window.clear();
		window.draw(lines);
		window.display();
		usleep(2500);
	}
}