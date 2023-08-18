/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Audio
*/

#include "Audio.hpp"

IndieStudio::Audio::Audio(std::string audioPath, bool loop)
{
	if (!this->_soundBuffer.loadFromFile(audioPath))
		exit(84);
	this->_sound.setBuffer(this->_soundBuffer);
	if (loop)
		this->_sound.setLoop(true);
}

IndieStudio::Audio::~Audio()
{
}

void IndieStudio::Audio::playSound(bool forced) noexcept
{
	if (this->_sound.getStatus() != sf::SoundSource::Status::Playing || forced)
		this->_sound.play();
}

void IndieStudio::Audio::stopSound() noexcept
{
	this->_sound.stop();
}

void IndieStudio::Audio::pauseSound() noexcept
{
	this->_sound.pause();
}

int IndieStudio::Audio::getSoundStatus(void) const noexcept
{
	return this->_sound.getStatus();
}

void IndieStudio::Audio::setVolume(int newVolume) noexcept
{
	this->_sound.setVolume(newVolume);
}

float IndieStudio::Audio::getVolume(void) const noexcept
{
	return this->_sound.getVolume();
}