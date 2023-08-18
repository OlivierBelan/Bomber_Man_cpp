/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** RenderManager
*/

#pragma once

#include "IGraphical.hpp"
#include "Config.hpp"
#include "Game.hpp"
#include "MenuManager.hpp"
#include "MusicManager.hpp"
#include "Volume.hpp"

namespace IndieStudio {
	class RenderManager {
	public:
		RenderManager(IndieStudio::IGraphical &graphical);
		~RenderManager();

	public:
		void render() noexcept;
	private:
		IndieStudio::IGraphical &_graphical;
		IndieStudio::Render _render = Render::MAIN_MENU;
		IndieStudio::Config *_config = new IndieStudio::Config();
		IndieStudio::Volume *_volume = new IndieStudio::Volume();
		IndieStudio::MusicManager _musicManager;
		IndieStudio::MenuManager _menu;
		std::unique_ptr<IndieStudio::Game> _game = nullptr;


	};
}; // namespace IndieStudio