#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

int solve(int a, int b, int x);

void drawFunctionGraph(double a, double b) {
	// Create a window to draw the graph
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Function Graph");
	window.setFramerateLimit(60);

	// Define the origin of the graph in pixels
	sf::Vector2f origin(640, 240);

	// Define the scale for the x and y values
	double xScale = 30;
	double yScale = 30;
		
	// Loop through the x values within the given range
	for (double x = -100; x <= 100; x++) {	
	
		// Convert the x and y values to pixels
		sf::Vector2f point(x + origin.x, -solve(a,b,x) + origin.y);
	
		// Draw a point at the current x and y values
		sf::CircleShape shape(2);
		shape.setFillColor(sf::Color::Cyan);
		shape.setPosition(point);
		window.draw(shape);
	}

	// Display the window
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.display();
	}
}

int main() {
	char func[10] = {0};
	std::cout << "Enter the function: ";
	std::cin.getline(func, 10);

	//int x = 0;
	//std::cin >> x;

	for(int i = 0; i < sizeof(func);i++)
	{
		switch (func[i])
		{
		case 'x':
			func[i] = { 0 };
			break;
		case '+':
			func[i] = { 0 };
			break;
		
		default:
			break;
		}
	}

	int a = 0;
	int b = 0;

	if (func[1] != 0) {
		auto a3 = std::string(1, func[0]) + func[1];
		std::cout << "a = " << a3 << std::endl;
		a = std::stoi(a3);
	}
	else {
		a = (func[0] - 48);
	}

	if (func[3] == 0) {
		if (func[5] != 0) {
			auto b3 = std::string(1, func[4]) + func[5];
			std::cout << "b = " << b3 << std::endl;
			b = std::stoi(b3);
		}
		else {
			b = func[4] - 48;
		}
	}
	else {
		if (func[3] != 0 && func[4] != 0) {
			auto b3 = std::string(1, func[3]) + func[4];
			std::cout << "b = " << b3 << std::endl;
			b = std::stoi(b3);
		}
		else {
			b = func[3] - 48;
		}
	}

	for (int x = -100; x <= 100; x++) {
		std::cout << "x = " << x << " | y = " << solve(a, b, x) << std::endl;
	}

	drawFunctionGraph(a, b);

	system("pause");
	return 0;
}

int solve(int a, int b, int x) {
	return a * x + b;
}