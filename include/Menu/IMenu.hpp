/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IMenu
*/

#ifndef IMENU_HPP_
#define IMENU_HPP_

class IMenu
{
public:
	virtual ~IMenu() = default;

private:
	virtual void drawMenu(void) noexcept = 0;
	virtual void drawMenuManager(void) noexcept = 0;
	virtual void createButtons(void) noexcept = 0;
	virtual void drawButtons(void) noexcept = 0;
	virtual void createImages(void) noexcept = 0;
	virtual void drawImages(void) noexcept = 0;

	virtual void checkActions(void) noexcept = 0;
	virtual void returnAction(void) noexcept = 0;
	virtual void returnActionManager(void) noexcept = 0;
	virtual void escapeAction(void) noexcept = 0;
	virtual void escapeActionManager(void) noexcept = 0;
	virtual void leftAction(void) noexcept = 0;
	virtual void leftActionManager(void) noexcept = 0;
	virtual void rightAction(void) noexcept = 0;
	virtual void rightActionManager(void) noexcept = 0;
	virtual void upAction(void) noexcept = 0;
	virtual void upActionManager(void) noexcept = 0;
	virtual void downAction(void) noexcept = 0;
	virtual void downActionManager(void) noexcept = 0;

	virtual void refreshSkin(void) noexcept = 0;
	virtual void setButtonSwitch(int, int) noexcept = 0;
	virtual void setMenuActive(int) noexcept = 0;
	virtual int getCurrentMenuActive(void) const noexcept = 0;
	virtual void setButtonActive(int) noexcept = 0;
	virtual int getCurrentButtonActive(void) const noexcept = 0;
};

#endif /* !IMENU_HPP_ */
