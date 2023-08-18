/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#include "Menu.hpp"

IndieStudio::Menu::Menu(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config) : _graphical(graphical)
{
	this->_config = config;
	this->_volume = volume;
	this->_sounds = sounds;
}

void IndieStudio::Menu::setButtonSwitch(int incrementation, int nbrOfButtons) noexcept
{
	this->_buttonStatus += incrementation;
	if (this->_buttonStatus > nbrOfButtons)
		this->_buttonStatus = 0;
	else if (this->_buttonStatus < 0)
		this->_buttonStatus = nbrOfButtons;
}

void IndieStudio::Menu::setMenuActive(int newMenuStatus) noexcept
{
	this->_renderStatus = newMenuStatus;
}

int IndieStudio::Menu::getCurrentMenuActive(void) const noexcept
{
	return this->_renderStatus;
}

void IndieStudio::Menu::setButtonActive(int newButtonStatus) noexcept
{
	this->_buttonStatus = newButtonStatus;
}

int IndieStudio::Menu::getCurrentButtonActive(void) const noexcept
{
	return this->_buttonStatus;
}