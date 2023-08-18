/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Audio.hpp"
#include "Character.hpp"
#include "IEntity.hpp"
#include "IGraphical.hpp"
#include "Map.hpp"

namespace IndieStudio {
	class Bomb {
	public:
		Bomb(IndieStudio::IGraphical &graphical, IndieStudio::Pos vector, int bombSize, IndieStudio::Map &map, std::vector<std::shared_ptr<IndieStudio::Bomb>> &bombVec, std::vector<std::shared_ptr<IndieStudio::Character>> &characterVec, std::shared_ptr<IndieStudio::Audio> audio, const IndieStudio::Config *config);
		~Bomb();
		void createParticule(IndieStudio::Pos vector) noexcept;
		void startCountdown(void);
		void explosion(void);
		bool getAlive(void) const noexcept;
		bool getTotalDeath(void) const noexcept;
		IndieStudio::Pos getPosition(void) const noexcept;
		IndieStudio::Pos getLastPosition(void) const noexcept;
		int getBombSize() noexcept;
		IndieStudio::IEntity *getEntity(void) const noexcept;

	private:
		std::size_t getAliveCharacter() const noexcept;
		void checkHitCube(std::vector<IndieStudio::Pos> pos, std::vector<bool> &boolVec);
		void checkHitBomb(std::vector<IndieStudio::Pos> pos, std::vector<bool> &boolVec);
		void checkHitPlayer(std::vector<IndieStudio::Pos> pos, std::vector<bool> &boolVec);
		void playExplosionSound(void) noexcept;
		void destroyExplosionParticle(void);
		void createAutoParticle(IndieStudio::Pos position, int lifeTime);
		void checkHit(IndieStudio::Pos position, std::vector<bool> boolVec);

	private:
		const IndieStudio::Config *_config;
		IndieStudio::IGraphical &_graphical;
		IndieStudio::Map &_map;
		IndieStudio::IEntity *_bomb;
		IndieStudio::IEntity *_particle;
		IndieStudio::Pos _lastPos = IndieStudio::Pos{0,0,0};
		std::shared_ptr<IndieStudio::Audio> _sound;
		std::vector<IndieStudio::IEntity *> _explosionParticule;
		std::vector<std::shared_ptr<IndieStudio::Bomb>> &_bombVec;
		std::vector<std::shared_ptr<IndieStudio::Character>> &_characterVec;
		bool _alive = true;
		bool _totalDeath = false;
		int _bombSize;
	};
}; // namespace IndieStudio

#endif