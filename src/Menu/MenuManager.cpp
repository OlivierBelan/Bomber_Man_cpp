/*
** EPITECH PROJECT, 2019
** 2018
** File description:
** menu
*/

#include "MenuManager.hpp"

IndieStudio::MenuManager::MenuManager(Render &renderStatus, IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::Config *config)
	: _renderStatus(renderStatus), _graphical(graphical), _volume(volume), _config(config)
{
	this->_sounds = new IndieStudio::MenuSounds(this->_volume);
	this->_menuMain = new IndieStudio::MenuMain(this->_graphical, this->_volume, this->_sounds, this->_config);
	this->_menuPause = new IndieStudio::MenuPause(this->_graphical, this->_volume, this->_sounds, this->_config);
	this->_volume->refreshVolume();
}

IndieStudio::MenuManager::~MenuManager()
{
}

void IndieStudio::MenuManager::checkActions(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
	{
		if (this->_menuMain->getCurrentMenuActive() == MENU_NEW_GAME)
		{
			this->_renderStatus = GAME;
			this->_menuMain->setMenuActive(MENU_MAIN_MAIN);
		}
		else if (this->_menuMain->getCurrentMenuActive() == MENU_MAIN_EXIT)
		{
			std::this_thread::sleep_for(std::chrono::microseconds(100000));
			this->_graphical.drop();
			exit(0);
		} else if (this->_menuMain->getCurrentMenuActive() == MENU_MAIN_LOADGAME)
		{
			if (std::ifstream(MAP_TXT_PATH).good() && std::ifstream(PLAYER_TXT_PATH).good()) {
				this->_config->setMode(Mode::CONTINUE);
				this->_renderStatus = Render::GAME;
				this->_menuMain->setMenuActive(MENU_MAIN_MAIN);
			}
		}
	}
	else if (this->_renderStatus == PAUSE_MENU)
	{
		if (this->_menuPause->getCurrentMenuActive() == MENU_PAUSE_BACK)
		{
			this->_renderStatus = GAME;
			this->_menuPause->setMenuActive(MENU_PAUSE_MAIN);
		}
		else if (this->_menuPause->getCurrentMenuActive() == MENU_PAUSE_QUIT)
		{
			this->_config->setMode(Mode::RESET);
			this->_renderStatus = MAIN_MENU;
			this->_menuPause->setButtonActive(BTN_PAUSE_BACK);
			this->_menuPause->setMenuActive(MENU_PAUSE_MAIN);
			this->_menuMain->setMenuActive(MENU_MAIN_MAIN);
		}
		else if (this->_menuPause->getCurrentMenuActive() == MENU_PAUSE_RESTART)
		{
			this->_config->setPrevMode(this->_config->getMode());
			this->_menuPause->setMenuActive(MENU_PAUSE_MAIN);
			this->_config->setMode(Mode::RESET);
			this->_renderStatus = Render::GAME;
		}
	}
}

void IndieStudio::MenuManager::render(void) noexcept
{
	this->checkEvent();
	this->checkActions();
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->drawMenuManager();
	else if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->drawMenuManager();
}

void IndieStudio::MenuManager::returnActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->returnActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->returnActionManager();
}

void IndieStudio::MenuManager::escapeActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->escapeActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->escapeActionManager();
}

void IndieStudio::MenuManager::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->leftActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->leftActionManager();
}

void IndieStudio::MenuManager::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->rightActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->rightActionManager();
}

void IndieStudio::MenuManager::upActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->upActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->upActionManager();
}

void IndieStudio::MenuManager::downActionManager(void) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->downActionManager();
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->downActionManager();
}

void IndieStudio::MenuManager::alphaActionManager(IndieStudio::Key key) noexcept
{
	if (this->_renderStatus == MAIN_MENU)
		this->_menuMain->alphaActionManager(key);
	if (this->_renderStatus == PAUSE_MENU)
		this->_menuPause->alphaActionManager(key);
}

void IndieStudio::MenuManager::checkEvent(void) noexcept
{
	bool returnKey = this->_event._key[IndieStudio::Key::RETURN];
	bool escKey = this->_event._key[IndieStudio::Key::ESC];
	bool leftKey = this->_event._key[IndieStudio::Key::KEY_LEFT];
	bool rightKey = this->_event._key[IndieStudio::Key::KEY_RIGHT];
	bool upKey = this->_event._key[IndieStudio::Key::KEY_UP];
	bool downKey = this->_event._key[IndieStudio::Key::KEY_DOWN];
	this->_event = this->_graphical.getEvent();

	if (this->_event._key[IndieStudio::Key::RETURN] != returnKey && returnKey == false)
		this->returnActionManager();
	else if (this->_event._key[IndieStudio::Key::ESC] != escKey && escKey == false)
		this->escapeActionManager();
	else if (this->_event._key[IndieStudio::Key::KEY_LEFT] != leftKey && leftKey == false)
		this->leftActionManager();
	else if (this->_event._key[IndieStudio::Key::KEY_RIGHT] != rightKey && rightKey == false)
		this->rightActionManager();
	else if (this->_event._key[IndieStudio::Key::KEY_UP] != upKey && upKey == false)
		this->upActionManager();
	else if (this->_event._key[IndieStudio::Key::KEY_DOWN] != downKey && downKey == false)
		this->downActionManager();
	IndieStudio::Key key = A;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		if (this->_event._key[key])
			this->alphaActionManager(key);
		key = static_cast<IndieStudio::Key>(static_cast<int>(key) + 1);
	}
}
