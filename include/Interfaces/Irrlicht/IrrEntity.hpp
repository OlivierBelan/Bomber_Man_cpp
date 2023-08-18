/*
** EPITECH PROJECT, 2019
** test
** File description:
** IrrEntity
*/

#ifndef IRRENTITY_HPP_
#define IRRENTITY_HPP_

#include "IEntity.hpp"
#include <irrlicht.h>
#include <iostream>

namespace IndieStudio {
	class IrrEntity : public IEntity {
		public:
			IrrEntity(irr::scene::IAnimatedMeshSceneNode *animatedNode) : _animatedNode(animatedNode) {};
			IrrEntity(irr::scene::IMeshSceneNode *node) : _node(node) {};
			IrrEntity(irr::scene::IParticleSystemSceneNode *particle) : _particle(particle) {};
			IrrEntity(irr::video::ITexture *image, std::pair<int, int> pos, irr::core::rect<irr::s32> rectangle) : _image(image), _pos(pos), _rectangle(rectangle) {};
			~IrrEntity();
			virtual IndieStudio::Pos getPosition(void) const noexcept;
			virtual void setPosition(IndieStudio::Pos) noexcept;
			virtual void setRotation(IndieStudio::Pos) noexcept;
			virtual void setAnimation(int) noexcept;
			virtual void setScale(IndieStudio::Pos) noexcept;
			irr::scene::IAnimatedMeshSceneNode *getAnimatedMesh() const noexcept;
			irr::scene::IMeshSceneNode *getMesh() const noexcept;
			irr::scene::IParticleSystemSceneNode *getParticle() const noexcept;
			irr::video::ITexture *getImage() const noexcept;
			void setImage(irr::video::ITexture *) noexcept;
			irr::core::position2d<irr::s32> get2DPos() const noexcept;
			irr::core::rect<irr::s32> getRectangle() const noexcept;
			void setRectangle(irr::core::rect<irr::s32>) noexcept;
			void set2Dpos(std::pair<int, int>) noexcept;



		private:
			irr::scene::IAnimatedMeshSceneNode *_animatedNode = nullptr;
			irr::scene::IMeshSceneNode *_node = nullptr;
			irr::scene::IParticleSystemSceneNode *_particle = nullptr;
			irr::video::ITexture *_image = nullptr;
			std::pair<int, int> _pos = {0, 0};
			irr::core::rect<irr::s32> _rectangle = {0, 0, 0, 0};
	};
};

#endif