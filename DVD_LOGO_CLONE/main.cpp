#include<iostream>
#include<SFML/Graphics.hpp>

#define WIDTH	800
#define HEIGHT  800


/*

remainig problems

1- changing resolution is buggy because of the if statments
2- make a file that  reads input for the game


*/



void changeColor(sf::CircleShape& shape)
{
	shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, rand() % 255));
}

int main(int argc, char* argv[])
{

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Assignment 1", sf::Style::Default);

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


		if (x > 0 && y + circle.getLocalBounds().height > WIDTH)
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