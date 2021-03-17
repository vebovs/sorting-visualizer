#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

class Algorithms
{
public:
	Algorithms(int bar_width);
	void custom(std::vector<int> numbers, sf::RenderWindow& window);
	void quicksort(std::vector<int>& numbers, int start, int end, sf::RenderWindow& window);

private:
	int bar_width;
	int partition(std::vector<int>& numbers, int start, int end, sf::RenderWindow& window);
	void swap(std::vector<int>& numbers, int a, int b, int pivot, sf::RenderWindow& window);
};

#endif