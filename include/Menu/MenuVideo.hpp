/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuLoad
*/

#ifndef MENUVIDEO_HPP_
#define MENUVIDEO_HPP_

static const int MENU_VIDEO_MAIN = 0;
static const int MENU_VIDEO_BACK = 1;

static const int BTN_VIDEO_BLOCK = 0;
static const int BTN_VIDEO_WALL = 1;
static const int BTN_VIDEO_QUALITY = 2;
static const int BTN_VIDEO_MAP = 3;

static const int QUALITY_LOW = 0;
static const int QUALITY_STANDARD = 1;
static const int QUALITY_HIGH = 2;
static const int QUALITY_VERY = 3;
static const int QUALITY_ULTRA = 4;

static const int MAP_SMALL = 0;
static const int MAP_MEDIUM = 1;
static const int MAP_LARGE = 2;

#include "Menu.hpp"

namespace IndieStudio
{
class MenuVideo : public Menu
{
public:
	MenuVideo(IGraphical &, Volume *, MenuSounds *, Config *);
	~MenuVideo();

public:
	void drawMenuManager(void) noexcept override;
	void returnActionManager(void) noexcept override;
	void escapeActionManager(void) noexcept override;
	void leftActionManager(void) noexcept override;
	void rightActionManager(void) noexcept override;
	void upActionManager(void) noexcept override;
	void downActionManager(void) noexcept override;
	void alphaActionManager(IndieStudio::Key) noexcept override;

private:
	void drawMenu(void) noexcept override;
	void createButtons(void) noexcept override;
	void drawButtons(void) noexcept override;
	void createImages(void) noexcept override;
	void drawImages(void) noexcept override;

	void checkActions(void) noexcept override;
	void returnAction(void) noexcept override;
	void escapeAction(void) noexcept override;
	void leftAction(void) noexcept override;
	void rightAction(void) noexcept override;
	void upAction(void) noexcept override;
	void downAction(void) noexcept override;
	void alphaAction(IndieStudio::Key) noexcept override;

	void refreshSkin(void) noexcept override;

private:
	int _mapStatus;
	int _qualityStatus;
	IEntity *_escapeInfo;

	Button *_block;
	Button *_wall;
	Button *_quality;
	Button *_map;

	Button *_low;
	Button *_standard;
	Button *_high;
	Button *_very;
	Button *_ultra;

	Button *_small;
	Button *_medium;
	Button *_large;
};
}; // namespace IndieStudio

#endif /* !MENULOAD_HPP_ */
