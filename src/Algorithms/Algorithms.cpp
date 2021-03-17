#include "Algorithms.hpp"
#include "unistd.h"

int timeout = 2500;

Algorithms::Algorithms(int bar_width)
{
	this->bar_width = bar_width;
}

void Algorithms::custom(std::vector<int> numbers, sf::RenderWindow& window)
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

		std::vector<sf::RectangleShape> lines;

		for (size_t k = 0; k < numbers.size(); k++)
		{
			sf::RectangleShape line(sf::Vector2f(this->bar_width, -numbers[k]));

			if (k == i)
			{
				line.setFillColor(sf::Color(167, 255, 131, 255));
			}
			else if (k > i)
			{
				line.setFillColor(sf::Color(248, 89, 89, 255));
			}
			else
			{
				line.setFillColor(sf::Color(255, 255, 255, 255));
			}

			line.setPosition(this->bar_width * k, window.getSize().y);
			lines.push_back(line);
		}

		window.clear();

		for (auto& line : lines)
		{
			window.draw(line);
		}

		window.display();
		usleep(timeout);
	}
}

void Algorithms::quicksort(std::vector<int>& numbers, int start, int end, sf::RenderWindow& window)
{
	if (start >= end)
	{
		return;
	}

	int index = partition(numbers, start, end, window);
	quicksort(numbers, start, index - 1, window);
	quicksort(numbers, index + 1, end, window);
}

int Algorithms::partition(std::vector<int>& numbers, int start, int end, sf::RenderWindow& window)
{
	int index = start;
	int pivot = numbers[end];

	for (int i = start; i < end; i++)
	{
		if (numbers[i] < pivot)
		{
			swap(numbers, i, index, pivot, window);
			index++;
		}
	}

	swap(numbers, index, end, pivot, window);

	return index;
}

void Algorithms::swap(std::vector<int>& numbers, int a, int b, int pivot, sf::RenderWindow& window)
{
	int temp = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = temp;

	std::vector<sf::RectangleShape> lines;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		sf::RectangleShape line(sf::Vector2f(this->bar_width, -numbers[i]));

		if (numbers[i] == pivot)
		{
			line.setFillColor(sf::Color(167, 255, 131, 255));
		}
		else if (numbers[i] > pivot)
		{
			line.setFillColor(sf::Color(248, 89, 89, 255));
		}

		line.setPosition(this->bar_width * i, window.getSize().y);
		lines.push_back(line);
	}

	window.clear();

	for (auto& line : lines)
	{
		window.draw(line);
	}

	window.display();
	usleep(timeout);
}
