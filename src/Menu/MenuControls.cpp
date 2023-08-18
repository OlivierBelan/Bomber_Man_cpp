/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuControls
*/

#include "MenuControls.hpp"

IndieStudio::MenuControls::MenuControls(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config)
	: Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_CONTROLS_MAIN;
	this->_buttonStatus = BTN_CONTROLS_UP;
	this->_playerStatus = MENU_CONTROLS_PLY_1;
	this->createButtons();
	this->createImages();
}

IndieStudio::MenuControls::~MenuControls()
{
}

void IndieStudio::MenuControls::createLetters(void) noexcept
{
	IndieStudio::Key key = A;
	letter tmp;
	std::string def = "assets/menu/controls/letters/";
	std::string act = "assets/menu/controls/letters/#";
	for (char c = 'A'; c <= 'Z'; c++)
	{
		tmp._id = c;
		tmp._btn = new Button(this->_graphical, def + c + ".png", act + c + ".png", std::pair<int, int>(975, 450));
		tmp._key = key;
		key = static_cast<IndieStudio::Key>(static_cast<int>(key) + 1);
		this->_letters.push_back(tmp);
	}
	IndieStudio::playerKeybinds keybinds1 = this->_config->getKeybinds1();
	this->_upKey1._key = keybinds1.up;
	this->_downKey1._key = keybinds1.down;
	this->_leftKey1._key = keybinds1.left;
	this->_rightKey1._key = keybinds1.right;
	this->_bombKey1._key = keybinds1.bomb;
	IndieStudio::playerKeybinds keybinds2 = this->_config->getKeybinds2();
	this->_upKey2._key = keybinds2.up;
	this->_downKey2._key = keybinds2.down;
	this->_leftKey2._key = keybinds2.left;
	this->_rightKey2._key = keybinds2.right;
	this->_bombKey2._key = keybinds2.bomb;
}

void IndieStudio::MenuControls::createButtons(void) noexcept
{
	int x = 770;
	int x3 = 990;
	int pos = 375;
	int off = 70;
	this->_upBtn1 = new Button(this->_graphical, "assets/menu/controls/up.png", "assets/menu/controls/upA.png", std::pair<int, int>(x, (pos += off)));
	this->_downBtn1 = new Button(this->_graphical, "assets/menu/controls/down.png", "assets/menu/controls/downA.png", std::pair<int, int>(x, (pos += off)));
	this->_leftBtn1 = new Button(this->_graphical, "assets/menu/controls/left.png", "assets/menu/controls/leftA.png", std::pair<int, int>(x, (pos += off)));
	this->_rightBtn1 = new Button(this->_graphical, "assets/menu/controls/right.png", "assets/menu/controls/rightA.png", std::pair<int, int>(x, (pos += off)));
	this->_bombBtn1 = new Button(this->_graphical, "assets/menu/controls/bomb.png", "assets/menu/controls/bombA.png", std::pair<int, int>(x, (pos += off)));
	pos = 375;
	this->_upBtn2 = new Button(this->_graphical, "assets/menu/controls/up.png", "assets/menu/controls/upA.png", std::pair<int, int>(x3, (pos += off)));
	this->_downBtn2 = new Button(this->_graphical, "assets/menu/controls/down.png", "assets/menu/controls/downA.png", std::pair<int, int>(x3, (pos += off)));
	this->_leftBtn2 = new Button(this->_graphical, "assets/menu/controls/left.png", "assets/menu/controls/leftA.png", std::pair<int, int>(x3, (pos += off)));
	this->_rightBtn2 = new Button(this->_graphical, "assets/menu/controls/right.png", "assets/menu/controls/rightA.png", std::pair<int, int>(x3, (pos += off)));
	this->_bombBtn2 = new Button(this->_graphical, "assets/menu/controls/bomb.png", "assets/menu/controls/bombA.png", std::pair<int, int>(x3, (pos += off)));
	this->createLetters();
}

void IndieStudio::MenuControls::drawLetter(IndieStudio::KeyB keyB, std::pair<int, int> pos) noexcept
{
	for (auto it = this->_letters.begin(); it != this->_letters.end(); it++)
		if ((*it)._key == keyB._key)
		{
			(*it)._btn->setPosition(pos);
			if (keyB._status)
				(*it)._btn->setActiveSkin();
			else
				(*it)._btn->setDefaultSkin();
			(*it)._btn->drawButton();
		}
}

