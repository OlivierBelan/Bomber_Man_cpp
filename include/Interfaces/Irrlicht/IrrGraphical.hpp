/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IrrGraphical
*/

#ifndef IRRGRAPHICAL_HPP_
#define IRRGRAPHICAL_HPP_

#include "IGraphical.hpp"
#include "IrrEntity.hpp"
#include "IrrEvent.hpp"
#include <irrlicht.h>

namespace IndieStudio {
	class IrrGraphical : public IGraphical, public irr::IEventReceiver {
	public:
		IrrGraphical();
		~IrrGraphical();
		virtual IndieStudio::IEntity *createMesh(std::string meshPath) const noexcept;
		virtual IndieStudio::IEntity *createAnimatedMesh(std::string meshPath, std::string texturePath) const noexcept;
		virtual IndieStudio::IEntity *createCube(float size, std::string texturePath, IndieStudio::Pos pos, IndieStudio::Pos scale) const noexcept;
		virtual IndieStudio::IEntity *createParticle(IndieStudio::Pos boxPos, IndieStudio::Pos dirPos, int min, int max, int disp, IndieStudio::Pos colorMin, IndieStudio::Pos colorMax, int lifeTime);
		virtual void createCollision(IndieStudio::IEntity *cube, IndieStudio::IEntity *entity) const noexcept;
		virtual IndieStudio::Pos getCameraPos(void) const noexcept;
		virtual void setCursorVisible(bool b) noexcept;
		virtual bool run(void) const noexcept;
		virtual void startRender(void) const noexcept;
		virtual void endRender(void) const noexcept;
		virtual void drawScene(void) const noexcept;
		virtual void drop(void) const noexcept;
		virtual void drawText(std::string) noexcept;
		virtual void setCameraTarget(IndieStudio::Pos pos) const noexcept;
		virtual void setCameraPosition(IndieStudio::Pos) noexcept;
		virtual void setCameraRotation(IndieStudio::Pos pos) noexcept;
		virtual bool OnEvent(const irr::SEvent &event);
		virtual IndieStudio::IEvent getEvent(void) const noexcept;
		virtual void deleteEntity(IndieStudio::IEntity *) const noexcept;
		virtual IndieStudio::IEntity *createImage(std::string texturePath, std::pair<int, int> pos) const noexcept;
		virtual void drawImage(IndieStudio::IEntity *) const noexcept;
		virtual void setSkin(IndieStudio::IEntity *, std::string) noexcept;
		virtual void set2DPos(IndieStudio::IEntity *, std::pair<int, int>) noexcept;
		virtual void setCustomRectangle(IndieStudio::IEntity *, int, int, int, int) noexcept;
		virtual void drawText(std::string, int, int, int, int) noexcept;
		void holdParticle(irr::scene::IParticleSystemSceneNode *particle) const;



	private:
		IndieStudio::IrrEvent _event;
		irr::IrrlichtDevice *_device;
		irr::scene::ISceneManager *_sceneManager;
		irr::video::IVideoDriver *_driver;
		irr::scene::ICameraSceneNode *_camera;
		irr::gui::IGUIEnvironment *_gui;
		irr::gui::IGUIFont *_mikado;
	};
}; // namespace IndieStudio

#endif