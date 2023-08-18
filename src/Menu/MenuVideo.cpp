/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuVideo
*/

#include "MenuVideo.hpp"
#include <string>

IndieStudio::MenuVideo::MenuVideo(IndieStudio::IGraphical &graphical, IndieStudio::Volume *volume, IndieStudio::MenuSounds *sounds, IndieStudio::Config *config) :
	Menu(graphical, volume, sounds, config)
{
	this->_renderStatus = MENU_VIDEO_MAIN;
	this->_buttonStatus = BTN_VIDEO_BLOCK;

	if (this->_config->getQuality() == 16)
		this->_qualityStatus = QUALITY_LOW;
	else if (this->_config->getQuality() == 32)
		this->_qualityStatus = QUALITY_STANDARD;
	else if (this->_config->getQuality() == 64)
		this->_qualityStatus = QUALITY_HIGH;
	else if (this->_config->getQuality() == 128)
		this->_qualityStatus = QUALITY_VERY;
	else if (this->_config->getQuality() == 256)
		this->_qualityStatus = QUALITY_ULTRA;

	if (this->_config->_mapSize == 11)
		this->_mapStatus = MAP_SMALL;
	else if (this->_config->_mapSize == 15)
		this->_mapStatus = MAP_MEDIUM;
	else if (this->_config->_mapSize == 25)
		this->_mapStatus = MAP_LARGE;

	this->createButtons();
	this->createImages();
}

IndieStudio::MenuVideo::~MenuVideo()
{
}

void IndieStudio::MenuVideo::createButtons(void) noexcept
{
	int x = 550;
	int pos = 400;
	int off = 110;

	this->_block = new Button(this->_graphical, "assets/menu/video/block.png", "assets/menu/video/blockA.png", std::pair<int, int>(x, pos));
	this->_wall = new Button(this->_graphical, "assets/menu/video/wall.png", "assets/menu/video/wallA.png", std::pair<int, int>(x + 10, (pos + 110)));
	this->_quality = new Button(this->_graphical, "assets/menu/video/quality.png", "assets/menu/video/qualityA.png", std::pair<int, int>(x, (pos + 220)));
	this->_map = new Button(this->_graphical, "assets/menu/video/map.png", "assets/menu/video/mapA.png", std::pair<int, int>(x, (pos + 330)));
	x = 900;
	this->_low = new Button(this->_graphical, "assets/menu/video/low.png", "assets/menu/video/lowA.png", std::pair<int, int>(x, pos + 220));
	this->_standard = new Button(this->_graphical, "assets/menu/video/standard.png", "assets/menu/video/standardA.png", std::pair<int, int>(x, (pos + 220)));
	this->_high = new Button(this->_graphical, "assets/menu/video/high.png", "assets/menu/video/highA.png", std::pair<int, int>(x, (pos + 220)));
	this->_very = new Button(this->_graphical, "assets/menu/video/very.png", "assets/menu/video/veryA.png", std::pair<int, int>(x, (pos + 220)));
	this->_ultra = new Button(this->_graphical, "assets/menu/video/ultra.png", "assets/menu/video/ultraA.png", std::pair<int, int>(x, (pos + 220)));

	this->_small = new Button(this->_graphical, "assets/menu/video/small.png", "assets/menu/video/smallA.png", std::pair<int, int>(x, (pos + 330)));
	this->_medium = new Button(this->_graphical, "assets/menu/video/medium.png", "assets/menu/video/mediumA.png", std::pair<int, int>(x, (pos + 330)));
	this->_large = new Button(this->_graphical, "assets/menu/video/large.png", "assets/menu/video/largeA.png", std::pair<int, int>(x, (pos + 330)));
}

void IndieStudio::MenuVideo::drawButtons(void) noexcept
{
	this->_block->drawButton();
	this->_wall->drawButton();
	this->_quality->drawButton();
	this->_map->drawButton();

	if (this->_qualityStatus == QUALITY_LOW)
		this->_low->drawButton();
	else if (this->_qualityStatus == QUALITY_STANDARD)
		this->_standard->drawButton();
	else if (this->_qualityStatus == QUALITY_HIGH)
		this->_high->drawButton();
	else if (this->_qualityStatus == QUALITY_VERY)
		this->_very->drawButton();
	else if (this->_qualityStatus == QUALITY_ULTRA)
		this->_ultra->drawButton();

	if (this->_mapStatus == MAP_SMALL)
		this->_small->drawButton();
	else if (this->_mapStatus == MAP_MEDIUM)
		this->_medium->drawButton();
	else if (this->_mapStatus == MAP_LARGE)
		this->_large->drawButton();
}

void IndieStudio::MenuVideo::createImages(void) noexcept
{
	this->_escapeInfo = this->_graphical.createImage("assets/menu/options/esc2.png", std::pair<int, int>(-1, 850));
}

void IndieStudio::MenuVideo::drawImages(void) noexcept
{
	int pos = 400;
	this->_graphical.drawText(std::to_string(this->_config->_blockDensity) + "%", 1100, pos + 20, 0, 0);
	this->_graphical.drawText(std::to_string(this->_config->_wallDensity) + "%", 1100, pos + 110 + 20, 0, 0);
	this->_graphical.drawImage(this->_escapeInfo);
}

void IndieStudio::MenuVideo::checkActions(void) noexcept
{
}

void IndieStudio::MenuVideo::drawMenu(void) noexcept
{
	this->refreshSkin();
	this->drawButtons();
	this->drawImages();
}

void IndieStudio::MenuVideo::drawMenuManager(void) noexcept
{
	this->checkActions();
	if (this->_renderStatus == MENU_VIDEO_MAIN)
		this->drawMenu();
	else if (this->_renderStatus == MENU_VIDEO_BACK)
		this->drawMenu();
}

