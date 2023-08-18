/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuRestart
*/

#include "MenuRestart.hpp"

IndieStudio::MenuRestart::MenuRestart(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(graphical, volume, sounds)
{
	this->_renderStatus = MENU_RESTART_MAIN;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuRestart::~MenuRestart()
{
}

void IndieStudio::MenuRestart::createButtons(void) noexcept
{
}

void IndieStudio::MenuRestart::drawButtons(void) noexcept
{
}

void IndieStudio::MenuRestart::createImages(void) noexcept
{
	this->_comingsoon = this->_graphical.createImage("assets/menu/comingsoon.png", std::pair<int, int>(-1, 500));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuRestart::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_comingsoon);
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuRestart::checkActions(void) noexcept
{
}

void IndieStudio::MenuRestart::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuRestart::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_RESTART_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_RESTART_BACK)
		this->drawMenu();
}

void IndieStudio::MenuRestart::refreshSkin(void) noexcept
{
}

void IndieStudio::MenuRestart::returnAction(void) noexcept
{
}

void IndieStudio::MenuRestart::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_RESTART_BACK;
}

void IndieStudio::MenuRestart::leftAction(void) noexcept
{
}

void IndieStudio::MenuRestart::rightAction(void) noexcept
{
}

void IndieStudio::MenuRestart::upAction(void) noexcept
{
}

void IndieStudio::MenuRestart::downAction(void) noexcept
{
}

void IndieStudio::MenuRestart::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuRestart::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_RESTART_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_RESTART_BACK)
		this->escapeAction();
}

void IndieStudio::MenuRestart::leftActionManager(void) noexcept
{
}

void IndieStudio::MenuRestart::rightActionManager(void) noexcept
{
}

void IndieStudio::MenuRestart::upActionManager(void) noexcept
{
}

void IndieStudio::MenuRestart::downActionManager(void) noexcept
{
}

void IndieStudio::MenuRestart::alphaActionManager(IndieStudio::Key key) noexcept
{
}

void IndieStudio::MenuRestart::alphaAction(IndieStudio::Key key) noexcept
{
}