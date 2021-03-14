#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

class Algorithms
{
public:
	Algorithms();
	void custom(std::vector<int> numbers, sf::RenderWindow& window);
	void quicksort(std::vector<int>& numbers, int start, int end, sf::RenderWindow& window);
};

#endif