void IndieStudio::MenuControls::drawButtons(void) noexcept
{
	int x1 = 770;
	int x2 = x1 + 80;
	int x3 = 990;
	int x4 = x3 + 80;
	int pos = 375;
	int off1 = 70;
	int off2 = 71;
	this->_upBtn1->drawButton();
	this->_downBtn1->drawButton();
	this->_leftBtn1->drawButton();
	this->_rightBtn1->drawButton();
	this->_bombBtn1->drawButton();
	this->_upBtn2->drawButton();
	this->_downBtn2->drawButton();
	this->_leftBtn2->drawButton();
	this->_rightBtn2->drawButton();
	this->_bombBtn2->drawButton();
	this->drawLetter(this->_upKey1, std::pair<int, int>(x2, (pos += off2)));
	this->drawLetter(this->_downKey1, std::pair<int, int>(x2, (pos += off2)));
	this->drawLetter(this->_leftKey1, std::pair<int, int>(x2, (pos += off2)));
	this->drawLetter(this->_rightKey1, std::pair<int, int>(x2, (pos += off2)));
	this->drawLetter(this->_bombKey1, std::pair<int, int>(x2, (pos += off2)));
	pos = 375;
	this->drawLetter(this->_upKey2, std::pair<int, int>(x4, (pos += off2)));
	this->drawLetter(this->_downKey2, std::pair<int, int>(x4, (pos += off2)));
	this->drawLetter(this->_leftKey2, std::pair<int, int>(x4, (pos += off2)));
	this->drawLetter(this->_rightKey2, std::pair<int, int>(x4, (pos += off2)));
	this->drawLetter(this->_bombKey2, std::pair<int, int>(x4, (pos += off2)));
}

void IndieStudio::MenuControls::createImages(void) noexcept
{
	this->_player1 = new Button(this->_graphical, "assets/menu/controls/player1.png", "assets/menu/controls/player1A.png", std::pair<int, int>(675, 375));
	this->_player2 = new Button(this->_graphical, "assets/menu/controls/player2.png", "assets/menu/controls/player2A.png", std::pair<int, int>(895, 375));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuControls::drawImages(void) noexcept
{
	this->_player1->drawButton();
	this->_player2->drawButton();
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuControls::checkActions(void) noexcept
{
}

void IndieStudio::MenuControls::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuControls::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_CONTROLS_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_CONTROLS_BACK)
		this->drawMenu();
}

