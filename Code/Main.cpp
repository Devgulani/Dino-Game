#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Player.h"
#include "Ground.h"
#include "Cactus.h"
#include "BG.h"
#include "Texts.h"
#include "Sound.h"
#include "Buttons.h"

using namespace std;

int main()
{
	//INITIALISE
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dino Game", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	window.setFramerateLimit(120);
	sf::Event event;

	bool isPaused = false;
	bool isRestarting = false;

	BG bg;
	Player player;
	Ground ground;
	Cactus cactus;
	Texts texts;
	Sound sound;

	bg.Initialise();
	ground.Initialise();
	player.Initialise(ground.baseRect);
	cactus.Initialise();
	texts.Initialise();
	sound.Initialise();

	sf::Clock clock;
	sf::Clock soundClock;

	sf::Time soundTime;

	//INITIALISE
	//LOAD
	bg.Load();
	ground.Load();
	player.Load();
	cactus.Load();
	texts.Load();
	sound.Load();

	//LOAD


	//UPDATE
	while (window.isOpen())
	{
		sf::Time deltaTimeTimer = clock.restart();
		float deltaTime = deltaTimeTimer.asMilliseconds();
		int fps = 1000 / deltaTime;
		//cout << "\nfps: " << fps <<"frame time: "<< deltaTime;


		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

			break;

			case sf::Event::KeyPressed:

				if (event.key.code == sf::Keyboard::Delete)
				{
					window.close();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					isPaused = !isPaused;

				}
				if (event.key.code == sf::Keyboard::Space )
				{
					if (player.isGameOver == false)
					{
						if (soundClock.getElapsedTime().asSeconds() >= 0.5)
						{
							sound.JumpPlay();
							soundClock.restart();
						}
					}
				}
			break;
			}

		}

		if (player.isGameOver == false)
		{
			if (isPaused == false)
			{
				bg.Update(deltaTime);
				ground.Update(deltaTime);
				player.Update(deltaTime, ground.baseRect, cactus.cactusBound, clock);
				cactus.Update(deltaTime);
				sound.Update();

				if (player.isGameOver == true)
				{
					sound.GameOverPlay();
				}
				texts.Update(deltaTime);

			}
		}
		
	//DRAW

		window.clear();

		bg.Draw(window);

		if (isPaused == false && player.isGameOver == false)
		{
			window.draw(texts.scoreText);
		}

		ground.Draw(window);
		cactus.Draw(window);
		player.Draw(window);

		if (player.isGameOver == true)
		{
			texts.Draw(window);
			texts.CloseTextDraw(window);

		}

		if (isPaused == true && player.isGameOver == false)
		{
			window.draw(texts.pauseText);
		}
		
		window.display();

	//DRAW
	}
}