void IndieStudio::MenuVideo::refreshSkin(void) noexcept
{
	this->_block->setDefaultSkin();
	this->_wall->setDefaultSkin();
	this->_quality->setDefaultSkin();
	this->_map->setDefaultSkin();

	this->_low->setDefaultSkin();
	this->_standard->setDefaultSkin();
	this->_high->setDefaultSkin();
	this->_very->setDefaultSkin();
	this->_ultra->setDefaultSkin();

	this->_small->setDefaultSkin();
	this->_medium->setDefaultSkin();
	this->_large->setDefaultSkin();

	if (this->_buttonStatus == BTN_VIDEO_BLOCK) {
		this->_block->setActiveSkin();
	} else if (this->_buttonStatus == BTN_VIDEO_WALL) {
		this->_wall->setActiveSkin();
	} else if (this->_buttonStatus == BTN_VIDEO_QUALITY) {
		this->_quality->setActiveSkin();
		if (this->_qualityStatus == QUALITY_LOW) {
			this->_low->setActiveSkin();
			this->_config->setQuality(16);
		} else if (this->_qualityStatus == QUALITY_STANDARD) {
			this->_standard->setActiveSkin();
			this->_config->setQuality(32);
		} else if (this->_qualityStatus == QUALITY_HIGH) {
			this->_high->setActiveSkin();
			this->_config->setQuality(64);
		} else if (this->_qualityStatus == QUALITY_VERY) {
			this->_very->setActiveSkin();
			this->_config->setQuality(128);
		} else if (this->_qualityStatus == QUALITY_ULTRA) {
			this->_ultra->setActiveSkin();
			this->_config->setQuality(256);
		}
	} else if (this->_buttonStatus == BTN_VIDEO_MAP) {
		this->_map->setActiveSkin();
		if (this->_mapStatus == MAP_SMALL) {
			this->_small->setActiveSkin();
			this->_config->_mapSize = 11;
		} else if (this->_mapStatus == MAP_MEDIUM) {
			this->_medium->setActiveSkin();
			this->_config->_mapSize = 15;
		} else if (this->_mapStatus == MAP_LARGE) {
			this->_large->setActiveSkin();
			this->_config->_mapSize = 25;
		}
	}
}

void IndieStudio::MenuVideo::returnAction(void) noexcept
{
}

void IndieStudio::MenuVideo::escapeAction(void) noexcept
{
	this->_renderStatus = MENU_VIDEO_BACK;
}

void IndieStudio::MenuVideo::leftAction(void) noexcept
{
}

void IndieStudio::MenuVideo::rightAction(void) noexcept
{
}

void IndieStudio::MenuVideo::upAction(void) noexcept
{
}

void IndieStudio::MenuVideo::downAction(void) noexcept
{
}

void IndieStudio::MenuVideo::returnActionManager(void) noexcept
{
}

void IndieStudio::MenuVideo::escapeActionManager(void) noexcept
{
	this->_sounds->_buttonReturnSound->playSound();
	if (this->_renderStatus == MENU_VIDEO_MAIN)
		this->escapeAction();
	else if (this->_renderStatus == MENU_VIDEO_BACK)
		this->escapeAction();
}

void IndieStudio::MenuVideo::leftActionManager(void) noexcept
{
	if (this->_buttonStatus == BTN_VIDEO_WALL) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_config->_wallDensity -= 5;
		if (this->_config->_wallDensity < 0)
			this->_config->_wallDensity = 0;
	} else if (this->_buttonStatus == BTN_VIDEO_BLOCK) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_config->_blockDensity -= 5;
		if (this->_config->_blockDensity < 0)
			this->_config->_blockDensity = 0;
	} else if (this->_buttonStatus == BTN_VIDEO_QUALITY) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_qualityStatus--;
		if (this->_qualityStatus > 4)
			this->_qualityStatus = 0;
		else if (this->_qualityStatus < 0)
			this->_qualityStatus = 4;
	} else if (this->_buttonStatus == BTN_VIDEO_MAP) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_mapStatus--;
		if (this->_mapStatus > 2)
			this->_mapStatus = 0;
		else if (this->_mapStatus < 0)
			this->_mapStatus = 2;
	}
}

void IndieStudio::MenuVideo::rightActionManager(void) noexcept
{
	if (this->_buttonStatus == BTN_VIDEO_WALL) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_config->_wallDensity += 5;
		if (this->_config->_wallDensity > 100)
			this->_config->_wallDensity = 100;
	} else if (this->_buttonStatus == BTN_VIDEO_BLOCK) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_config->_blockDensity += 5;
		if (this->_config->_blockDensity > 100)
			this->_config->_blockDensity = 100;
	} else if (this->_buttonStatus == BTN_VIDEO_QUALITY) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_qualityStatus++;
		if (this->_qualityStatus > 4)
			this->_qualityStatus = 0;
		else if (this->_qualityStatus < 0)
			this->_qualityStatus = 4;
	} else if (this->_buttonStatus == BTN_VIDEO_MAP) {
		this->_sounds->_buttonSwitchSound->playSound();
		this->_mapStatus++;
		if (this->_mapStatus > 2)
			this->_mapStatus = 0;
		else if (this->_mapStatus < 0)
			this->_mapStatus = 2;
	}
}

void IndieStudio::MenuVideo::upActionManager(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(-1, 3);
}

void IndieStudio::MenuVideo::downActionManager(void) noexcept
{
	this->_sounds->_buttonSwitchSound->playSound();
	this->setButtonSwitch(1, 3);
}

void IndieStudio::MenuVideo::alphaActionManager(IndieStudio::Key key) noexcept
{
}

void IndieStudio::MenuVideo::alphaAction(IndieStudio::Key key) noexcept
{
}