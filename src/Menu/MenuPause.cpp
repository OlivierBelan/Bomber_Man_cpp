/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuPause
*/

#include "MenuPause.hpp"

IndieStudio::MenuPause::MenuPause(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config)
	: Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_PAUSE_MAIN;
	this->_buttonStatus = BTN_PAUSE_BACK;
	this->createButtons();
	this->createImages();
	this->_menuRestart = new IndieStudio::MenuRestart(this->_graphical, this->_volume, this->_sounds);
	this->_menuOptions = new IndieStudio::MenuOptions(this->_graphical, this->_volume, this->_sounds, this->_config);
}

IndieStudio::MenuPause::~MenuPause()
{
}

void IndieStudio::MenuPause::createButtons(void) noexcept
{
	this->_back = new Button(this->_graphical, "assets/menu/buttons/resume.png", "assets/menu/buttons/resumeA.png", std::pair<int, int>(-1, 400));
	this->_restart = new Button(this->_graphical, "assets/menu/buttons/restart.png", "assets/menu/buttons/restartA.png", std::pair<int, int>(-1, 400 + 110));
	this->_options = new Button(this->_graphical, "assets/menu/buttons/options.png", "assets/menu/buttons/optionsA.png", std::pair<int, int>(-1, 400 + 220));
	this->_quit = new Button(this->_graphical, "assets/menu/buttons/quit.png", "assets/menu/buttons/quitA.png", std::pair<int, int>(-1, 400 + 330));
}

void IndieStudio::MenuPause::drawButtons(void) noexcept
{
	this->_back->drawButton();
	this->_restart->drawButton();
	this->_options->drawButton();
	this->_quit->drawButton();
}

void IndieStudio::MenuPause::createImages(void) noexcept
{
	this->_wall = this->_graphical.createImage("assets/menu/wall.jpg", std::pair<int, int>(0, 0));
	this->_titleMenu = this->_graphical.createImage("assets/menu/gamepaused.png", std::pair<int, int>(-1, 100));
	this->_frameMenu = this->_graphical.createImage("assets/menu/frame.png", std::pair<int, int>(-1, 320));
}

void IndieStudio::MenuPause::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_wall);
	this->_graphical.drawImage(this->_titleMenu);
	this->_graphical.drawImage(this->_titleMenu);
	// this->_graphical.drawImage(this->_frameMenu);
}

void IndieStudio::MenuPause::checkActions(void) noexcept
{
	if (this->_menuRestart->getCurrentMenuActive() == MENU_RESTART_BACK)
	{
		this->_renderStatus = MENU_PAUSE_MAIN;
		this->_menuRestart->setMenuActive(MENU_RESTART_MAIN);
	}
	else if (this->_menuOptions->getCurrentMenuActive() == MENU_OPTIONS_BACK)
	{
		this->_renderStatus = MENU_PAUSE_MAIN;
		this->_menuOptions->setMenuActive(MENU_OPTIONS_MAIN);
		this->_menuOptions->setButtonActive(BTN_OPTIONS_AUDIO);
	}
}

void IndieStudio::MenuPause::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawImages();
	this->drawButtons();
}

void IndieStudio::MenuPause::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus != MENU_PAUSE_MAIN)
		this->drawImages();
	if (this->_renderStatus == MENU_PAUSE_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_PAUSE_RESTART)
		this->_menuRestart->drawMenuManager();
	else if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->drawMenuManager();
}

void IndieStudio::MenuPause::refreshSkin(void) noexcept
{
	if (this->_buttonStatus == BTN_PAUSE_BACK)
	{
		this->_back->setActiveSkin();
		this->_restart->setDefaultSkin();
		this->_options->setDefaultSkin();
		this->_quit->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_PAUSE_RESTART)
	{
		this->_back->setDefaultSkin();
		this->_restart->setActiveSkin();
		this->_options->setDefaultSkin();
		this->_quit->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_PAUSE_OPTIONS)
	{
		this->_back->setDefaultSkin();
		this->_restart->setDefaultSkin();
		this->_options->setActiveSkin();
		this->_quit->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_PAUSE_QUIT)
	{
		this->_back->setDefaultSkin();
		this->_restart->setDefaultSkin();
		this->_options->setDefaultSkin();
		this->_quit->setActiveSkin();
	}
}

void IndieStudio::MenuPause::returnAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_buttonStatus == BTN_PAUSE_BACK)
		this->_renderStatus = MENU_PAUSE_BACK;
	else if (this->_buttonStatus == BTN_PAUSE_RESTART)
		this->_renderStatus = MENU_PAUSE_RESTART;
	else if (this->_buttonStatus == BTN_PAUSE_OPTIONS)
		this->_renderStatus = MENU_PAUSE_OPTIONS;
	else if (this->_buttonStatus == BTN_PAUSE_QUIT)
		this->_renderStatus = MENU_PAUSE_QUIT;
}

void IndieStudio::MenuPause::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_PAUSE_BACK;
}

void IndieStudio::MenuPause::leftAction(void) noexcept
{
}

void IndieStudio::MenuPause::rightAction(void) noexcept
{
}

void IndieStudio::MenuPause::upAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuPause::downAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuPause::returnActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_PAUSE_MAIN)
		this->returnAction();
	else if (this->_renderStatus == MENU_PAUSE_RESTART)
		this->_menuRestart->returnActionManager();
	else if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->returnActionManager();
}

void IndieStudio::MenuPause::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_PAUSE_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_PAUSE_RESTART)
		this->_menuRestart->escapeActionManager();
	else if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->escapeActionManager();
}

void IndieStudio::MenuPause::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->leftActionManager();
}

void IndieStudio::MenuPause::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->rightActionManager();
}

void IndieStudio::MenuPause::upActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_PAUSE_MAIN)
		this->upAction();
	else if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->upActionManager();
}

void IndieStudio::MenuPause::downActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_PAUSE_MAIN)
		this->downAction();
	else if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->downActionManager();
}

void IndieStudio::MenuPause::alphaActionManager(IndieStudio::Key key) noexcept
{
	if (this->_renderStatus == MENU_PAUSE_OPTIONS)
		this->_menuOptions->alphaActionManager(key);
}

void IndieStudio::MenuPause::alphaAction(IndieStudio::Key key) noexcept
{
}