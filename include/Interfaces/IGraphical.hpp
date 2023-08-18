/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

namespace IndieStudio {
	enum Render {
		GAME,
		MAIN_MENU,
		PAUSE_MENU,
	};
};

#include "IEntity.hpp"
#include "IEvent.hpp"
#include <iostream>
#include <memory>

namespace IndieStudio {
	class IGraphical {
	public:
		virtual ~IGraphical() = default;
		virtual IndieStudio::IEntity *createMesh(std::string meshPath) const noexcept = 0;
		virtual IndieStudio::IEntity *createAnimatedMesh(std::string meshPath, std::string texturePath) const noexcept = 0;
		virtual IndieStudio::IEntity *createCube(float size, std::string texturePath, IndieStudio::Pos pos = IndieStudio::Pos(0, 0, 0), IndieStudio::Pos scale = IndieStudio::Pos(1, 1, 1)) const noexcept = 0;
		virtual IndieStudio::IEntity *createParticle(IndieStudio::Pos boxPos, IndieStudio::Pos dirPos, int min, int max, int disp, IndieStudio::Pos colorMin, IndieStudio::Pos colorMax, int lifeTime) = 0;
		virtual void createCollision(IndieStudio::IEntity *cube, IndieStudio::IEntity *entity) const noexcept = 0;
		virtual IndieStudio::Pos getCameraPos(void) const noexcept = 0;
		virtual void setCursorVisible(bool b) noexcept = 0;
		virtual bool run(void) const noexcept = 0;
		virtual void startRender(void) const noexcept = 0;
		virtual void endRender(void) const noexcept = 0;
		virtual void drawScene(void) const noexcept = 0;
		virtual void drop(void) const noexcept = 0;
		virtual void drawText(std::string) noexcept = 0;
		virtual void setCameraTarget(IndieStudio::Pos pos) const noexcept = 0;
		virtual void setCameraPosition(IndieStudio::Pos pos) = 0;
		virtual void setCameraRotation(IndieStudio::Pos pos) = 0;
		virtual IndieStudio::IEvent getEvent(void) const noexcept = 0;
		virtual void deleteEntity(IndieStudio::IEntity *) const noexcept = 0;
		virtual IndieStudio::IEntity *createImage(std::string texturePath, std::pair<int, int> pos) const noexcept = 0;
		virtual void drawImage(IndieStudio::IEntity *) const noexcept = 0;
		virtual void setSkin(IndieStudio::IEntity *, std::string) noexcept = 0;
		virtual void set2DPos(IndieStudio::IEntity *, std::pair<int, int>) noexcept = 0;
		virtual void setCustomRectangle(IndieStudio::IEntity *, int, int, int, int) noexcept = 0;
		virtual void drawText(std::string, int, int, int, int) noexcept = 0;
	};
}; // namespace IndieStudio

#endif