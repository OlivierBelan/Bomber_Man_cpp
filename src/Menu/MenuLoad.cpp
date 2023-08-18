/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuLoad
*/

#include "MenuLoad.hpp"

IndieStudio::MenuLoad::MenuLoad(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(graphical, volume, sounds)
{
	this->_renderStatus = MENU_LOAD_MAIN;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuLoad::~MenuLoad()
{
}

void IndieStudio::MenuLoad::createButtons(void) noexcept
{
}

void IndieStudio::MenuLoad::drawButtons(void) noexcept
{
}

void IndieStudio::MenuLoad::createImages(void) noexcept
{
	this->_comingsoon = this->_graphical.createImage("assets/menu/yoshi.png", std::pair<int, int>(-1, 500));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuLoad::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_comingsoon);
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuLoad::checkActions(void) noexcept
{
}

void IndieStudio::MenuLoad::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuLoad::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_LOAD_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_LOAD_BACK)
		this->drawMenu();
}

void IndieStudio::MenuLoad::refreshSkin(void) noexcept
{
}

void IndieStudio::MenuLoad::returnAction(void) noexcept
{
}

void IndieStudio::MenuLoad::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_LOAD_BACK;
}

void IndieStudio::MenuLoad::leftAction(void) noexcept
{
}

void IndieStudio::MenuLoad::rightAction(void) noexcept
{
}

void IndieStudio::MenuLoad::upAction(void) noexcept
{
}

void IndieStudio::MenuLoad::downAction(void) noexcept
{
}

void IndieStudio::MenuLoad::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuLoad::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_LOAD_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_LOAD_BACK)
		this->escapeAction();
}

void IndieStudio::MenuLoad::leftActionManager(void) noexcept
{
}

void IndieStudio::MenuLoad::rightActionManager(void) noexcept
{
}

void IndieStudio::MenuLoad::upActionManager(void) noexcept
{
}

void IndieStudio::MenuLoad::downActionManager(void) noexcept
{
}

void IndieStudio::MenuLoad::alphaActionManager(IndieStudio::Key key) noexcept
{
}

void IndieStudio::MenuLoad::alphaAction(IndieStudio::Key key) noexcept
{
}