/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <irrlicht.h>
#include <iostream>

#include "Image2d.hpp"
#include "IGraphical.hpp"

namespace IndieStudio
{
class Button
{
public:
	Button(IGraphical &, std::string, std::string, std::pair<int, int>);
	~Button();

	void drawButton(void) noexcept;
	void setDefaultSkin(void) noexcept;
	void setActiveSkin(void) noexcept;
	void setPosition(std::pair<int, int>) noexcept;

private:
	bool _active;

	IEntity *_image;

	std::string _skinDefault;
	std::string _skinActive;

	IGraphical &_graphical;
};
}; // namespace IndieStudio

#endif /* !BUTTON_HPP_ */
