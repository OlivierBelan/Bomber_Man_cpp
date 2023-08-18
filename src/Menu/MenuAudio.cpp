/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuAudio
*/

#include "MenuAudio.hpp"

IndieStudio::MenuAudio::MenuAudio(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds)
	: Menu(graphical, volume, sounds)
{
	this->_renderStatus = MENU_AUDIO_MAIN;
	this->_buttonStatus = BTN_AUDIO_MUSIC;
	this->createButtons();
	this->createImages();
	this->setVolumeMusicBar();
	this->setVolumeEffectBar();
}

IndieStudio::MenuAudio::~MenuAudio()
{
}

void IndieStudio::MenuAudio::createButtons(void) noexcept
{
	this->_music = new Button(this->_graphical, "assets/menu/options/music.png", "assets/menu/options/musicA.png", std::pair<int, int>(-1, 550));
	this->_effects = new Button(this->_graphical, "assets/menu/options/effects.png", "assets/menu/options/effectsA.png", std::pair<int, int>(-1, 750));
	this->_leftMusicArrow = new Button(this->_graphical, "assets/menu/options/left.png", "assets/menu/options/leftA.png", std::pair<int, int>(-1, 420));
	this->_leftEffectArrow = new Button(this->_graphical, "assets/menu/options/left.png", "assets/menu/options/leftA.png", std::pair<int, int>(-1, 620));
	this->_rightMusicArrow = new Button(this->_graphical, "assets/menu/options/right.png", "assets/menu/options/rightA.png", std::pair<int, int>(-1, 420));
	this->_rightEffectArrow = new Button(this->_graphical, "assets/menu/options/right.png", "assets/menu/options/rightA.png", std::pair<int, int>(-1, 620));
}

void IndieStudio::MenuAudio::drawButtons(void) noexcept
{
	this->_music->drawButton();
	this->_effects->drawButton();
	this->_leftMusicArrow->drawButton();
	this->_leftEffectArrow->drawButton();
	this->_rightMusicArrow->drawButton();
	this->_rightEffectArrow->drawButton();
}

void IndieStudio::MenuAudio::createImages(void) noexcept
{
	this->_volumeBarMusicEmpty = this->_graphical.createImage("assets/menu/options/empty2.png", std::pair<int, int>(-1, 380));
	this->_volumeBarEffectEmpty = this->_graphical.createImage("assets/menu/options/empty2.png", std::pair<int, int>(-1, 580));
	this->_volumeBarMusicFilled = this->_graphical.createImage("assets/menu/options/filled.png", std::pair<int, int>(-1, 380));
	this->_volumeBarEffectFilled = this->_graphical.createImage("assets/menu/options/filled.png", std::pair<int, int>(-1, 580));
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 800));
}

void IndieStudio::MenuAudio::drawImages(void) noexcept
{
	this->_graphical.drawImage(this->_volumeBarMusicEmpty);
	this->_graphical.drawImage(this->_volumeBarEffectEmpty);
	this->_graphical.drawImage(this->_volumeBarMusicFilled);
	this->_graphical.drawImage(this->_volumeBarEffectFilled);
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuAudio::drawMenuManager(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuAudio::refreshSkin(void) noexcept
{
	this->setVolumeMusicBar();
	this->setVolumeEffectBar();
	if (this->_buttonStatus == BTN_AUDIO_MUSIC)
	{
		this->_music->setActiveSkin();
		this->_effects->setDefaultSkin();
	}
	else if (this->_buttonStatus == BTN_AUDIO_EFFECT)
	{
		this->_music->setDefaultSkin();
		this->_effects->setActiveSkin();
	}
	if (this->_leftMusicTime <= 0)
		this->_leftMusicArrow->setDefaultSkin();
	else
		this->_leftMusicTime--;
	if (this->_rightMusicTime <= 0)
		this->_rightMusicArrow->setDefaultSkin();
	else
		this->_rightMusicTime--;
	if (this->_leftEffectTime <= 0)
		this->_leftEffectArrow->setDefaultSkin();
	else
		this->_leftEffectTime--;
	if (this->_rightEffectTime <= 0)
		this->_rightEffectArrow->setDefaultSkin();
	else
		this->_rightEffectTime--;
}

void IndieStudio::MenuAudio::setVolumeMusicBar(void) noexcept
{
	int vol = 0;
	int volume = this->_volume->getVolumeMusics() / 10;
	if (volume == 0)
		vol = 0;
	else
		vol = 35 * volume + 20;
	this->_graphical.setCustomRectangle(this->_volumeBarMusicFilled, 0, 0, vol, 208);
}

void IndieStudio::MenuAudio::setVolumeEffectBar(void) noexcept
{
	int vol = 0;
	int volume = this->_volume->getVolumeEffects() / 10;
	if (volume == 0)
		vol = 0;
	else
		vol = 35 * volume + 20;
	this->_graphical.setCustomRectangle(this->_volumeBarEffectFilled, 0, 0, vol, 208);
}

void IndieStudio::MenuAudio::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuAudio::escapeActionManager(void) noexcept
{
	this->_renderStatus = MENU_AUDIO_BACK;
}

void IndieStudio::MenuAudio::leftActionManager(void) noexcept
{
	this->_sounds->_volumeSwitchSound->playSound();
	if (this->_buttonStatus == BTN_AUDIO_MUSIC)
	{
		this->_leftMusicTime = 50;
		this->_leftMusicArrow->setActiveSkin();
		this->_volume->setVolumeMusics(this->_volume->getVolumeMusics() - 10);
	}
	else if (this->_buttonStatus == BTN_AUDIO_EFFECT)
	{
		this->_leftEffectTime = 50;
		this->_leftEffectArrow->setActiveSkin();
		this->_volume->setVolumeEffects(this->_volume->getVolumeEffects() - 10);
	}
}

void IndieStudio::MenuAudio::rightActionManager(void) noexcept
{
	this->_sounds->_volumeSwitchSound->playSound();
	if (this->_buttonStatus == BTN_AUDIO_MUSIC)
	{
		this->_rightMusicTime = 50;
		this->_rightMusicArrow->setActiveSkin();
		this->_volume->setVolumeMusics(this->_volume->getVolumeMusics() + 10);
	}
	else if (this->_buttonStatus == BTN_AUDIO_EFFECT)
	{
		this->_rightEffectTime = 50;
		this->_rightEffectArrow->setActiveSkin();
		this->_volume->setVolumeEffects(this->_volume->getVolumeEffects() + 10);
	}
}

void IndieStudio::MenuAudio::upActionManager(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 1);
}

void IndieStudio::MenuAudio::downActionManager(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 1);
}

void IndieStudio::MenuAudio::returnAction(void) noexcept
{
}

void IndieStudio::MenuAudio::escapeAction(void) noexcept
{
}

void IndieStudio::MenuAudio::leftAction(void) noexcept
{
}

void IndieStudio::MenuAudio::rightAction(void) noexcept
{
}

void IndieStudio::MenuAudio::upAction(void) noexcept
{
}

void IndieStudio::MenuAudio::downAction(void) noexcept
{
}

void IndieStudio::MenuAudio::checkActions(void) noexcept
{
}

void IndieStudio::MenuAudio::drawMenu(void) noexcept
{
}

void IndieStudio::MenuAudio::alphaActionManager(IndieStudio::Key key) noexcept
{
}

void IndieStudio::MenuAudio::alphaAction(IndieStudio::Key key) noexcept
{
}