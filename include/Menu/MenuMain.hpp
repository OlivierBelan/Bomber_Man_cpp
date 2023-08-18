/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuMain
*/

#ifndef MENUMAIN_HPP_
#define MENUMAIN_HPP_

static const int MENU_MAIN_GAME = -1;
static const int MENU_MAIN_MAIN = 0;
static const int MENU_MAIN_NEWGAME = 1;
static const int MENU_MAIN_LOADGAME = 2;
static const int MENU_MAIN_OPTIONS = 3;
static const int MENU_MAIN_EXIT = 4;

static const int BTN_MAIN_NEWGAME = 0;
static const int BTN_MAIN_LOADGAME = 1;
static const int BTN_MAIN_OPTIONS = 2;
static const int BTN_MAIN_EXIT = 3;

#include "Menu.hpp"
#include "MenuNew.hpp"
#include "MenuOptions.hpp"
#include "MenuLoad.hpp"

namespace IndieStudio
{
class MenuMain : public Menu
{
public:
	MenuMain(IGraphical &, Volume *, MenuSounds *, Config *);
	~MenuMain();

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
	MenuNew *_menuNew;
	MenuLoad *_menuLoad;
	MenuOptions *_menuOptions;

	Button *_newGame;
	Button *_loadGame;
	Button *_options;
	Button *_exit;

	IEntity *_wall;
	IEntity *_frameMenu;
	IEntity *_titleMenu;
};
}; // namespace IndieStudio

#endif /* !MENUMAIN_HPP_ */