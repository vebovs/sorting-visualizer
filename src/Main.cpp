#include "./App/App.hpp"

void quicksort(std::vector<int>& numbers, int start, int end);
int partition(std::vector<int>& numbers, int start, int end);
void swap(std::vector<int>& numbers, int a, int b);

int main()
{
	//App app = App();
	//app.Run();

	std::vector<int> numbers = { 5, 4, 8, 12, 3 };

	quicksort(numbers, 0, 4);

	for (int i = 0; i < 5; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	return 0;
}

void quicksort(std::vector<int>& numbers, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int index = partition(numbers, start, end);
	quicksort(numbers, start, index - 1);
	quicksort(numbers, index + 1, end);
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