void IndieStudio::MenuControls::refreshSkin(void) noexcept
{
	IndieStudio::playerKeybinds keybinds1 = this->_config->getKeybinds1();
	this->_upKey1._key = keybinds1.up;
	this->_downKey1._key = keybinds1.down;
	this->_leftKey1._key = keybinds1.left;
	this->_rightKey1._key = keybinds1.right;
	this->_bombKey1._key = keybinds1.bomb;
	IndieStudio::playerKeybinds keybinds2 = this->_config->getKeybinds2();
	this->_upKey2._key = keybinds2.up;
	this->_downKey2._key = keybinds2.down;
	this->_leftKey2._key = keybinds2.left;
	this->_rightKey2._key = keybinds2.right;
	this->_bombKey2._key = keybinds2.bomb;
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
	{
		this->_player1->setActiveSkin();
		this->_player2->setDefaultSkin();
		this->_upBtn2->setDefaultSkin();
		this->_downBtn2->setDefaultSkin();
		this->_leftBtn2->setDefaultSkin();
		this->_rightBtn2->setDefaultSkin();
		this->_bombBtn2->setDefaultSkin();
		this->_upKey2._status = false;
		this->_downKey2._status = false;
		this->_leftKey2._status = false;
		this->_rightKey2._status = false;
		this->_bombKey2._status = false;
		if (this->_buttonStatus == BTN_CONTROLS_UP)
		{
			this->_upBtn1->setActiveSkin();
			this->_downBtn1->setDefaultSkin();
			this->_leftBtn1->setDefaultSkin();
			this->_rightBtn1->setDefaultSkin();
			this->_bombBtn1->setDefaultSkin();
			this->_upKey1._status = true;
			this->_downKey1._status = false;
			this->_leftKey1._status = false;
			this->_rightKey1._status = false;
			this->_bombKey1._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_DOWN)
		{
			this->_upBtn1->setDefaultSkin();
			this->_downBtn1->setActiveSkin();
			this->_leftBtn1->setDefaultSkin();
			this->_rightBtn1->setDefaultSkin();
			this->_bombBtn1->setDefaultSkin();
			this->_upKey1._status = false;
			this->_downKey1._status = true;
			this->_leftKey1._status = false;
			this->_rightKey1._status = false;
			this->_bombKey1._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_LEFT)
		{
			this->_upBtn1->setDefaultSkin();
			this->_downBtn1->setDefaultSkin();
			this->_leftBtn1->setActiveSkin();
			this->_rightBtn1->setDefaultSkin();
			this->_bombBtn1->setDefaultSkin();
			this->_upKey1._status = false;
			this->_downKey1._status = false;
			this->_leftKey1._status = true;
			this->_rightKey1._status = false;
			this->_bombKey1._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_RIGHT)
		{
			this->_upBtn1->setDefaultSkin();
			this->_downBtn1->setDefaultSkin();
			this->_leftBtn1->setDefaultSkin();
			this->_rightBtn1->setActiveSkin();
			this->_bombBtn1->setDefaultSkin();
			this->_upKey1._status = false;
			this->_downKey1._status = false;
			this->_leftKey1._status = false;
			this->_rightKey1._status = true;
			this->_bombKey1._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_BOMB)
		{
			this->_upBtn1->setDefaultSkin();
			this->_downBtn1->setDefaultSkin();
			this->_leftBtn1->setDefaultSkin();
			this->_rightBtn1->setDefaultSkin();
			this->_bombBtn1->setActiveSkin();
			this->_upKey1._status = false;
			this->_downKey1._status = false;
			this->_leftKey1._status = false;
			this->_rightKey1._status = false;
			this->_bombKey1._status = true;
		}
	}
	else if (this->_playerStatus == MENU_CONTROLS_PLY_2)
	{
		this->_player1->setDefaultSkin();
		this->_player2->setActiveSkin();
		this->_upBtn1->setDefaultSkin();
		this->_downBtn1->setDefaultSkin();
		this->_leftBtn1->setDefaultSkin();
		this->_rightBtn1->setDefaultSkin();
		this->_bombBtn1->setDefaultSkin();
		this->_upKey1._status = false;
		this->_downKey1._status = false;
		this->_leftKey1._status = false;
		this->_rightKey1._status = false;
		this->_bombKey1._status = false;
		if (this->_buttonStatus == BTN_CONTROLS_UP)
		{
			this->_upBtn2->setActiveSkin();
			this->_downBtn2->setDefaultSkin();
			this->_leftBtn2->setDefaultSkin();
			this->_rightBtn2->setDefaultSkin();
			this->_bombBtn2->setDefaultSkin();
			this->_upKey2._status = true;
			this->_downKey2._status = false;
			this->_leftKey2._status = false;
			this->_rightKey2._status = false;
			this->_bombKey2._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_DOWN)
		{
			this->_upBtn2->setDefaultSkin();
			this->_downBtn2->setActiveSkin();
			this->_leftBtn2->setDefaultSkin();
			this->_rightBtn2->setDefaultSkin();
			this->_bombBtn2->setDefaultSkin();
			this->_upKey2._status = false;
			this->_downKey2._status = true;
			this->_leftKey2._status = false;
			this->_rightKey2._status = false;
			this->_bombKey2._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_LEFT)
		{
			this->_upBtn2->setDefaultSkin();
			this->_downBtn2->setDefaultSkin();
			this->_leftBtn2->setActiveSkin();
			this->_rightBtn2->setDefaultSkin();
			this->_bombBtn2->setDefaultSkin();
			this->_upKey2._status = false;
			this->_downKey2._status = false;
			this->_leftKey2._status = true;
			this->_rightKey2._status = false;
			this->_bombKey2._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_RIGHT)
		{
			this->_upBtn2->setDefaultSkin();
			this->_downBtn2->setDefaultSkin();
			this->_leftBtn2->setDefaultSkin();
			this->_rightBtn2->setActiveSkin();
			this->_bombBtn2->setDefaultSkin();
			this->_upKey2._status = false;
			this->_downKey2._status = false;
			this->_leftKey2._status = false;
			this->_rightKey2._status = true;
			this->_bombKey2._status = false;
		}
		else if (this->_buttonStatus == BTN_CONTROLS_BOMB)
		{
			this->_upBtn2->setDefaultSkin();
			this->_downBtn2->setDefaultSkin();
			this->_leftBtn2->setDefaultSkin();
			this->_rightBtn2->setDefaultSkin();
			this->_bombBtn2->setActiveSkin();
			this->_upKey2._status = false;
			this->_downKey2._status = false;
			this->_leftKey2._status = false;
			this->_rightKey2._status = false;
			this->_bombKey2._status = true;
		}
	}
}

