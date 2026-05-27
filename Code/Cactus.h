#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;

class Cactus
{
private:
	sf::Texture cacTexture;
	sf::Sprite cacbaseSprite;
	sf::Vector2f cacSize;
	sf::Vector2f cacScale;
	sf::Vector2f cacPos;
	sf::Vector2f scale;

	float speed;
	float spawnTimer;
	float spawnInterval;

	float currentPosX;
	float currentPosY;

public:
	int lastElement;

	std::vector <sf::Sprite> cactusVect;
	sf::RectangleShape cactusBound;
public:
	void Initialise();
	void Load();
	void Update(float& deltaTime);
	void Draw(sf::RenderWindow& window);
	void spawnCacti();
	void removeCacti();
};