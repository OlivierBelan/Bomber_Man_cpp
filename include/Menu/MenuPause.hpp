/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuPause
*/

#ifndef MENUPAUSE_HPP_
#define MENUPAUSE_HPP_

static const int MENU_PAUSE_MAIN = 0;
static const int MENU_PAUSE_BACK = 1;
static const int MENU_PAUSE_RESTART = 2;
static const int MENU_PAUSE_OPTIONS = 3;
static const int MENU_PAUSE_QUIT = 4;

static const int BTN_PAUSE_BACK = 0;
static const int BTN_PAUSE_RESTART = 1;
static const int BTN_PAUSE_OPTIONS = 2;
static const int BTN_PAUSE_QUIT = 3;

#include "Menu.hpp"
#include "MenuRestart.hpp"
#include "MenuOptions.hpp"

namespace IndieStudio
{
class MenuPause : public Menu
{
public:
	MenuPause(IGraphical &, Volume *, MenuSounds *, Config *);
	~MenuPause();

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
	MenuRestart *_menuRestart;
	MenuOptions *_menuOptions;

	Button *_back;
	Button *_restart;
	Button *_options;
	Button *_quit;

	IEntity *_wall;
	IEntity *_frameMenu;
	IEntity *_titleMenu;
};
}; // namespace IndieStudio

#endif /* !MENUPAUSE_HPP_ */
