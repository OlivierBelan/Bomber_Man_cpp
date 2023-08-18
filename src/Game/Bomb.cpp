/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "Audio.hpp"
#include <chrono>
#include <iostream>
#include <thread>

#define WALL_SIZE 40
#define EXPLOSION_DURATION 1

void setMiddle(float &vec)
{
	if ((int)(vec + WALL_SIZE / 2) % WALL_SIZE != 0) {
		float f = (int)(vec + WALL_SIZE / 2) % WALL_SIZE;
		vec += (WALL_SIZE / 2 - f);
	} else {
		vec += WALL_SIZE / 2;
	}
	vec = static_cast<int>(vec);
}

int getMiddle(float vec)
{
	if ((int)(vec + WALL_SIZE / 2) % WALL_SIZE != 0) {
		float f = (int)(vec + WALL_SIZE / 2) % WALL_SIZE;
		vec += (WALL_SIZE / 2 - f);
	} else {
		vec += WALL_SIZE / 2;
	}
	vec = static_cast<int>(vec);
	return (vec);
}


IndieStudio::Bomb::Bomb(IndieStudio::IGraphical &graphical, IndieStudio::Pos vector, int bombSize, IndieStudio::Map &map, std::vector<std::shared_ptr<IndieStudio::Bomb>> &bombVec, std::vector<std::shared_ptr<IndieStudio::Character>> &characterVec, std::shared_ptr<IndieStudio::Audio> audio, const IndieStudio::Config *config) :
	_graphical(graphical),
	_map(map),
	_sound(audio),
	_bombSize(bombSize),
	_bombVec(bombVec),
	_bomb(graphical.createMesh("assets/bomb/dinamite.obj")),
	_characterVec(characterVec),
	_config(config)
{
	setMiddle(vector._x);
	setMiddle(vector._z);
	this->_bomb->setScale(IndieStudio::Pos(20, 20, 20));
	this->_bomb->setPosition(vector);
	this->createParticule(vector);
	this->_lastPos = vector;
}

std::size_t IndieStudio::Bomb::getAliveCharacter() const noexcept
{
	std::size_t alive = 0;

	for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
		if (character_it->get()->getDeath() == false)
			alive++;
	return (alive);
}

IndieStudio::Pos IndieStudio::Bomb::getPosition() const noexcept
{
	return (this->_bomb->getPosition());
}

IndieStudio::Bomb::~Bomb()
{
}

void IndieStudio::Bomb::createParticule(IndieStudio::Pos vector) noexcept
{
	this->_particle = this->_graphical.createParticle(
		IndieStudio::Pos(vector._x, vector._y, vector._z),
		IndieStudio::Pos(0.0f, 0.05f, 0.0f),
		3, 10,
		0,
		IndieStudio::Pos(0, 0, 0),
		IndieStudio::Pos(30, 30, 30), 0);
}

void IndieStudio::Bomb::createAutoParticle(IndieStudio::Pos position, int lifeTime)
{
	this->_graphical.createParticle(
		IndieStudio::Pos(
			position._x,
			position._y,
			position._z),
		IndieStudio::Pos(
			0,
			0.01,
			0),
		10, 20,
		2000,
		IndieStudio::Pos(
			255,
			1,
			1),
		IndieStudio::Pos(
			255,
			255,
			255),
		lifeTime);
}

#include <chrono>

void IndieStudio::Bomb::checkHitCube(std::vector<IndieStudio::Pos> posVec, std::vector<bool> &boolVec)
{
	auto bool_it = boolVec.begin();
	for (auto pos_it = posVec.begin(); pos_it != posVec.end(); pos_it++, bool_it++) {
		auto cube = this->_map.get_Cube_By_Position(*pos_it);
		if (cube != nullptr && *bool_it == false) {
			this->_map.delete_Cube(cube);
			*bool_it = true;
		}
	}
}

void IndieStudio::Bomb::checkHitBomb(std::vector<IndieStudio::Pos> posVec, std::vector<bool> &boolVec)
{
	auto bool_it = boolVec.begin();
	for (auto pos_it = posVec.begin(); pos_it != posVec.end(); pos_it++, bool_it++)
		for (auto bomb_it = this->_bombVec.begin(); bomb_it != this->_bombVec.end(); bomb_it++)
			if (bomb_it->get()->getPosition()._x == pos_it->_x && bomb_it->get()->getPosition()._z == pos_it->_z && bomb_it->get()->getAlive() == true && *bool_it == false)
				bomb_it->get()->explosion();
}

