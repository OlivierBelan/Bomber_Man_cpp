/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuLoad
*/

#ifndef MENULOAD_HPP_
#define MENULOAD_HPP_

static const int MENU_LOAD_MAIN = 0;
static const int MENU_LOAD_BACK = 1;

#include "Menu.hpp"

namespace IndieStudio
{
class MenuLoad : public Menu
{
public:
	MenuLoad(IGraphical &, Volume *, MenuSounds *);
	~MenuLoad();

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
	IEntity *_comingsoon;
	IEntity *_escapeInfo;
};
}; // namespace IndieStudio

#endif /* !MENULOAD_HPP_ */
