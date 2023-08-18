/*
** EPITECH PROJECT, 2019
** test
** File description:
** IrrEntity
*/

#include "IrrEntity.hpp"

IndieStudio::IrrEntity::~IrrEntity()
{
}

IndieStudio::Pos IndieStudio::IrrEntity::getPosition(void) const noexcept
{
	irr::core::vector3df entityPos;

	if (this->_node != nullptr)
		entityPos = this->_node->getPosition();
	if (this->_animatedNode != nullptr)
		entityPos = this->_animatedNode->getPosition();
	IndieStudio::Pos pos(entityPos.X, entityPos.Y, entityPos.Z);
	return (pos);
}

void IndieStudio::IrrEntity::setPosition(IndieStudio::Pos position) noexcept
{
	irr::core::vector3df entityPos(position._x, position._y, position._z);
	if (this->_node != nullptr)
		this->_node->setPosition(entityPos);
	if (this->_animatedNode != nullptr)
		this->_animatedNode->setPosition(entityPos);
}

void IndieStudio::IrrEntity::setRotation(IndieStudio::Pos position) noexcept
{
	if (this->_animatedNode != nullptr)
		this->_animatedNode->setRotation(irr::core::vector3df(position._x, position._y, position._z));
	if (this->_node != nullptr)
		this->_node->setRotation(irr::core::vector3df(position._x, position._y, position._z));
}

void IndieStudio::IrrEntity::setAnimation(int animation) noexcept
{
	this->_animatedNode->setMD2Animation(static_cast<irr::scene::EMD2_ANIMATION_TYPE>(animation));
}

void IndieStudio::IrrEntity::setScale(IndieStudio::Pos scale) noexcept
{
	irr::core::vector3df newScale(scale._x, scale._y, scale._z);
	if (this->_node != nullptr)
		this->_node->setScale(newScale);
	if (this->_animatedNode != nullptr)
		this->_animatedNode->setScale(newScale);
}

irr::scene::IAnimatedMeshSceneNode *IndieStudio::IrrEntity::getAnimatedMesh() const noexcept
{
	return (this->_animatedNode);
}

irr::scene::IMeshSceneNode *IndieStudio::IrrEntity::getMesh() const noexcept
{
	return (this->_node);
}

irr::scene::IParticleSystemSceneNode *IndieStudio::IrrEntity::getParticle() const noexcept
{
	return (this->_particle);
}

irr::video::ITexture *IndieStudio::IrrEntity::getImage() const noexcept
{
	return (this->_image);
}

void IndieStudio::IrrEntity::setImage(irr::video::ITexture *image) noexcept
{
	this->_image = image;
}

void IndieStudio::IrrEntity::setRectangle(irr::core::rect<irr::s32> rectangle) noexcept
{
	this->_rectangle = rectangle;
}

irr::core::position2d<irr::s32> IndieStudio::IrrEntity::get2DPos() const noexcept
{
	return (irr::core::position2d<irr::s32>(this->_pos.first, this->_pos.second));
}

irr::core::rect<irr::s32> IndieStudio::IrrEntity::getRectangle() const noexcept
{
	return (this->_rectangle);
}

void IndieStudio::IrrEntity::set2Dpos(std::pair<int, int> pos) noexcept
{
	this->_pos = pos;
}