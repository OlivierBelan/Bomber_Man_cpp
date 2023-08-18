/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuSounds
*/

#include "MenuSounds.hpp"

IndieStudio::MenuSounds::MenuSounds(Volume *volume) : _volume(volume)
{
	this->_buttonReturnSound = this->_volume->createSoundEffect("sounds/menu/turnoff.ogg");
	this->_buttonSwitchSound = this->_volume->createSoundEffect("sounds/menu/tick.ogg");
	this->_volumeSwitchSound = this->_volume->createSoundEffect("sounds/menu/vol.ogg");
}

IndieStudio::MenuSounds::~MenuSounds()
{
}