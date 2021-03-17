#ifndef APP_HPP
#define APP_HPP

class App
{
public:
	App();
	void Run();

private:
	int N;
	int number_of_bars;
	std::vector<int> numbers;
	std::vector<int> randomNumbers(int size, int max);
};

#endif