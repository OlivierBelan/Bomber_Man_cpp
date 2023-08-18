/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Volume
*/

#include "Volume.hpp"

IndieStudio::Volume::Volume()
{
}

IndieStudio::Volume::~Volume()
{
}

int IndieStudio::Volume::getVolumeMusics(void) const noexcept
{
	return this->_volumeMusics;
}

int IndieStudio::Volume::getVolumeEffects(void) const noexcept
{
	return this->_volumeEffects;
}

void IndieStudio::Volume::setVolumeMusics(int newVolume) noexcept
{
	this->_volumeMusics = newVolume;
	if (this->_volumeMusics > 100)
		this->_volumeMusics = 100;
	else if (this->_volumeMusics < 0)
		this->_volumeMusics = 0;
	this->refreshVolumeMusics();
}

void IndieStudio::Volume::setVolumeEffects(int newVolume) noexcept
{
	this->_volumeEffects = newVolume;
	if (this->_volumeEffects > 100)
		this->_volumeEffects = 100;
	else if (this->_volumeEffects < 0)
		this->_volumeEffects = 0;
	this->refreshVolumeEffects();
}

void IndieStudio::Volume::refreshVolumeMusics(void) noexcept
{
	for (auto i = this->_soundsMusics.begin(); i != this->_soundsMusics.end(); i++)
		(*i)->setVolume(this->_volumeMusics);
}

void IndieStudio::Volume::refreshVolumeEffects(void) noexcept
{
	for (auto i = this->_soundsEffects.begin(); i != this->_soundsEffects.end(); i++)
		(*i)->setVolume(this->_volumeEffects);
}

void IndieStudio::Volume::refreshVolume(void) noexcept
{
	this->refreshVolumeMusics();
	this->refreshVolumeEffects();
}

IndieStudio::Audio *IndieStudio::Volume::createSoundMusic(std::string path, bool loop) noexcept
{
	Audio *music = new IndieStudio::Audio(path, loop);
	this->_soundsMusics.push_back(music);
	return this->_soundsMusics.back();
}

IndieStudio::Audio *IndieStudio::Volume::createSoundEffect(std::string path, bool loop) noexcept
{
	Audio *effect = new IndieStudio::Audio(path, loop);
	this->_soundsEffects.push_back(effect);
	return this->_soundsEffects.back();
}