/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IaMouvement
*/

#include "IaMouvement.hpp"

IndieStudio::IaMouvement::IaMouvement()
{
}

void IndieStudio::IaMouvement::Ia(std::shared_ptr<IndieStudio::Character> &characVec, std::vector<std::shared_ptr<IndieStudio::Bomb>> &bombVec,
	std::vector<std::shared_ptr<IndieStudio::Pos>> freePos, std::vector<IndieStudio::IEntity *> brick, std::vector<std::shared_ptr<IndieStudio::Character>> characAll)
{
	this->_characVec = characVec;
	this->_bombVec = bombVec;
	this->_freePos = freePos;
	this->_brick = brick;
	this->_characAll = characAll;
	this->_characVec->setBombSize(1);
	if (isMoving() == false) {
		resetMoving();
		setCenter();
		checkFreeMove();
		checkBomb();
		poseBomb();
		chooseDirection();
		this->_characVec->setMovingUp(_freeUp);
		this->_characVec->setMovingDown(_freeDown);
		this->_characVec->setMovingRight(_freeRight);
		this->_characVec->setMovingLeft(_freeLeft);
		std::this_thread::sleep_for(std::chrono::microseconds(300));
	}
}

bool IndieStudio::IaMouvement::checkPlayer()
{
	auto inRange = [this](std::shared_ptr<IndieStudio::Character> &charac){
		if (charac->getPosition()._x >= this->_currentPos._x - 60 && charac->getPosition()._x <= this->_currentPos._x + 60
		&& charac->getPosition()._z >= this->_currentPos._z - 20 && charac->getPosition()._z <= this->_currentPos._z + 20)
			return (true);
		if (charac->getPosition()._z >= this->_currentPos._z - 60 && charac->getPosition()._z >= this->_currentPos._z + 60
		&& charac->getPosition()._x >= this->_currentPos._x - 20 && charac->getPosition()._x <= this->_currentPos._x + 20)
			return (true);
		return(false);
	};
	for (unsigned int i = 0; i != this->_characAll.size(); i++) {
		if (this->_characVec->getName() != this->_characAll[i]->getName() && inRange(this->_characAll[i]) == true) {
			return(true);
		}
	}
	return (false);
}

void IndieStudio::IaMouvement::checkBomb()
{
//	std::cout << this->_characVec->getName() << " " << this->_characVec->getPosition()._x << " " << this->_characVec->getPosition()._y << " " << this->_characVec->getPosition()._z << "\n";
	std::vector<int> tempChoiceDestination = checkBombHit();
	if (tempChoiceDestination.size() > 0)
			this->_choiceDestination = tempChoiceDestination;
	else if (this->_canStay == true)
		this->_choiceDestination = tempChoiceDestination;
	else if (this->_characVec->getDeath() == false && this->_choiceDestination.size() != 1 && inBomb() != true) {
		// if (this->_choiceDestination.size() == check && this->_characVec->getBombSize() > 1) {
		// 	// std::cout << this->_characVec->getName() << ": ";
		// 	// std::cout << "CHECK = " << check << " choice = " << this->_choiceDestination.size() << "\n";
		// 	return;
		// }
		this->_choiceDestination = tempChoiceDestination;
	}

}

std::vector<int> IndieStudio::IaMouvement::checkBombHit()
{
	setBombPos();
	std::vector<int> tempChoiceDestination = this->_choiceDestination;
	this->_canStay = true;
	unsigned int check = 0;
	auto eraseDestination = [&tempChoiceDestination, &check](int nb) {
		for (unsigned int i = 0; i != tempChoiceDestination.size(); i++) {
			if (tempChoiceDestination[i] == nb) {
				check++;
				tempChoiceDestination.erase(tempChoiceDestination.begin() + i);
				break;
			}
		}
	};
	for (unsigned int i = 0; i != this->_bombPos.size(); i++) {
		if (this->_bombPos[i]._x == _destinationUp._x && this->_bombPos[i]._z == _destinationUp._z) {
			eraseDestination(Up);
		}
		if (this->_bombPos[i]._x == _destinationDown._x && this->_bombPos[i]._z == _destinationDown._z) {
			eraseDestination(Down);
		}
		if (this->_bombPos[i]._x == _destinationRight._x && this->_bombPos[i]._z == _destinationRight._z) {
			eraseDestination(Right);
		}
		if (this->_bombPos[i]._x == _destinationLeft._x && this->_bombPos[i]._z == _destinationLeft._z) {
			eraseDestination(Left);
		}
		if (this->_bombPos[i]._x == this->_currentPos._x && this->_bombPos[i]._z == this->_currentPos._z) {
			this->_canStay = false;
		}
	}
	return (tempChoiceDestination);
}

