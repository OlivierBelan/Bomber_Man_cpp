/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <irrlicht.h>
#include <iostream>

#include "IMenu.hpp"
#include "Button.hpp"
#include "Config.hpp"
#include "Volume.hpp"
#include "IGraphical.hpp"
#include "MenuSounds.hpp"

namespace IndieStudio
{
class Menu : public IMenu
{
public:
	Menu(IGraphical &, Volume *, MenuSounds *, Config *config = nullptr);

	virtual void setButtonSwitch(int, int) noexcept;
	virtual void setMenuActive(int) noexcept;
	virtual int getCurrentMenuActive(void) const noexcept;
	virtual void setButtonActive(int) noexcept;
	virtual int getCurrentButtonActive(void) const noexcept;
	virtual void alphaAction(IndieStudio::Key) noexcept = 0;
	virtual void alphaActionManager(IndieStudio::Key) noexcept = 0;

protected:
	int _renderStatus;
	int _buttonStatus;

	Config *_config;
	Volume *_volume;
	MenuSounds *_sounds;
	IGraphical &_graphical;
};
};	 // namespace IndieStudio
#endif /* !IMENU_HPP_ */
