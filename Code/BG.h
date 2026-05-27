#pragma once
#include <SFML/Graphics.hpp>

class BG
{
private:
	sf::Texture bgTexture;
	sf::Sprite bgSprite1;
	sf::Sprite bgSprite2;
	sf::Vector2i size;
	sf::Vector2f scale;

	float bgScrollSpeed;
public:
	void Initialise();
	void Load();
	void Update(float& deltaTime);
	void Draw(sf::RenderWindow& window);
};