bool IndieStudio::IaMouvement::inBomb()
{
	for (unsigned int i = 0; i != this->_bombVec.size(); i++) {
		if (this->_bombVec[i]->getPosition()._x == this->_currentPos._x && this->_bombVec[i]->getPosition()._z == this->_currentPos._z)
			return (true);
	}
	return (false);
}

void IndieStudio::IaMouvement::poseBomb()
{
	if (this->checkBrick() == true || checkPlayer() == true) {
		if (this->_currentPos != this->_spawnPos /* && rand() % 3 == 0 */&& this->_choiceDestination.size() > 0 &&
		 this->_characVec->get_Bomb_Current() == 0 && this->_canStay == true && this->_canBomb == true) {
			this->_characVec->setDoingAction(true);
		}
	}
}

void IndieStudio::IaMouvement::setBombPos()
{
	this->_bombPos.clear();
	for (unsigned int i = 0; i != this->_bombVec.size(); i++) {
		for (int j = 0; j != this->_bombVec[i]->getBombSize() + 1; j++) {
			if (j < 1) {
				this->_bombPos.push_back(IndieStudio::Pos{this->_bombVec[i]->getLastPosition()._x, this->_bombVec[i]->getLastPosition()._y, this->_bombVec[i]->getLastPosition()._z});
			} else {
				this->_bombPos.push_back(IndieStudio::Pos{this->_bombVec[i]->getLastPosition()._x + (j * 40), this->_bombVec[i]->getLastPosition()._y, this->_bombVec[i]->getLastPosition()._z});
				this->_bombPos.push_back(IndieStudio::Pos{this->_bombVec[i]->getLastPosition()._x - (j * 40), this->_bombVec[i]->getLastPosition()._y, this->_bombVec[i]->getLastPosition()._z});
				this->_bombPos.push_back(IndieStudio::Pos{this->_bombVec[i]->getLastPosition()._x, this->_bombVec[i]->getLastPosition()._y, this->_bombVec[i]->getLastPosition()._z + (j * 40)});
				this->_bombPos.push_back(IndieStudio::Pos{this->_bombVec[i]->getLastPosition()._x, this->_bombVec[i]->getLastPosition()._y, this->_bombVec[i]->getLastPosition()._z - (j * 40)});
			}
		}
	}
}

bool IndieStudio::IaMouvement::checkBrick()
{
	for (unsigned int i = 0; i != this->_brick.size(); i++) {
		if (this->_currentPos._x + 40 == this->_brick[i]->getPosition()._x && this->_currentPos._z == this->_brick[i]->getPosition()._z)
			return (true);
		if (this->_currentPos._x - 40 == this->_brick[i]->getPosition()._x && this->_currentPos._z == this->_brick[i]->getPosition()._z)
			return (true);
		if (this->_currentPos._x == this->_brick[i]->getPosition()._x && this->_currentPos._z + 40 == this->_brick[i]->getPosition()._z)
			return (true);
		if (this->_currentPos._x == this->_brick[i]->getPosition()._x && this->_currentPos._z - 40== this->_brick[i]->getPosition()._z)
			return (true);
	}
	return (false);
}

void IndieStudio::IaMouvement::resetMoving()
{
	this->_characVec->setMovingUp(false);
	this->_characVec->setMovingDown(false);
	this->_characVec->setMovingLeft(false);
	this->_characVec->setMovingRight(false);
	this->_freeUp = false;
	this->_freeDown = false;
	this->_freeLeft = false;
	this->_freeRight = false;
	this->_choiceDestination.clear();
}

void IndieStudio::IaMouvement::resetDirection()
{
	this->_characVec->setMovingUp(false);
	this->_characVec->setMovingDown(false);
	this->_characVec->setMovingLeft(false);
	this->_characVec->setMovingRight(false);
	this->_freeUp = false;
	this->_freeDown = false;
	this->_freeLeft = false;
	this->_freeRight = false;
}

void IndieStudio::IaMouvement::chooseDirection()
{
	if (this->_choiceDestination.size() > 0) {
		int choose = rand() % (this->_choiceDestination.size());
		resetDirection();
		choose = this->_choiceDestination[choose];
		if (choose == Up) {
			this->_characVec->setMovingUp(true);
			_destination = _destinationUp;
			_freeUp = true;
		} else if (choose == Down) {
			this->_characVec->setMovingDown(true);
			_destination = _destinationDown;
			_freeDown = true;
		} else if (choose == Right) {
			this->_characVec->setMovingRight(true);
			_destination = _destinationRight;
			_freeRight = true;
		} else if (choose == Left) {
			this->_characVec->setMovingLeft(true);
			_destination = _destinationLeft;
			_freeLeft = true;
		}
	}
}

