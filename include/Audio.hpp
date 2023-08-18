/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <SFML/Audio.hpp>

namespace IndieStudio {
	class Audio {
		public:
			Audio(std::string audioPath, bool loop = false);
			~Audio();
			void playSound(bool forced = false) noexcept;
			void stopSound(void) noexcept;
			void pauseSound(void) noexcept;
			int getSoundStatus(void) const noexcept;
			float getVolume(void) const noexcept;
			void setVolume(int) noexcept;
		private:
			sf::SoundBuffer _soundBuffer;
			sf::Sound _sound;
	};
};

#endif