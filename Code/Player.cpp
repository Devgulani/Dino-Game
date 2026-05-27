#include "Player.h"
#include <iostream>

using namespace std;

Player::Player():  //constructor
	speed(0), jumpSpeed(0)
{ 
}

Player::~Player() //detructor
{
}

void Player::Initialise(sf::RectangleShape& baseRect)
{
	size.x = 64;
	size.y = 64;
	speed = 0.9f;
	jumpSpeed = 2.7f;
	groundpos.x = 0;
	groundpos.y = baseRect.getGlobalBounds().top;
	scale.x = 2;
	scale.y = 2;
	playerPosX = 500.f;
	playerPosY = groundpos.y - size.y * scale.y;

	gravity = 0.09f;

	velocity.x = 0;
	velocity.y = 0;

	isjumping = false;
	isGround = true;
	isGameOver = false;

	playerBound.setFillColor(sf::Color::Transparent);
	playerBound.setOutlineColor(sf::Color::Transparent);
	playerBound.setOutlineThickness(5.f);
	playerBound.setSize(sf::Vector2f(size.x * scale.x, size.y * scale.y));
	
}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Textures/Player/player.png"))
	{
		cout << "Texture loaded";
		sprite.setTexture(texture);
		
		Xindex = 0;
		Yindex = 7;


		sprite.setScale(scale.x, scale.y);

		sprite.setPosition(playerPosX, playerPosY);

		currentFrame = sf::IntRect(Xindex * size.x, Yindex * size.y, size.x, size.y);
		sprite.setTextureRect(currentFrame);

	}
	else
	{
		cout << "\nnot loaded\n";
	}
}

void Player::Update(float deltaTime, sf::RectangleShape& baseRect, sf::RectangleShape& cactusBound, sf::Clock& clock)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isjumping == false)
	{
		velocity.y = -jumpSpeed * deltaTime;
		isjumping = true;
		isGround = false;
	}
	else
		isGround = true;

	if (sprite.getPosition().y + size.y < groundpos.y || velocity.y < 0)  //gravity
	{
		velocity.y += gravity * deltaTime;
		isGround = false;
	}
	else
		isGround = true;

	animation();

	checkCollision(baseRect);

	sprite.move(velocity.x, velocity.y);

	playerBound.setPosition(sprite.getPosition());

	if (sprite.getGlobalBounds().intersects(cactusBound.getGlobalBounds())) //collision of player and Cactus
	{
		//sprite.setColor(sf::Color::Transparent);
		isGameOver = true;
	}

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerBound);
	window.draw(sprite);

}


void Player::checkCollision(sf::RectangleShape& baseRect)
{
	if (sprite.getGlobalBounds().intersects(baseRect.getGlobalBounds()))  //collision of player and ground
	{
		sprite.setPosition(sprite.getPosition().x, groundpos.y - (size.y * scale.y));
		velocity.y = 0;																				
		isjumping = false;
		isGround = true;
	}
	else
		isGround = true;

}

void Player::animation()
{
	if (aniClock.getElapsedTime().asSeconds() >= 0.08f)
	{
		currentFrame.left += 64;
		if (currentFrame.left > 448)
		{
			currentFrame.left = 0;
		}
		aniClock.restart();
		sprite.setTextureRect(currentFrame);
	}
}
