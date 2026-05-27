#include "Sound.h"
#include <iostream>

using namespace std;

void Sound::Initialise()
{

}

void Sound::Load()
{
	if (!jumpBuffer.loadFromFile("Assets/Audio/Sounds/jump2.wav"))
	{
		cout << "error loading sound \n";
	}

	jumpSound.setBuffer(jumpBuffer);

	if (!gameOverBuffer.loadFromFile("Assets/Audio/Sounds/game over.wav"))
	{
		cout << "error loading sound \n";
	}

	gameOverSound.setBuffer(gameOverBuffer);
}

void Sound::Update()
{
}

void Sound::JumpPlay()
{
	jumpSound.play();
}

void Sound::GameOverPlay()
{
	gameOverSound.play();
}