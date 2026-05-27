#pragma once
#include <SFML/Graphics.hpp>

class Player
{
private:
	sf::Texture texture;

	sf::Vector2f groundpos;
	sf::Vector2f scale;

	sf::RectangleShape playerBound;

	sf::IntRect currentFrame;

	sf::Clock aniClock;

	float speed;
	float jumpSpeed;

	float gravity;

	bool isGround;

	float playerPosX;
	float playerPosY;
	sf::Vector2f velocity;
	
public:
	Player();
	~Player();

	bool isjumping;

	int Xindex;
	int Yindex;

	sf::Sprite sprite;
	sf::Vector2f size;

	bool isGameOver;
public:
	void Initialise(sf::RectangleShape& baseRect);
	void Load();
	void Update(float deltaTime, sf::RectangleShape& baseRect, sf::RectangleShape& cactusBound, sf::Clock& clock);
	void Draw(sf::RenderWindow& window);
	void checkCollision(sf::RectangleShape& baseRect);
	void animation();
};