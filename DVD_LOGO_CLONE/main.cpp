#include<iostream>
#include<SFML/Graphics.hpp>
#include<fstream>

/*

remainig problems

1- changing resolution is buggy because of the if statments
2- make a config file that  reads input for width and height

*/
#define CONFIG_FILE_PATH "bin/game.txt"

size_t WIDTH;
size_t HEIGHT;

bool loadGameConfig()
{
	std::ifstream in(CONFIG_FILE_PATH);
	
	if (!in.is_open())
	{
		std::cout << "Cannot open file"<<std::endl;
		return false;
	}

	std::string param;
	size_t value;

	while (!in.eof())
	{
		in >> param;
		in >> value;

		if (param == "WIDTH")
		{
			WIDTH = value;
		}
		else if (param == "HEIGHT")
		{
			HEIGHT = value;
		}

	}
	in.close();
	return true;
}



void changeColor(sf::CircleShape& shape)
{
	shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255));
}

int main(int argc, char* argv[])
{
	if (!loadGameConfig())
	{
		std::cout << "failed to read config";
		return EXIT_FAILURE;
	}
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DVD", sf::Style::Default);

	window.setFramerateLimit(60);

	sf::CircleShape circle(60.0f);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(400, 400);

	float circleMoveSpeedX = 6;
	float circleMoveSpeedY = 4;


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		circle.setPosition(circle.getPosition().x + circleMoveSpeedX, circle.getPosition().y + circleMoveSpeedY);

		float x = circle.getPosition().x;
		float y = circle.getPosition().y;


		if (x < 0 && y>0)
		{
			circleMoveSpeedX *= -1;
			std::cout << "1" << std::endl;
			
			changeColor(circle);
		}
		if (x + circle.getLocalBounds().width > WIDTH && y > 0)
		{
			circleMoveSpeedX *= -1;
			std::cout << "2" << std::endl;
			changeColor(circle);

		}

		if (x > 0 && y < 0)
		{
			circleMoveSpeedY *= -1;
			std::cout << "3" << std::endl;
			changeColor(circle);

		}


		if (x > 0 && y + circle.getLocalBounds().height > HEIGHT)
		{
			circleMoveSpeedY *= -1;
			std::cout << "4" << std::endl;
			changeColor(circle);

		}

		if ((x < 0 && y < 0) || (x + circle.getLocalBounds().width > WIDTH && y + circle.getLocalBounds().height > HEIGHT)
			|| (x + circle.getLocalBounds().width > WIDTH && y <= 0) || (x <0 && y + circle.getLocalBounds().height > HEIGHT))
		{
			circleMoveSpeedY *= -1;
			circleMoveSpeedX *= -1;

			std::cout << "5" << std::endl;
			changeColor(circle);

		}


		window.clear();


		window.draw(circle);
		window.display();


	}





}