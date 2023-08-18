/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MenuSounds
*/

#ifndef MENUSOUNDS_HPP_
#define MENUSOUNDS_HPP_

#include "Volume.hpp"

namespace IndieStudio
{
class MenuSounds
{
public:
	MenuSounds(Volume *);
	~MenuSounds();

private:
	Volume *_volume;

public:
	Audio *_volumeSwitchSound;
	Audio *_buttonSwitchSound;
	Audio *_buttonReturnSound;
};
}; // namespace IndieStudio

#endif /* !MENUSOUNDS_HPP_ */
