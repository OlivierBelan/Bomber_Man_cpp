/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuOptions
*/

#include "MenuOptions.hpp"

IndieStudio::MenuOptions::MenuOptions(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config)
	: Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_OPTIONS_MAIN;
	this->_buttonStatus = BTN_OPTIONS_AUDIO;
	this->createButtons();
	this->_menuAudio = new IndieStudio::MenuAudio(this->_graphical, this->_volume, this->_sounds);
	this->_menuVideo = new IndieStudio::MenuVideo(this->_graphical, this->_volume, this->_sounds, this->_config);
	this->_menuControls = new IndieStudio::MenuControls(this->_graphical, this->_volume, this->_sounds, this->_config);
}

IndieStudio::MenuOptions::~MenuOptions()
{
}

void IndieStudio::MenuOptions::createButtons(void) noexcept
{
	this->_audio = new Button(this->_graphical, "assets/menu/buttons/audio.png", "assets/menu/buttons/audioA.png", std::pair<int, int>(-1, 400));
	this->_video = new Button(this->_graphical, "assets/menu/buttons/video.png", "assets/menu/buttons/videoA.png", std::pair<int, int>(-1, 400 + 110));
	this->_controls = new Button(this->_graphical, "assets/menu/buttons/controls.png", "assets/menu/buttons/controlsA.png", std::pair<int, int>(-1, 400 + 220));
	this->_back = new Button(this->_graphical, "assets/menu/buttons/back.png", "assets/menu/buttons/backA.png", std::pair<int, int>(-1, 400 + 330));
}

void IndieStudio::MenuOptions::drawButtons(void) noexcept
{
	this->_audio->drawButton();
	this->_video->drawButton();
	this->_controls->drawButton();
	this->_back->drawButton();
}

void IndieStudio::MenuOptions::checkActions(void) noexcept
{
	if (this->_menuAudio->getCurrentMenuActive() == MENU_AUDIO_BACK)
	{
		this->_renderStatus = MENU_OPTIONS_MAIN;
		this->_menuAudio->setMenuActive(MENU_AUDIO_MAIN);
	}
	else if (this->_menuVideo->getCurrentMenuActive() == MENU_VIDEO_BACK)
	{
		this->_renderStatus = MENU_OPTIONS_MAIN;
		this->_menuVideo->setMenuActive(MENU_VIDEO_MAIN);
	}
	else if (this->_menuControls->getCurrentMenuActive() == MENU_CONTROLS_BACK)
	{
		this->_renderStatus = MENU_OPTIONS_MAIN;
		this->_menuControls->setMenuActive(MENU_CONTROLS_MAIN);
	}
}

void IndieStudio::MenuOptions::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
}

void IndieStudio::MenuOptions::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->drawMenuManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->_menuVideo->drawMenuManager();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->drawMenuManager();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->drawMenu();
}

void IndieStudio::MenuOptions::refreshSkin(void) noexcept
{
	if (this->_buttonStatus == BTN_OPTIONS_AUDIO)
	{
		this->_audio->setActiveSkin();
		this->_video->setDefaultSkin();
		this->_controls->setDefaultSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_OPTIONS_VIDEO)
	{
		this->_audio->setDefaultSkin();
		this->_video->setActiveSkin();
		this->_controls->setDefaultSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_OPTIONS_CONTROLS)
	{
		this->_audio->setDefaultSkin();
		this->_video->setDefaultSkin();
		this->_controls->setActiveSkin();
		this->_back->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_OPTIONS_BACK)
	{
		this->_audio->setDefaultSkin();
		this->_video->setDefaultSkin();
		this->_controls->setDefaultSkin();
		this->_back->setActiveSkin();
	}
}

void IndieStudio::MenuOptions::returnAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_buttonStatus == BTN_OPTIONS_AUDIO)
		this->_renderStatus = MENU_OPTIONS_AUDIO;
	else if (this->_buttonStatus == BTN_OPTIONS_VIDEO)
		this->_renderStatus = MENU_OPTIONS_VIDEO;
	else if (this->_buttonStatus == BTN_OPTIONS_CONTROLS)
		this->_renderStatus = MENU_OPTIONS_CONTROLS;
	else if (this->_buttonStatus == BTN_OPTIONS_BACK)
		this->_renderStatus = MENU_OPTIONS_BACK;
}

void IndieStudio::MenuOptions::escapeAction(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	this->_renderStatus = MENU_OPTIONS_BACK;
}

void IndieStudio::MenuOptions::leftAction(void) noexcept
{
}

void IndieStudio::MenuOptions::rightAction(void) noexcept
{
}

void IndieStudio::MenuOptions::upAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuOptions::downAction(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuOptions::returnActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->returnAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->returnActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->returnAction();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->returnAction();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->returnAction();
}

void IndieStudio::MenuOptions::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->escapeActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->_menuVideo->escapeActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->escapeActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->escapeAction();
}

void IndieStudio::MenuOptions::leftActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->leftAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->leftActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->_menuVideo->leftActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->leftActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->leftAction();
}

void IndieStudio::MenuOptions::rightActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->rightAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->rightActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->_menuVideo->rightActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->rightActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->rightAction();
}

void IndieStudio::MenuOptions::upActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->upAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->upActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->_menuVideo->upActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->upActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->upAction();
}

void IndieStudio::MenuOptions::downActionManager(void) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_MAIN)
		this->downAction();
	else if (this->_renderStatus == MENU_OPTIONS_AUDIO)
		this->_menuAudio->downActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_VIDEO)
		this->_menuVideo->downActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->downActionManager();
	else if (this->_renderStatus == MENU_OPTIONS_BACK)
		this->downAction();
}

void IndieStudio::MenuOptions::createImages(void) noexcept
{
}

void IndieStudio::MenuOptions::drawImages(void) noexcept
{
}

void IndieStudio::MenuOptions::alphaActionManager(IndieStudio::Key key) noexcept
{
	if (this->_renderStatus == MENU_OPTIONS_CONTROLS)
		this->_menuControls->alphaActionManager(key);
}

void IndieStudio::MenuOptions::alphaAction(IndieStudio::Key key) noexcept
{
}