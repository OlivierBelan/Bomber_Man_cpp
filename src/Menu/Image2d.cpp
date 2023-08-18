/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Image2d
*/

#include "Image2d.hpp"

IndieStudio::Image2d::Image2d(irr::video::IVideoDriver *driver, std::string str, std::pair<int, int> position)
	: _driver(driver)
{
	setTexture(str);
	_position = irr::core::position2d<irr::s32>(position.first, position.second);
	setFullRectangle();
	if (position.first == -1)
		setPositionToMid();
}

IndieStudio::Image2d::~Image2d()
{
}

void IndieStudio::Image2d::setFullRectangle(void) noexcept
{
	irr::core::dimension2d<irr::u32> taille = _image->getSize();
	irr::core::position2d<irr::s32> position0;
	position0.X = 0;
	position0.Y = 0;
	irr::core::position2d<irr::s32> position1;
	position1.X = taille.Width;
	position1.Y = taille.Height;
	irr::core::rect<irr::s32> rectangle;
	rectangle.UpperLeftCorner = position0;
	rectangle.LowerRightCorner = position1;
	_rectangle = rectangle;
}

void IndieStudio::Image2d::setCustomRectangle(int p0X, int p0Y, int p1X, int p1Y) noexcept
{
	irr::core::position2d<irr::s32> position0;
	position0.X = p0X;
	position0.Y = p0Y;
	irr::core::position2d<irr::s32> position1;
	position1.X = p1X;
	position1.Y = p1Y;
	irr::core::rect<irr::s32> rectangle;
	rectangle.UpperLeftCorner = position0;
	rectangle.LowerRightCorner = position1;
	_rectangle = rectangle;
}

void IndieStudio::Image2d::setPositionToMid(void) noexcept
{
	irr::core::dimension2d<irr::u32> screen = _driver->getScreenSize();
	_position.X = screen.Width / 2 - _rectangle.LowerRightCorner.X / 2;
}

void IndieStudio::Image2d::drawImage(void) noexcept
{
	_driver->draw2DImage(_image, _position, _rectangle, 0, irr::video::SColor(255, 255, 255, 255), true);
}

void IndieStudio::Image2d::setTexture(std::string skin) noexcept
{
	_image = _driver->getTexture(skin.c_str());
}