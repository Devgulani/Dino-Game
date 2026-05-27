#pragma once
#include <SFML/Graphics.hpp>


class Ground
{
private:
	sf::Texture texture;

	int Xindex;
	int Yindex;

	sf::Vector2i size;
	sf::Vector2f gPos;
	sf::Vector2f gScale;

	float gScrollSpeed;
public:
	sf::RectangleShape baseRect;

	sf::Texture gTexture;
	sf::Sprite gSprite1;
	sf::Sprite gSprite2;

public:
	void Initialise();
	void Load();
	void Update(float& deltatime);
	void Draw(sf::RenderWindow& window);
};