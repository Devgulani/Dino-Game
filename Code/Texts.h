#pragma once
#include <SFML/Graphics.hpp>

class Texts
{
private:
	sf::Font gameFont;
	sf::Text gameOverText;
	sf::Text closeText;

	float gameOverTextSize;
	float pauseTextSize;
	float closeTextSize;
	float scoreTextSize;

	int score;

	float scoretimer;
	float scoretime;

	bool ranOnce;
	
public:
	sf::Text pauseText;
	sf::Text scoreText;

public:
	void Initialise();
	void Load();
	void Update(float& deltatime);
	void Draw(sf::RenderWindow& window);
	void CloseTextDraw(sf::RenderWindow& window);
};