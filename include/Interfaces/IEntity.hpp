/*
** EPITECH PROJECT, 2019
** test
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
#define IENTITY_HPP_

#include "IEntity.hpp"

namespace IndieStudio {
	class Pos {
		public:
			Pos(float x, float y, float z) : _x(x), _y(y), _z(z) {};
			float _x;
			float _y;
			float _z;
			bool operator ==(const Pos &p) {
				if (p._x == this->_x && p._z == this->_z)
					return (true);
				return (false);
			};
			bool operator !=(const Pos &p) {
				return (!(*this == p));
			};
	};
	class IEntity {
		public:
			virtual ~IEntity() = default;
			virtual IndieStudio::Pos getPosition(void) const noexcept = 0;
			virtual void setPosition(IndieStudio::Pos) noexcept = 0;
			virtual void setRotation(IndieStudio::Pos) noexcept = 0;
			virtual void setAnimation(int) noexcept = 0;
			virtual void setScale(IndieStudio::Pos) noexcept = 0;
	};
};

#endif