///////// GET ///////////
bool IndieStudio::IaMouvement::isMoving()
{
	if (_freeUp == false && _freeDown == false && _freeLeft == false && _freeRight == false) {
		return (false);
	}
	if (this->_characVec->getPosition()._x >= _destination._x - ECART && this->_characVec->getPosition()._x <= _destination._x + ECART && this->_characVec->getPosition()._z >= _destination._z - ECART && this->_characVec->getPosition()._z <= _destination._z + ECART) {
		setCenter();
		resetMoving();
		return (false);
	}
	return (true);
}

///////// SET ////////////
void IndieStudio::IaMouvement::checkFreeMove()
{
	freeUp();
	freeDown();
	freeLeft();
	freeRight();
}

void IndieStudio::IaMouvement::freeUp()
{
	float nb = 0;
	float pos = this->_characVec->getPosition()._x + 1;
	for (nb = 0; (int)(pos + nb) % 40 != 0; nb++);

	for (unsigned int i = 0; i != _freePos.size(); i++) {
		if (this->_characVec->getPosition()._z >= _freePos[i]->_z - ECART && this->_characVec->getPosition()._z <= _freePos[i]->_z + ECART && (this->_characVec->getPosition()._x + nb) >= _freePos[i]->_x - ECART && (this->_characVec->getPosition()._x + nb) <= _freePos[i]->_x + ECART) {
			this->_choiceDestination.push_back(Up);
			this->_destinationUp = *_freePos[i];
		}
	}
}
void IndieStudio::IaMouvement::freeDown()
{
	float nb = 0;
	float pos = this->_characVec->getPosition()._x - 1;
	for (nb = 0; (int)(pos + nb) % 40 != 0; nb--);

	for (unsigned int i = 0; i != _freePos.size(); i++) {
		if (this->_characVec->getPosition()._z >= _freePos[i]->_z - ECART && this->_characVec->getPosition()._z <= _freePos[i]->_z + ECART && (this->_characVec->getPosition()._x + nb) >= _freePos[i]->_x - ECART && (this->_characVec->getPosition()._x + nb) <= _freePos[i]->_x + ECART) {
			this->_choiceDestination.push_back(Down);
			this->_destinationDown = *_freePos[i];
		}
	}
}
void IndieStudio::IaMouvement::freeLeft()
{
	float nb = 0;
	float pos = this->_characVec->getPosition()._z + 1;
	for (nb = 0; (int)(pos + nb) % 40 != 0; nb++);

	for (unsigned int i = 0; i != _freePos.size(); i++) {
		if (this->_characVec->getPosition()._x >= (_freePos[i]->_x - ECART) && this->_characVec->getPosition()._x <= (_freePos[i]->_x + ECART) && (this->_characVec->getPosition()._z + nb) >= (_freePos[i]->_z - ECART) && (this->_characVec->getPosition()._z + nb) <= _freePos[i]->_z + ECART) {
			this->_choiceDestination.push_back(Left);
			this->_destinationLeft = *_freePos[i];
		}
	}
}
void IndieStudio::IaMouvement::freeRight()
{
	float nb = 0;
	float pos = this->_characVec->getPosition()._z - 1;
	for (nb = 0; (int)(pos + nb) % 40 != 0; nb--);

	for (unsigned int i = 0; i != _freePos.size(); i++) {
		if (this->_characVec->getPosition()._x >= _freePos[i]->_x - ECART && this->_characVec->getPosition()._x <= _freePos[i]->_x + ECART && (this->_characVec->getPosition()._z + nb) >= _freePos[i]->_z - ECART && (this->_characVec->getPosition()._z + nb) <= _freePos[i]->_z + ECART) {
			this->_choiceDestination.push_back(Right);
			this->_destinationRight = *_freePos[i];
		}
	}
}

void IndieStudio::IaMouvement::setCenter()
{
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
	float pos_RIGHT_LEFT = this->_characVec->getPosition()._z;
	float pos_UP_DOWN = this->_characVec->getPosition()._x;
	for (up = 0; (int)(pos_UP_DOWN + up) % 40 != 0; up++)
		;
	for (down = 0; (int)(pos_UP_DOWN + down) % 40 != 0; down--)
		;
	for (right = 0; (int)(pos_RIGHT_LEFT + right) % 40 != 0; right--)
		;
	for (left = 0; (int)(pos_RIGHT_LEFT + left) % 40 != 0; left++)
		;
	int x = (up < -1 * (down) ? up : down) + pos_UP_DOWN;
	int z = (left < -1 * (right) ? left : right) + pos_RIGHT_LEFT;
	this->_characVec->setPosition(IndieStudio::Pos{(float)x, this->_characVec->getPosition()._y, (float)z});
	this->_currentPos = IndieStudio::Pos{(float)x, this->_characVec->getPosition()._y, (float)z};
	if (this->_spawnPos == IndieStudio::Pos{0,0,0})
		this->_spawnPos = IndieStudio::Pos{(float)x, this->_characVec->getPosition()._y, (float)z};
}

IndieStudio::IaMouvement::~IaMouvement()
{
}
