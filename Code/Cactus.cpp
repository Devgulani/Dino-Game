#include "Cactus.h"

void Cactus::Initialise()
{
	cacSize.x = 100.f;
	cacSize.y = 90.f;

	cacPos.x = 0;
	cacPos.y = 835;

	scale.x = -0.6;
	scale.y = 0.8;

	speed = 0.4f;
	spawnTimer = 0.f;
	spawnInterval = 3300.f;

	cactusBound.setFillColor(sf::Color::Transparent);
	cactusBound.setOutlineColor(sf::Color::Transparent);
	cactusBound.setOutlineThickness(5.f);
	cactusBound.setSize(sf::Vector2f(cacSize.x * scale.x, cacSize.y * scale.y));
}

void Cactus::Load()
{
	if (cacTexture.loadFromFile("Assets/Textures/Cactus/cactus.png"))
	{
		cout << "Cactus loaded\n";

		cacbaseSprite.setTexture(cacTexture);
		cacbaseSprite.setTextureRect(sf::IntRect(0 * cacSize.x, 0 * cacSize.y, cacSize.x, cacSize.y));
		cacbaseSprite.setPosition(sf::Vector2f(500, cacPos.y - cacSize.y));
		cacbaseSprite.setScale(scale.x, scale.y);

		lastElement = cactusVect.size() - 1;

		cout << "cactus vect size = " << cactusVect.size() << "\n";
	}
	else
		cout << "cactus failed to load";
}

void Cactus::Update(float& deltaTime)
{
	spawnTimer += deltaTime;

	if (spawnTimer >= spawnInterval)
	{
		spawnCacti();
		spawnTimer = 0.f;
	}

	for (auto& cactus : cactusVect)
	{
		currentPosX = cactus.getPosition().x;
		currentPosY = cactus.getPosition().y;
		cactus.setPosition(currentPosX - (speed * deltaTime), currentPosY);
		cactusBound.setPosition(cactus.getPosition());
		int cacvectsize = cactusVect.size();

	}

	//cactusBound.setPosition(currentPosX,currentP);
	removeCacti();
}

void Cactus::Draw(sf::RenderWindow& window)
{
	if (!cactusVect.empty())
	{
		for (const auto& cactus : cactusVect)
		{
			window.draw(cactus);

		}
	}
	window.draw(cactusBound);
}

void Cactus::spawnCacti()
{
	sf::Sprite newCactus = cacbaseSprite;
	newCactus.setPosition(1920, cacPos.y - cacSize.y);
	cactusVect.push_back(newCactus);
}

void Cactus::removeCacti()
{
	//cactusVect.erase(std::remove_if
	//(cactusVect.begin(), cactusVect.end(), 
	//	[](const sf::Sprite& cactus) 
	//{
	//		return cactus.getPosition().x < -100.f;
	//}),
	//	cactusVect.end()
	//);

	for (int i = 0; i < cactusVect.size();i++)
	{
		if (cactusVect[i].getPosition().x < -100)
		{
			cactusVect.erase(cactusVect.begin() + i);
			i--;
		}
	}
}
