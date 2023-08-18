/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include "IrrGraphical.hpp"
#include "RenderManager.hpp"

int main()
{
	IndieStudio::IrrGraphical graphical;
	IndieStudio::Render render = IndieStudio::Render::MAIN_MENU;
	IndieStudio::RenderManager renderManager(graphical);

	while (graphical.run()) {
		graphical.startRender();
		renderManager.render();
		graphical.endRender();
	}
	graphical.drop();
	return 0;
}