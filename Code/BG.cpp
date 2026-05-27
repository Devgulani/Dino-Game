#include "BG.h"
#include <iostream>

using namespace std;

void BG::Initialise()
{
	scale.x = 0.3;
	scale.y = 0.4;

	size.x = 1920;
	size.y = 1080;

	bgScrollSpeed = 0.02f;
}

void BG::Load()
{
	if (bgTexture.loadFromFile("Assets/Textures/Background/bg7.jpg"))
	{
		cout << "\nbg loaded\n";
		bgSprite1.setTexture(bgTexture);
		bgSprite1.setPosition(0, 0);

		bgSprite2.setTexture(bgTexture);
		bgSprite2.setPosition(bgSprite1.getGlobalBounds().width * scale.x, 0);

		bgSprite1.setTextureRect(sf::IntRect(0 * size.x, 0 * size.y, (size.x / scale.x), (size.y / scale.y)));
		bgSprite1.setScale(scale.x, scale.y);

		bgSprite2.setTextureRect(sf::IntRect(0 * size.x, 0 * size.y, (size.x / scale.x), (size.y / scale.y)));
		bgSprite2.setScale(scale.x, scale.y);
	}
	else
		cout << "\nbg failed\n";
}

void BG::Update(float& deltatime)
{
	bgSprite1.move(sf::Vector2f(-bgScrollSpeed * deltatime, 0));
	bgSprite2.move(sf::Vector2f(-bgScrollSpeed * deltatime, 0));

	if (bgSprite1.getPosition().x + bgSprite1.getGlobalBounds().width <=0)
	{
		bgSprite1.setPosition(bgSprite2.getPosition().x + bgSprite2.getGlobalBounds().width, 0);
	}

	if (bgSprite2.getPosition().x + bgSprite2.getGlobalBounds().width <= 0)
	{
		bgSprite2.setPosition(bgSprite1.getPosition().x + bgSprite1.getGlobalBounds().width, 0);
	}
}

void BG::Draw(sf::RenderWindow& window)
{
	window.draw(bgSprite1);
	window.draw(bgSprite2);
}