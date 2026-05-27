#include "ground.h"
#include <iostream>

void Ground::Initialise()
{
	baseRect.setPosition(sf::Vector2f(0, 835.f));
	baseRect.setSize(sf::Vector2f(1920.f, 10.f));
	baseRect.setFillColor(sf::Color::Transparent);

	gPos.x = 0;
	gPos.y = 780;

	gScrollSpeed = 0.4f;

	gScale.x = 1;
	gScale.y = 1.5;
}

void Ground::Load()
{
	if (!gTexture.loadFromFile("Assets/Textures/Others/ground 1.png"))
	{
		std::cout << "fly not loaded";
	}
		size.x = 1920;
		size.y = 250;
	
		gSprite1.setTexture(gTexture);
		gSprite1.setPosition(gPos.x, gPos.y);

		gSprite2.setTexture(gTexture);
		gSprite2.setPosition(gSprite1.getPosition().x + gSprite1.getGlobalBounds().width - 100 , gPos.y);

		gSprite1.setTextureRect(sf::IntRect(0 * size.x, 0 * size.y, size.x, size.y));
		gSprite2.setTextureRect(sf::IntRect(0 * size.x, 0 * size.y, size.x, size.y));

		gSprite1.setScale(gScale.x, gScale.y);
		gSprite2.setScale(gScale.x, gScale.y);

}

void Ground::Update(float& deltatime)
{

	gSprite1.move(-gScrollSpeed * deltatime , 0);
	gSprite2.move(-gScrollSpeed * deltatime, 0);

	if (gSprite1.getPosition().x + gSprite1.getGlobalBounds().width <=0)
	{
		gSprite1.setPosition(gSprite2.getPosition().x + gSprite2.getGlobalBounds().width, gPos.y);
	}

	if (gSprite2.getPosition().x + gSprite2.getGlobalBounds().width <= 0)
	{
		gSprite2.setPosition(gSprite1.getPosition().x + gSprite1.getGlobalBounds().width, gPos.y);
	}
}

void Ground::Draw(sf::RenderWindow& window)
{
	window.draw(baseRect);
	window.draw(gSprite1);
	window.draw(gSprite2);
}

