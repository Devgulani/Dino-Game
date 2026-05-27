#pragma once
#include <SFML/Audio.hpp>

class Sound
{
private:
	sf::SoundBuffer jumpBuffer;
	sf::Sound jumpSound;

	sf::SoundBuffer gameOverBuffer;
	sf::Sound gameOverSound;

public:

public:
	void Initialise();
	void Load();
	void Update();
	void JumpPlay();
	void GameOverPlay();
};