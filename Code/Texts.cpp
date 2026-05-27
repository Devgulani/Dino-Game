#include "Texts.h"
#include <iostream>

using namespace std;

void Texts::Initialise()
{
	gameOverTextSize = 300;
	pauseTextSize = 300;

	scoreTextSize = 100;
	score = 0;

	scoretimer = 0;
	scoretime = 6600;

	ranOnce = true;

	closeTextSize = 100;
}

void Texts::Load()
{
	if (gameFont.loadFromFile("Assets/Fonts/Pixel Game.otf"))
	{
		cout << "\n font loaded \n";
		gameOverText.setOutlineColor(sf::Color::Black);
		gameOverText.setOutlineThickness(5);
		gameOverText.setOrigin(sf::Vector2f(gameOverTextSize / 2, gameOverTextSize / 2));
		gameOverText.setFont(gameFont);
		gameOverText.setCharacterSize(gameOverTextSize);
		gameOverText.setString("GAME OVER!");
		gameOverText.setStyle(sf::Text::Bold);
		gameOverText.setPosition(sf::Vector2f(510, 500));
	}
	else
		cout << "\nFont not loaded\n";

	pauseText.setOutlineColor(sf::Color::Black);
	pauseText.setOutlineThickness(5);
	pauseText.setOrigin(sf::Vector2f(pauseTextSize / 2, pauseTextSize / 2));
	pauseText.setFont(gameFont);
	pauseText.setCharacterSize(pauseTextSize);
	pauseText.setString("Paused!");
	pauseText.setStyle(sf::Text::Bold);
	pauseText.setPosition(sf::Vector2f(680, 500));

	scoreText.setOutlineColor(sf::Color::Black);
	scoreText.setOutlineThickness(5);
	scoreText.setOrigin(sf::Vector2f(scoreTextSize / 2, scoreTextSize / 2));
	scoreText.setFont(gameFont);
	scoreText.setCharacterSize(scoreTextSize);
	scoreText.setPosition(sf::Vector2f(80, 50));

	closeText.setOutlineColor(sf::Color::Black);
	closeText.setOutlineThickness(5);
	closeText.setFont(gameFont);
	closeText.setCharacterSize(closeTextSize);
	closeText.setString("Press Delete Button to Close");
	closeText.setPosition(sf::Vector2f(425, 600));
}

void Texts::Update(float& deltatime)
{
	scoreText.setString(to_string(score));

	scoretimer += deltatime;

	if (scoretimer > scoretime)
	{
		scoreText.setString(to_string(score));

		score += 1;
		scoretimer = 0;

		if (ranOnce == true)
		{
			scoretime = 3300;
			ranOnce = false;
		}
	}
}

void Texts::Draw(sf::RenderWindow& window)
{
	window.draw(gameOverText);
}

void Texts::CloseTextDraw(sf::RenderWindow& window)
{
	window.draw(closeText);
}