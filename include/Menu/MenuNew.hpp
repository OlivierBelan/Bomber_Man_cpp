/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuNew
*/

#ifndef MENUNEW_HPP_
#define MENUNEW_HPP_

static const int MENU_NEW_GAME = -1;
static const int MENU_NEW_MAIN = 0;
static const int MENU_NEW_BACK = 1;

static const int MODE_SOLO = 0;
static const int MODE_COOP = 1;
static const int MODE_DUEL = 2;

static const int PLAYER1_BOB = 0;
static const int PLAYER1_CARTMAN = 1;
static const int PLAYER1_STARFOX = 2;
static const int PLAYER1_YOSHI = 3;

static const int PLAYER2_BOB = 0;
static const int PLAYER2_CARTMAN = 1;
static const int PLAYER2_STARFOX = 2;
static const int PLAYER2_YOSHI = 3;

static const int BTN_TOOL_PLAY = 0;
static const int BTN_TOOL_BACK = 1;

static const int BTN_NEW_GAMEMODE = 0;
static const int BTN_NEW_PLAYER1 = 1;
static const int BTN_NEW_PLAYER2 = 2;
static const int BTN_NEW_PLAY = 3;

#include "Menu.hpp"

namespace IndieStudio
{
struct Arrow
{
	Button *btn;
	int c;
};

class MenuNew : public Menu
{
public:
	MenuNew(IGraphical &, Volume *, MenuSounds *, Config *);
	~MenuNew();

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
	int _modeStatus;
	int _player1Status;
	int _player2Status;
	int _toolStatus;

	Button *_gamemode;
	Button *_player1;
	Button *_player2;

	Button *_solo;
	Button *_coop;
	Button *_duel;

	Button *_bob1;
	Button *_cartman1;
	Button *_starfox1;
	Button *_yoshi1;

	Button *_bob2;
	Button *_cartman2;
	Button *_starfox2;
	Button *_yoshi2;

	IEntity *_bobPreview;
	IEntity *_cartmanPreview;
	IEntity *_starfoxPreview;
	IEntity *_yoshiPreview;

	Arrow _left1;
	Arrow _right1;

	Arrow _left2;
	Arrow _right2;

	Arrow _left3;
	Arrow _right3;

	Button *_back;
	Button *_play;
};
}; // namespace IndieStudio

#endif /* !MENUNEW_HPP_ */
