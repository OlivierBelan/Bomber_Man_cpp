/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "Audio.hpp"
#include "Config.hpp"
#include "IGraphical.hpp"
#include <iostream>
#include <list>

static const float SPEED = 2.5f;
static const int BOMBMAX = 2;
static const int BOMBSIZE = 1;

namespace IndieStudio {
	typedef struct character_assets_s
	{
		std::string mesh;
		std::string texture;
		std::string deathSound;
	} character_assets_t;

	class Character {
	public:
		Character(IndieStudio::IGraphical &graphical, std::string name, bool bot, IndieStudio::Pos position = IndieStudio::Pos(0, 0, 0), IndieStudio::playerKeybinds keys = {Key::null, Key::null, Key::null, Key::null, Key::null});
		~Character();
		char getUpKey() const noexcept;
		char getLeftKey() const noexcept;
		char getDownKey() const noexcept;
		char getRightKey() const noexcept;
		char getActionKey() const noexcept;

		void setMovingUp(bool) noexcept;
		void setMovingLeft(bool) noexcept;
		void setMovingDown(bool) noexcept;
		void setMovingRight(bool) noexcept;
		void setDoingAction(bool) noexcept;

		bool getMovingUp() const noexcept;
		bool getMovingLeft() const noexcept;
		bool getMovingDown() const noexcept;
		bool getMovingRight() const noexcept;
		bool getDoingAction() const noexcept;

		bool getIsMoving() const noexcept;
		void setIsMoving(bool) noexcept;

		float getSpeed() const noexcept;
		void setSpeed(float) noexcept;

		int get_Bomb_Current() const noexcept;
		void set_Bomb_Current(int) noexcept;

		int getBombSize() const noexcept;
		void setBombSize(int) noexcept;

		int getBombMax() const noexcept;
		void setBombMax(int) noexcept;

		IndieStudio::IEntity *getEntity() noexcept;
		void playDeathSound(bool b = false) noexcept;

		void setPosition(IndieStudio::Pos) noexcept;
		IndieStudio::Pos getPosition() noexcept;

		IndieStudio::Pos getSpawnPos() const noexcept;
		void setBonus(float, int, int) noexcept;

		void death(void) noexcept;
		bool getDeath(void) const noexcept;
		void setDeath(bool) noexcept;

		bool getBot() noexcept;
		void setBot(bool) noexcept;

		std::string getName(void) const noexcept;

	private:
		IndieStudio::IGraphical &_graphical;
		IndieStudio::IEntity *_model;
		std::shared_ptr<IndieStudio::Audio> _deathSound;
		IndieStudio::Pos _spawnPos;

		std::string _name;
		bool _bot;
		char _up;
		char _left;
		char _down;
		char _right;
		char _action;
		bool _movingUp = false;
		bool _movingLeft = false;
		bool _movingDown = false;
		bool _movingRight = false;
		bool _doingAction = false;
		bool _isMoving = false;
		bool _death = false;
		float _speed = SPEED;
		int _bomb_Max = BOMBMAX;
		int _bomb_current = 0;
		int _bombSize = BOMBSIZE;
	};
}; // namespace IndieStudio

#endif