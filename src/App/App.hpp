#ifndef APP_HPP
#define APP_HPP

class App
{
public:
	App();
	void Run();

private:
	int N;
	std::vector<int> numbers;
	int* numArr;
	std::vector<int> randomNumbers(int size, int max);
	int* getRandomNumbers(int size, int max);
};

#endif