/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** MusicManager
*/

#ifndef MUSICMANAGER_HPP_
#define MUSICMANAGER_HPP_

#include "Volume.hpp"
#include "IGraphical.hpp"

namespace IndieStudio
{
class MusicManager
{
public:
	MusicManager(Volume *);
	~MusicManager();

	void refreshMusic(Render &) noexcept;

private:
	Volume *_volume;

	Audio *_menuMusic;
	Audio *_gameMusic;
};
}; // namespace IndieStudio

#endif /* !MUSICMANAGER_HPP_ */
