/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Config
*/

#include "Config.hpp"

IndieStudio::Config::Config() : _prevMode(IndieStudio::Mode::SOLO)
{
	this->_player1.up = Z;
	this->_player1.down = S;
	this->_player1.left = Q;
	this->_player1.right = D;
	this->_player1.bomb = E;

	this->_player2.up = I;
	this->_player2.down = K;
	this->_player2.left = J;
	this->_player2.right = L;
	this->_player2.bomb = O;

	this->_quality = 64;
	this->_wallDensity = 100;
	this->_blockDensity = 50;
	this->_mapSize = 15;
}

IndieStudio::Config::~Config()
{
}

IndieStudio::Mode IndieStudio::Config::getMode(void) const noexcept
{
	return this->_mode;
}

void IndieStudio::Config::setMode(IndieStudio::Mode mode) noexcept
{
	this->_mode = mode;
}

int IndieStudio::Config::getQuality(void) const noexcept
{
	return this->_quality;
}

void IndieStudio::Config::setQuality(int quality) noexcept
{
	this->_quality = quality;
}

std::string IndieStudio::Config::getPlayer1Skin(void) const noexcept
{
	return this->_player1Skin;
}

std::string IndieStudio::Config::getPlayer2Skin(void) const noexcept
{
	return this->_player2Skin;
}

void IndieStudio::Config::setPlayer1Skin(std::string skin) noexcept
{
	this->_player1Skin = skin;
}

void IndieStudio::Config::setPlayer2Skin(std::string skin) noexcept
{
	this->_player2Skin = skin;
}

IndieStudio::playerKeybinds IndieStudio::Config::getKeybinds1(void) const noexcept
{
	return this->_player1;
}

IndieStudio::playerKeybinds IndieStudio::Config::getKeybinds2(void) const noexcept
{
	return this->_player2;
}

void IndieStudio::Config::setKeybinds1(IndieStudio::playerKeybinds keyBinds) noexcept
{
	this->_player1 = keyBinds;
}

void IndieStudio::Config::setKeybinds2(IndieStudio::playerKeybinds keyBinds) noexcept
{
	this->_player2 = keyBinds;
}

IndieStudio::Mode IndieStudio::Config::getPrevMode(void) const noexcept
{
	return (this->_prevMode);
}

void IndieStudio::Config::setPrevMode(Mode mode) noexcept
{
	this->_prevMode = mode;
}

int IndieStudio::Config::getBlockDensity(void) const noexcept
{
	return (this->_blockDensity);
}

int IndieStudio::Config::getWallDensity(void) const noexcept
{
	return (this->_wallDensity);
}

int IndieStudio::Config::getMapSize(void) const noexcept
{
	return (this->_mapSize);
}