#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "App starting..." << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	window.create(sf::VideoMode(512, 512), "Sorting visualizer", sf::Style::Close);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}

	return 0;
}