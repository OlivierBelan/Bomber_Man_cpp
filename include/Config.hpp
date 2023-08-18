/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include "IEvent.hpp"

namespace IndieStudio {
	struct playerKeybinds
	{
		Key up;
		Key down;
		Key left;
		Key right;
		Key bomb;
	};

	enum Mode {
		SOLO,
		COOP,
		DUEL,
		CONTINUE,
		RESET
	};
	class Config {
	public:
		Config();
		~Config();

		Mode getMode(void) const noexcept;
		void setMode(Mode) noexcept;

		int getQuality(void) const noexcept;
		void setQuality(int) noexcept;

		Mode getPrevMode(void) const noexcept;
		void setPrevMode(Mode) noexcept;

		std::string getPlayer1Skin(void) const noexcept;
		std::string getPlayer2Skin(void) const noexcept;
		void setPlayer1Skin(std::string) noexcept;
		void setPlayer2Skin(std::string) noexcept;

		playerKeybinds getKeybinds1(void) const noexcept;
		playerKeybinds getKeybinds2(void) const noexcept;
		void setKeybinds1(playerKeybinds) noexcept;
		void setKeybinds2(playerKeybinds) noexcept;

		int getMapSize(void) const noexcept;
		int getWallDensity(void) const noexcept;
		int getBlockDensity(void) const noexcept;

		int _mapSize;
		int _wallDensity;
		int _blockDensity;
	private:
		Mode _mode;
		int _quality;
		Mode _prevMode;

		std::string _player1Skin;
		std::string _player2Skin;

		playerKeybinds _player1;
		playerKeybinds _player2;
	};
}; // namespace IndieStudio

#endif /* !CONFIG_HPP_ */
