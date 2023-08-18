/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#include "RenderManager.hpp"
#include "Config.hpp"
#include "Game.hpp"
#include "MenuManager.hpp"
#include "MusicManager.hpp"
#include "Volume.hpp"

IndieStudio::RenderManager::RenderManager(IndieStudio::IGraphical &graphical) :
	_graphical(graphical),
	_musicManager(this->_volume),
	_menu(this->_render, this->_graphical, this->_volume, this->_config)
{
}

IndieStudio::RenderManager::~RenderManager()
{
}

void IndieStudio::RenderManager::render(void) noexcept
{
	this->_musicManager.refreshMusic(this->_render);
	if (this->_config->getMode() == Mode::RESET) {
		while (this->_game->checkDeleteBomb()) {};
		this->_game->destroy();
		this->_game.reset();
		this->_game = nullptr;
		this->_config->setMode(this->_config->getPrevMode());
	}
	if (this->_render == Render::GAME) {
		if (this->_game == nullptr)
			this->_game = std::unique_ptr<IndieStudio::Game>(new IndieStudio::Game(this->_graphical, this->_render, this->_config));
		this->_game->render();
		if (this->_game->isOver()) {
			while (this->_game->checkDeleteBomb()) {};
			this->_game->destroy();
			this->_game.reset();
			this->_game = nullptr;
		}
	} else if (this->_render == Render::MAIN_MENU || Render::PAUSE_MENU)
		this->_menu.render();
}