void IndieStudio::Bomb::checkHitPlayer(std::vector<IndieStudio::Pos> posVec, std::vector<bool> &boolVec)
{
	posVec.push_back(this->_bomb->getPosition());
	std::thread([this, posVec, boolVec]() {
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
		std::chrono::time_point<std::chrono::system_clock> end;
		while (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() < EXPLOSION_DURATION + 1) {
			end = std::chrono::system_clock::now();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			auto bool_it = boolVec.begin();
			for (auto pos_it = posVec.begin(); pos_it != posVec.end(); pos_it++, bool_it++)
				for (auto character_it = this->_characterVec.begin(); character_it != this->_characterVec.end(); character_it++)
					if (pos_it->_x == getMiddle(character_it->get()->getPosition()._x) && pos_it->_z == getMiddle(character_it->get()->getPosition()._z) && *bool_it == false && character_it->get()->getDeath() == false && this->getAliveCharacter() > 1 && this->_config->getMode() != Mode::RESET)
						character_it->get()->death();
		}
		this->_totalDeath = true;
	}).detach();
}

void IndieStudio::Bomb::checkHit(IndieStudio::Pos position, std::vector<bool> boolVec)
{
	std::vector<IndieStudio::Pos> posVec;
	for (int i = 1; i != _bombSize + 1; i++) {
		posVec.push_back(IndieStudio::Pos(position._x, position._y - 10, position._z + (i * WALL_SIZE)));
		posVec.push_back(IndieStudio::Pos(position._x, position._y - 10, position._z - (i * WALL_SIZE)));
		posVec.push_back(IndieStudio::Pos(position._x + (i * WALL_SIZE), position._y - 10, position._z));
		posVec.push_back(IndieStudio::Pos(position._x - (i * WALL_SIZE), position._y - 10, position._z));
		this->checkHitCube(posVec, boolVec);
		this->checkHitBomb(posVec, boolVec);
		this->checkHitPlayer(posVec, boolVec);
		auto bool_it = boolVec.begin();
		for (auto pos_it = posVec.begin(); pos_it != posVec.end(); pos_it++, bool_it++)
			if (*bool_it == false)
				this->createAutoParticle(*pos_it, EXPLOSION_DURATION);
		posVec.clear();
	}
}

void IndieStudio::Bomb::explosion()
{
	this->_alive = false;
	IndieStudio::Pos position = this->_bomb->getPosition();
	this->createAutoParticle(position, EXPLOSION_DURATION);
	this->checkHit(position, std::vector<bool>{false, false, false, false});
	if (this->_config->getMode() != Mode::RESET)
		this->playExplosionSound();
	this->_graphical.deleteEntity(this->_bomb);
	this->_graphical.deleteEntity(this->_particle);
}

void IndieStudio::Bomb::destroyExplosionParticle()
{
	for (std::vector<IndieStudio::IEntity *>::iterator it = this->_explosionParticule.begin();
		 it != this->_explosionParticule.end(); ++it) {
		this->_graphical.deleteEntity(*it);
	}
}

void IndieStudio::Bomb::playExplosionSound(void) noexcept
{
	this->_sound->playSound(true);
}

void IndieStudio::Bomb::startCountdown(void)
{
	for (int i = 0, j = 22; i != 4; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		this->_bomb->setScale(IndieStudio::Pos(j, j, j));
		j += 2;
	}
	if (this->_alive)
		this->explosion();
}

bool IndieStudio::Bomb::getAlive() const noexcept
{
	return (this->_alive);
}

bool IndieStudio::Bomb::getTotalDeath() const noexcept
{
	return (this->_totalDeath);
}

int IndieStudio::Bomb::getBombSize() noexcept
{
	return (this->_bombSize);
}

IndieStudio::Pos IndieStudio::Bomb::getLastPosition(void) const noexcept
{
	return (this->_lastPos);
}

IndieStudio::IEntity *IndieStudio::Bomb::getEntity(void) const noexcept
{
	return (this->_bomb);
}