void IndieStudio::MenuControls::returnAction(void) noexcept
{
}

void IndieStudio::MenuControls::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_CONTROLS_BACK;
}

void IndieStudio::MenuControls::leftAction(void) noexcept
{
}

void IndieStudio::MenuControls::rightAction(void) noexcept
{
}

void IndieStudio::MenuControls::upAction(void) noexcept
{
}

void IndieStudio::MenuControls::downAction(void) noexcept
{
}

void IndieStudio::MenuControls::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuControls::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_CONTROLS_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_CONTROLS_BACK)
		this->escapeAction();
}

void IndieStudio::MenuControls::leftActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
		this->_playerStatus = MENU_CONTROLS_PLY_2;
	else
		this->_playerStatus = MENU_CONTROLS_PLY_1;
}

void IndieStudio::MenuControls::rightActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
		this->_playerStatus = MENU_CONTROLS_PLY_2;
	else
		this->_playerStatus = MENU_CONTROLS_PLY_1;
}

void IndieStudio::MenuControls::upActionManager(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 4);
}

void IndieStudio::MenuControls::downActionManager(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 4);
}

bool IndieStudio::MenuControls::checkKey(IndieStudio::Key key) noexcept
{
	bool status = true;
	IndieStudio::playerKeybinds keybinds1 = this->_config->getKeybinds1();
	IndieStudio::Key *keyPtr1 = (IndieStudio::Key *)&keybinds1;
	for (int i = 0; i < 5; i++)
		if (*(keyPtr1 + i) == key)
			status = false;
	IndieStudio::playerKeybinds keybinds2 = this->_config->getKeybinds2();
	IndieStudio::Key *keyPtr2 = (IndieStudio::Key *)&keybinds2;
	for (int i = 0; i < 5; i++)
		if (*(keyPtr2 + i) == key)
			status = false;
	if (status)
		this->_sounds->_volumeSwitchSound->playSound();
	return status;
}

void IndieStudio::MenuControls::alphaActionManager(IndieStudio::Key key) noexcept
{
	if (this->_playerStatus == MENU_CONTROLS_PLY_1)
	{
		IndieStudio::playerKeybinds keybinds = this->_config->getKeybinds1();
		if (this->_buttonStatus == BTN_CONTROLS_UP && checkKey(key))
			keybinds.up = key;
		else if (this->_buttonStatus == BTN_CONTROLS_DOWN && checkKey(key))
			keybinds.down = key;
		else if (this->_buttonStatus == BTN_CONTROLS_LEFT && checkKey(key))
			keybinds.left = key;
		else if (this->_buttonStatus == BTN_CONTROLS_RIGHT && checkKey(key))
			keybinds.right = key;
		else if (this->_buttonStatus == BTN_CONTROLS_BOMB && checkKey(key))
			keybinds.bomb = key;
		this->_config->setKeybinds1(keybinds);
	}
	else if (this->_playerStatus == MENU_CONTROLS_PLY_2)
	{
		IndieStudio::playerKeybinds keybinds = this->_config->getKeybinds2();
		if (this->_buttonStatus == BTN_CONTROLS_UP && checkKey(key))
			keybinds.up = key;
		else if (this->_buttonStatus == BTN_CONTROLS_DOWN && checkKey(key))
			keybinds.down = key;
		else if (this->_buttonStatus == BTN_CONTROLS_LEFT && checkKey(key))
			keybinds.left = key;
		else if (this->_buttonStatus == BTN_CONTROLS_RIGHT && checkKey(key))
			keybinds.right = key;
		else if (this->_buttonStatus == BTN_CONTROLS_BOMB && checkKey(key))
			keybinds.bomb = key;
		this->_config->setKeybinds2(keybinds);
	}
}

void IndieStudio::MenuControls::alphaAction(IndieStudio::Key key) noexcept
{
}