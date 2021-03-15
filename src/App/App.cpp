#include "App.hpp"
#include "../Algorithms/Algorithms.hpp"
#include "../Platform/Platform.hpp"
#include <unistd.h>
#include <vector>

App::App()
{
	this->N = 1000;
	this->numbers = randomNumbers(250, N / 2 - 32);
}

std::vector<int> App::randomNumbers(int size, int max)
{
	std::vector<int> numbers;

	for (int i = 0; i < size; i++)
	{
		numbers.push_back(rand() % max);
	}

	return numbers;
}

void App::Run()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "App is starting..." << std::endl;
#endif

	sf::RenderWindow window;
	window.create(sf::VideoMode(this->N, this->N / 2), "Sorting visualizer");

	sf::Event event;

	Algorithms algo = Algorithms();

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//algo.custom(this->numbers, window);
		algo.quicksort(numbers, 0, static_cast<int>(this->numbers.size()) - 1, window);
		window.close();
	}
}