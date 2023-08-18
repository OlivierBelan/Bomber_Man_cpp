/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Save
*/

#pragma once

#include "Character.hpp"
#include "IGraphical.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

static const std::string MAP_TXT_PATH = "save/map.txt";
static const std::string PLAYER_TXT_PATH = "save/player.txt";

namespace IndieStudio {
	class Save {
	public:
		Save(IndieStudio::IGraphical &graphical, IndieStudio::playerKeybinds player1Key, IndieStudio::playerKeybinds player2Key);
		Save(std::vector<IndieStudio::IEntity *> const &, std::vector<IndieStudio::IEntity *> const &, std::vector<IndieStudio::IEntity *> const &, std::vector<std::shared_ptr<IndieStudio::Character>>, float, float, float, IndieStudio::IGraphical &);
		~Save();
		void setBrickVec(std::vector<IndieStudio::IEntity *> const &) noexcept;
		void setWallOutsideVec(std::vector<IndieStudio::IEntity *> const &) noexcept;
		void setWallInsideVec(std::vector<IndieStudio::IEntity *> const &) noexcept;
		void setDimensionMap(float, float, float) noexcept;
		void setCharacterVec(std::vector<std::shared_ptr<IndieStudio::Character>>) noexcept;
		std::vector<std::string> getMap() noexcept;
		void createSave() noexcept;
		std::string getMapFile() noexcept;
		std::vector<std::string> getMapByTxt() noexcept;
		void configPlayerByTxt(std::vector<std::shared_ptr<IndieStudio::Character>> &) noexcept;
		std::size_t getPlayerNb() noexcept;

	private:
		void generateSave() noexcept;
		void generateMap() noexcept;
		void generatePlayerPosition() noexcept;
		std::vector<std::string> getTxt(std::string) noexcept;
		std::vector<std::string> splitTxt(std::string, std::string) noexcept;
		std::string reverseStr(std::string &str) noexcept;

	private:
		IndieStudio::playerKeybinds _player1Key;
		IndieStudio::playerKeybinds _player2Key;
		std::vector<std::string> _mapTxt;
		std::vector<std::string> _playerPosition;
		std::vector<IndieStudio::IEntity *> _brickVec;
		std::vector<IndieStudio::IEntity *> _wallOutsideVec;
		std::vector<IndieStudio::IEntity *> _wallInsideVec;
		std::vector<std::shared_ptr<IndieStudio::Character>> _characterVec;
		IndieStudio::IGraphical &_graphical;
		float _x_map = 0;
		float _y_map = 0;
		float _cube_size = 0;
	};
} // namespace IndieStudio