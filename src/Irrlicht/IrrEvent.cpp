/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IrrEvent
*/

#include "IrrEvent.hpp"
#include "iostream"

IndieStudio::IrrEvent::IrrEvent()
{
	for (auto key_it = this->_key.begin(); key_it != this->_key.end(); key_it++)
		key_it->second = false;
}

IndieStudio::IrrEvent::~IrrEvent()
{
}

void IndieStudio::IrrEvent::update(const irr::SEvent &event) noexcept
{
	for (auto dic_it = this->_keyDic.begin(); dic_it != this->_keyDic.end(); dic_it++)
		if (dic_it->second == event.KeyInput.Key)
			this->_key[dic_it->first] = event.KeyInput.PressedDown;
	if (!event.KeyInput.PressedDown)
	{
		for (auto dic_it = this->_keyDic.begin(); dic_it != this->_keyDic.end(); dic_it++)
		{
			if (dic_it->second == event.KeyInput.Key)
			{
				this->_keyRelease[dic_it->first] = true;
			}
			else
			{
				this->_keyRelease[dic_it->first] = false;
			}
		}
	}
}