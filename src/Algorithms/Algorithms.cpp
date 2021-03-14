#include "Algorithms.hpp"
#include "unistd.h"

int partition(std::vector<int>& numbers, int start, int end);
void swap(std::vector<int>& numbers, int a, int b);

Algorithms::Algorithms()
{
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

		sf::VertexArray lines(sf::Lines);

		for (size_t k = 0; k < numbers.size(); k++)
		{
			if (k == i)
			{
				lines.append(sf::Vertex(sf::Vector2f(k, window.getSize().y), sf::Color(167, 255, 131, 255)));
				lines.append(sf::Vertex(sf::Vector2f(k, window.getSize().y - numbers[k]), sf::Color(167, 255, 131, 255)));
			}
			else if (k > i)
			{
				lines.append(sf::Vertex(sf::Vector2f(k, window.getSize().y), sf::Color(248, 89, 89, 255)));
				lines.append(sf::Vertex(sf::Vector2f(k, window.getSize().y - numbers[k]), sf::Color(248, 89, 89, 255)));
			}
			else
			{
				lines.append(sf::Vertex(sf::Vector2f(k, window.getSize().y)));
				lines.append(sf::Vertex(sf::Vector2f(k, window.getSize().y - numbers[k])));
			}
		}

		window.clear();
		window.draw(lines);
		window.display();
		usleep(2500);
	}
}

void Algorithms::quicksort(std::vector<int>& numbers, int start, int end, sf::RenderWindow& window)
{
	if (start >= end)
	{
		return;
	}

	int index = partition(numbers, start, end);
	quicksort(numbers, start, index - 1, window);
	quicksort(numbers, index + 1, end, window);
}

int partition(std::vector<int>& numbers, int start, int end)
{
	int index = start;
	int pivot = numbers[end];

	for (int i = start; i < end; i++)
	{
		if (numbers[i] < pivot)
		{
			swap(numbers, i, index);
			index++;
		}
	}

	swap(numbers, index, end);

	return index;
}

void swap(std::vector<int>& numbers, int a, int b)
{
	int temp = numbers[a];
	numbers[a] = numbers[b];
	numbers[b] = temp;
}
