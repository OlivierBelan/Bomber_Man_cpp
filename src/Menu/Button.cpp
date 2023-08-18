/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Button
*/

#include "Button.hpp"

IndieStudio::Button::Button(IndieStudio::IGraphical &graphical, std::string skinDefault, std::string skinActive, std::pair<int, int> position)
	: _graphical(graphical), _active(false), _skinDefault(skinDefault), _skinActive(skinActive)
{
	this->_image = this->_graphical.createImage(_skinDefault, position);
}

IndieStudio::Button::~Button()
{
}

void IndieStudio::Button::drawButton(void) noexcept
{
	this->_graphical.drawImage(this->_image);
}

void IndieStudio::Button::setActiveSkin(void) noexcept
{
	this->_graphical.setSkin(this->_image, _skinActive);
}

void IndieStudio::Button::setDefaultSkin(void) noexcept
{
	this->_graphical.setSkin(this->_image, _skinDefault);
}
void IndieStudio::Button::setPosition(std::pair<int, int> pos) noexcept
{
	this->_graphical.set2DPos(this->_image, pos);
}