/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "Bomb.hpp"
#include "Bonus.hpp"
#include "Character.hpp"
#include "Config.hpp"
#include "IEntity.hpp"
#include "IGraphical.hpp"
#include "IaMouvement.hpp"
#include "Map.hpp"
#include "Save.hpp"
#include <iostream>
#include <thread>
#include <vector>

static const int SIZE_MAP_X = 15;
static const int SIZE_MAP_Y = 15;
static const int DENSITY_BRICK = 10;
static const int DENSITY_WALL = 100;
static const int DENSITY_BONUS = 10;

namespace IndieStudio {
	class Game {
	public:
		Game(IndieStudio::IGraphical &graphical, Render &render, const IndieStudio::Config *);
		~Game();

	public:
		void render(void) noexcept;
		bool isOver(void) const noexcept;
		void destroy(void) noexcept;
		bool checkDeleteBomb() noexcept;

	private:
		void reset() noexcept;
		void playIntro() noexcept;
		std::size_t getAliveCharacter() const noexcept;
		void playEnding();
		void createCubes() noexcept;
		void createCharacters() noexcept;
		void createCubeColision(IndieStudio::IEntity *cube) noexcept;
		virtual int getRenderStatus(void) const noexcept;
		virtual void setRenderStatus(int) noexcept;
		virtual void checkEvent(void) noexcept;
		void moveCharacter() noexcept;
		void mapRender() noexcept;
		void bonusRender() noexcept;
		void setMapCollision() noexcept;
		void setCameraPosition(int x, int y) noexcept;
		void setSave() noexcept;
	private:
		const IndieStudio::Config *_config;
		std::shared_ptr<IndieStudio::Audio> _bombSound;
		IndieStudio::Map _map;
		IndieStudio::Bonus _bonus;
		IndieStudio::Save _save;
		std::vector<IndieStudio::IaMouvement> _iaMouvement;
		int _renderStatus = MAIN_MENU;
		IndieStudio::IGraphical &_graphical;
		std::vector<std::shared_ptr<IndieStudio::Character>> _characterVec;
		std::vector<std::shared_ptr<IndieStudio::Bomb>> _bombVec;
		std::vector<std::thread> _th;
		IndieStudio::IEvent _event;
		float _rot_x = 100;
		float _rot_y = 0;
		float _rot_z = 0;
		float _counter = 0;
		bool _bonus_bool = false;
		IndieStudio::Render &_render;
		bool _win = false;
		bool _isOver = false;
		bool _intro = true;
		int _introNumber = 3;
		bool _create = true;
		IndieStudio::IEntity *_3;
		IndieStudio::IEntity *_2;
		IndieStudio::IEntity *_1;
	};
}; // namespace IndieStudio

#endif