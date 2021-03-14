#include "Platform/Platform.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>

std::vector<int> randomNumbers(int size, int max);
void sorter(std::vector<int>, sf::RenderWindow& window);

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "App is starting..." << std::endl;
#endif

	int N = 1024;
	sf::RenderWindow window;
	window.create(sf::VideoMode(N, N / 2), "Sorting visualizer");

	std::vector<int> arr = randomNumbers(N, N / 2 - 32);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		sorter(arr, window);
		window.close();
	}

	return 0;
}

std::vector<int> randomNumbers(int size, int max)
{
	std::vector<int> numbers;

	for (int i = 0; i < size; i++)
	{
		numbers.push_back(rand() % max);
	}

	return numbers;
}

void sorter(std::vector<int> numbers, sf::RenderWindow& window)
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