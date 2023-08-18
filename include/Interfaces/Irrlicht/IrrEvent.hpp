/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IrrEvent
*/

#ifndef IRREVENT_HPP_
#define IRREVENT_HPP_

#include "IEvent.hpp"
#include <irrlicht.h>

namespace IndieStudio {
	class IrrEvent : public IEvent {
		public:
			IrrEvent();
			~IrrEvent();
			void update(const irr::SEvent &event) noexcept;

		protected:
		private:
			const std::map<IndieStudio::Key, irr::EKEY_CODE> _keyDic = {
				{IndieStudio::Key::A, irr::EKEY_CODE::KEY_KEY_A},
				{IndieStudio::Key::B, irr::EKEY_CODE::KEY_KEY_B},
				{IndieStudio::Key::C, irr::EKEY_CODE::KEY_KEY_C},
				{IndieStudio::Key::D, irr::EKEY_CODE::KEY_KEY_D},
				{IndieStudio::Key::E, irr::EKEY_CODE::KEY_KEY_E},
				{IndieStudio::Key::F, irr::EKEY_CODE::KEY_KEY_F},
				{IndieStudio::Key::G, irr::EKEY_CODE::KEY_KEY_G},
				{IndieStudio::Key::H, irr::EKEY_CODE::KEY_KEY_H},
				{IndieStudio::Key::I, irr::EKEY_CODE::KEY_KEY_I},
				{IndieStudio::Key::J, irr::EKEY_CODE::KEY_KEY_J},
				{IndieStudio::Key::K, irr::EKEY_CODE::KEY_KEY_K},
				{IndieStudio::Key::L, irr::EKEY_CODE::KEY_KEY_L},
				{IndieStudio::Key::M, irr::EKEY_CODE::KEY_KEY_M},
				{IndieStudio::Key::N, irr::EKEY_CODE::KEY_KEY_N},
				{IndieStudio::Key::O, irr::EKEY_CODE::KEY_KEY_O},
				{IndieStudio::Key::P, irr::EKEY_CODE::KEY_KEY_P},
				{IndieStudio::Key::Q, irr::EKEY_CODE::KEY_KEY_Q},
				{IndieStudio::Key::R, irr::EKEY_CODE::KEY_KEY_R},
				{IndieStudio::Key::S, irr::EKEY_CODE::KEY_KEY_S},
				{IndieStudio::Key::T, irr::EKEY_CODE::KEY_KEY_T},
				{IndieStudio::Key::U, irr::EKEY_CODE::KEY_KEY_U},
				{IndieStudio::Key::V, irr::EKEY_CODE::KEY_KEY_V},
				{IndieStudio::Key::W, irr::EKEY_CODE::KEY_KEY_W},
				{IndieStudio::Key::X, irr::EKEY_CODE::KEY_KEY_X},
				{IndieStudio::Key::Y, irr::EKEY_CODE::KEY_KEY_Y},
				{IndieStudio::Key::Z, irr::EKEY_CODE::KEY_KEY_Z},
				{IndieStudio::Key::RETURN, irr::EKEY_CODE::KEY_RETURN},
				{IndieStudio::Key::ESC, irr::EKEY_CODE::KEY_ESCAPE},
				{IndieStudio::Key::KEY_UP, irr::EKEY_CODE::KEY_UP},
				{IndieStudio::Key::KEY_DOWN, irr::EKEY_CODE::KEY_DOWN},
				{IndieStudio::Key::KEY_LEFT, irr::EKEY_CODE::KEY_LEFT},
				{IndieStudio::Key::KEY_RIGHT, irr::EKEY_CODE::KEY_RIGHT},
			};
	};
};

#endif