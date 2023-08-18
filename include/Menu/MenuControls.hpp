/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuLoad
*/

#ifndef MENUCONTROLS_HPP_
#define MENUCONTROLS_HPP_

static const int MENU_CONTROLS_MAIN = 0;
static const int MENU_CONTROLS_BACK = 1;

static const int MENU_CONTROLS_PLY_1 = 0;
static const int MENU_CONTROLS_PLY_2 = 1;

static const int BTN_CONTROLS_UP = 0;
static const int BTN_CONTROLS_DOWN = 1;
static const int BTN_CONTROLS_LEFT = 2;
static const int BTN_CONTROLS_RIGHT = 3;
static const int BTN_CONTROLS_BOMB = 4;

#include "Menu.hpp"

namespace IndieStudio
{

struct letter
{
	char _id;
	Button *_btn;
	Key _key;
};

struct KeyB
{
	Key _key;
	bool _status;
};

class MenuControls : public Menu
{
public:
	MenuControls(IGraphical &, Volume *, MenuSounds *, Config *);
	~MenuControls();
	void createLetters(void) noexcept;
	void drawLetter(KeyB, std::pair<int, int>) noexcept;
	bool checkKey(Key) noexcept;

public:
	void drawMenuManager(void) noexcept override;
	void returnActionManager(void) noexcept override;
	void escapeActionManager(void) noexcept override;
	void leftActionManager(void) noexcept override;
	void rightActionManager(void) noexcept override;
	void upActionManager(void) noexcept override;
	void downActionManager(void) noexcept override;
	void alphaActionManager(Key) noexcept override;

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
	int _playerStatus;

	Button *_player1;
	Button *_player2;
	IEntity *_escapeInfo;

	Button *_upBtn1;
	Button *_downBtn1;
	Button *_leftBtn1;
	Button *_rightBtn1;
	Button *_bombBtn1;

	Button *_upBtn2;
	Button *_downBtn2;
	Button *_leftBtn2;
	Button *_rightBtn2;
	Button *_bombBtn2;

	std::vector<letter> _letters;

	KeyB _upKey1;
	KeyB _downKey1;
	KeyB _leftKey1;
	KeyB _rightKey1;
	KeyB _bombKey1;

	KeyB _upKey2;
	KeyB _downKey2;
	KeyB _leftKey2;
	KeyB _rightKey2;
	KeyB _bombKey2;
};
}; // namespace IndieStudio

#endif /* !MENULOAD_HPP_ */
