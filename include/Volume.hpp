/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Volume
*/

#ifndef VOLUME_HPP_
#define VOLUME_HPP_

#include "Audio.hpp"

namespace IndieStudio {
	class Volume {
	public:
		Volume();
		~Volume();

		int getVolumeMusics(void) const noexcept;
		int getVolumeEffects(void) const noexcept;
		void setVolumeMusics(int) noexcept;
		void setVolumeEffects(int) noexcept;
		void refreshVolumeMusics(void) noexcept;
		void refreshVolumeEffects(void) noexcept;
		void refreshVolume(void) noexcept;
		Audio *createSoundMusic(std::string, bool loop = false) noexcept;
		Audio *createSoundEffect(std::string, bool loop = false) noexcept;

	private:
		int _volumeMusics = 50;
		int _volumeEffects = 50;

		std::vector<IndieStudio::Audio *> _soundsMusics;
		std::vector<IndieStudio::Audio *> _soundsEffects;
	};
}; // namespace IndieStudio

#endif