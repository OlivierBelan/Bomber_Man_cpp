/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include "Character.hpp"
#include <cctype>
#include <clocale>
static std::map<std::string, IndieStudio::character_assets_t> playerAssets = {
	{"Yoshi", {"assets/characters/yoshi/tris.md2", "assets/characters/yoshi/yoshi.pcx", "assets/characters/yoshi/death.wav"}},
	{"Sponge Bob", {"assets/characters/spongebob/tris.md2", "assets/characters/spongebob/bob.pcx", "assets/characters/spongebob/death.wav"}},
	{"Eric Cartman", {"assets/characters/eric_c/tris.md2", "assets/characters/eric_c/eric.pcx", "assets/characters/eric_c/death.wav"}},
	{"Fox", {"assets/characters/starfox/tris.md2", "assets/characters/starfox/starfox.pcx", "assets/characters/starfox/death.wav"}}};

IndieStudio::Character::Character(IndieStudio::IGraphical &graphical, std::string name, bool bot, IndieStudio::Pos position, IndieStudio::playerKeybinds keys) :
	_graphical(graphical),
	_bot(bot),
	_up(std::toupper(keys.up)),
	_left(std::toupper(keys.left)),
	_down(std::toupper(keys.down)),
	_right(std::toupper(keys.right)),
	_action(std::toupper(keys.bomb)),
	_spawnPos(position),
	_name(name)
{
	if (bot) {
		this->_up = IndieStudio::Key::null;
		this->_left = IndieStudio::Key::null;
		this->_down = IndieStudio::Key::null;
		this->_right = IndieStudio::Key::null;
		this->_action = IndieStudio::Key::null;
	}
	this->_model = this->_graphical.createAnimatedMesh(playerAssets[name].mesh, playerAssets[name].texture);
	this->_model->setPosition(position);
	this->_deathSound = std::shared_ptr<IndieStudio::Audio>(new IndieStudio::Audio(playerAssets[name].deathSound));
}

IndieStudio::Character::~Character()
{
}

std::string IndieStudio::Character::getName() const noexcept
{
	return (this->_name);
}

IndieStudio::Pos IndieStudio::Character::getPosition() noexcept
{
	return (_model->getPosition());
}

void IndieStudio::Character::setPosition(IndieStudio::Pos position) noexcept
{
	_model->setPosition(position);
}

IndieStudio::IEntity *IndieStudio::Character::getEntity() noexcept
{
	return (this->_model);
}

char IndieStudio::Character::getUpKey() const noexcept
{
	return (this->_up);
}

char IndieStudio::Character::getLeftKey() const noexcept
{
	return (this->_left);
}

char IndieStudio::Character::getDownKey() const noexcept
{
	return (this->_down);
}

char IndieStudio::Character::getRightKey() const noexcept
{
	return (this->_right);
}

char IndieStudio::Character::getActionKey() const noexcept
{
	return (this->_action);
}

void IndieStudio::Character::setMovingUp(bool b) noexcept
{
	this->_movingUp = b;
}

void IndieStudio::Character::setMovingLeft(bool b) noexcept
{
	this->_movingLeft = b;
}

void IndieStudio::Character::setMovingDown(bool b) noexcept
{
	this->_movingDown = b;
}

void IndieStudio::Character::setMovingRight(bool b) noexcept
{
	this->_movingRight = b;
}

void IndieStudio::Character::setDoingAction(bool b) noexcept
{
	this->_doingAction = b;
}

bool IndieStudio::Character::getMovingUp(void) const noexcept
{
	return (this->_movingUp);
}

bool IndieStudio::Character::getMovingLeft(void) const noexcept
{
	return (this->_movingLeft);
}

bool IndieStudio::Character::getMovingDown(void) const noexcept
{
	return (this->_movingDown);
}

bool IndieStudio::Character::getMovingRight(void) const noexcept
{
	return (this->_movingRight);
}

bool IndieStudio::Character::getDoingAction(void) const noexcept
{
	return (this->_doingAction);
}

bool IndieStudio::Character::getIsMoving(void) const noexcept
{
	return (this->_isMoving);
}

void IndieStudio::Character::setIsMoving(bool b) noexcept
{
	this->_isMoving = b;
}

float IndieStudio::Character::getSpeed(void) const noexcept
{
	return (this->_speed);
}

void IndieStudio::Character::setSpeed(float speed) noexcept
{
	this->_speed = speed;
}

void IndieStudio::Character::playDeathSound(bool b) noexcept
{
	this->_deathSound->playSound(b);
}

void IndieStudio::Character::set_Bomb_Current(int i) noexcept
{
	this->_bomb_current = i;
}

int IndieStudio::Character::get_Bomb_Current() const noexcept
{
	return (this->_bomb_current);
}

void IndieStudio::Character::setBombMax(int i) noexcept
{
	this->_bomb_Max = i;
}

int IndieStudio::Character::getBombMax() const noexcept
{
	return (this->_bomb_Max);
}

int IndieStudio::Character::getBombSize() const noexcept
{
	return (this->_bombSize);
}

void IndieStudio::Character::setBombSize(int i) noexcept
{
	this->_bombSize = i;
}

IndieStudio::Pos IndieStudio::Character::getSpawnPos() const noexcept
{
	return (this->_spawnPos);
}

bool IndieStudio::Character::getBot() noexcept
{
	return (this->_bot);
}
void IndieStudio::Character::setBot(bool isBot) noexcept
{
	this->_bot = isBot;
}
void IndieStudio::Character::setBonus(float speed, int bombSize, int bombMax) noexcept
{
	if (speed != 0 || bombSize != 0 || bombMax != 0) {
		this->setSpeed(getSpeed() + speed / 4);
		this->setBombSize(getBombSize() + bombSize);
		this->setBombMax(getBombMax() + bombMax);
	}
	if (getSpeed() < SPEED)
		setSpeed(SPEED);
	if (getBombSize() < BOMBSIZE)
		setBombSize(BOMBSIZE);
	if (getBombMax() < BOMBMAX)
		setBombMax(BOMBMAX);
}

#include <thread>

#define DEATH 19

bool IndieStudio::Character::getDeath(void) const noexcept
{
	return (this->_death);
}

void IndieStudio::Character::death(void) noexcept
{
	this->_death = true;
	this->playDeathSound();
	std::thread([this] {
		this->getEntity()->setAnimation(DEATH);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		this->setPosition(IndieStudio::Pos(1000, 1000, 1000));
	})
		.detach();
}

void IndieStudio::Character::setDeath(bool isDead) noexcept
{
	this->_death = isDead;
}