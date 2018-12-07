#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
		sf::Event event2;
        while (window.pollEvent(event))
        {
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					//move circle down
					
					shape.move(0, 5);
				}
				else if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
				{
					//move circle up
					shape.move(0, -5);
				}
				else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
				{
					//move circle left
					shape.move(-5, 0);
				}
				else if (event.key.code ==  sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					//move circ right
					shape.move(5, 0);
				}
				else if (event.key.code == sf::Keyboard::B)
				{
					shape.setFillColor(sf::Color::Cyan);
				}





				
				

			}
			if (event.type == sf::Event::LostFocus)
			{
		
				cout << "Game Paused" << endl;
				

			}
			if (event.type == sf::Event::GainedFocus)
			{
				if (event.type == sf::Event::KeyPressed)
				{
					cout << "Game Unpaused" << endl;
				}
			}

			

            if (event.type == sf::Event::Closed)
			{
				window.close();
			}

                
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}