/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MusicManager
*/

#include "MusicManager.hpp"

IndieStudio::MusicManager::MusicManager(Volume *volume) : _volume(volume)
{
	srand(time(NULL));
	int choice = rand() % 3;
	this->_menuMusic = this->_volume->createSoundMusic("sounds/menu/Stillness2.ogg", true);
	if (choice == 0)
		this->_gameMusic = this->_volume->createSoundMusic("sounds/game/gravity.ogg", true);
	else if (choice == 1)
		this->_gameMusic = this->_volume->createSoundMusic("sounds/game/kid.ogg", true);
	else
		this->_gameMusic = this->_volume->createSoundMusic("sounds/game/rayman.ogg", true);
}

IndieStudio::MusicManager::~MusicManager()
{
}

void IndieStudio::MusicManager::refreshMusic(Render &render) noexcept
{
	if (render == MAIN_MENU || render == PAUSE_MENU)
	{
		if (this->_menuMusic->getSoundStatus() == 0 || this->_menuMusic->getSoundStatus() == 1)
			this->_menuMusic->playSound();
		if (this->_gameMusic->getSoundStatus() == 2)
			this->_gameMusic->pauseSound();
	}
	else
	{
		if (this->_menuMusic->getSoundStatus() == 2)
			this->_menuMusic->pauseSound();
		if (this->_gameMusic->getSoundStatus() == 0 || this->_gameMusic->getSoundStatus() == 1)
			this->_gameMusic->playSound();
	}
}
