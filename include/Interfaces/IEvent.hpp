/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Event
*/

#ifndef IEVENT_HPP_
#define IEVENT_HPP_

#include <map>

namespace IndieStudio {
	enum Key {
		A = 'A',
		B = 'B',
		C = 'C',
		D = 'D',
		E = 'E',
		F = 'F',
		G = 'G',
		H = 'H',
		I = 'I',
		J = 'J',
		K = 'K',
		L = 'L',
		M = 'M',
		N = 'N',
		O = 'O',
		P = 'P',
		Q = 'Q',
		R = 'R',
		S = 'S',
		T = 'T',
		U = 'U',
		V = 'V',
		W = 'W',
		X = 'X',
		Y = 'Y',
		Z = 'Z',
		RETURN,
		ESC,
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		null = 0
	};
	class IEvent {
	public:
		virtual ~IEvent() = default;
		std::map<IndieStudio::Key, bool> _key;
		std::map<IndieStudio::Key, bool> _keyRelease;
	};
}; // namespace IndieStudio

#endif