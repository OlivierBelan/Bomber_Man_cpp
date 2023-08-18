/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** IaMouvement
*/

#pragma once

#include <stdlib.h>
#include <vector>
#include "Character.hpp"
#include "Bomb.hpp"
#include <thread>
static const float ECART = 2;

namespace IndieStudio {
    class IaMouvement {
        public:
            IaMouvement();
            ~IaMouvement();
            void Ia(std::shared_ptr<IndieStudio::Character> &characVec, std::vector<std::shared_ptr<IndieStudio::Bomb>> &bombVec, std::vector<std::shared_ptr<IndieStudio::Pos>> freePos, std::vector<IndieStudio::IEntity *> brick, std::vector<std::shared_ptr<IndieStudio::Character>> characAll);
        protected:
        private:
        enum direction {
            Up,
            Down,
            Right,
            Left
        };
        void checkFreeMove();
        void freeUp();
        void freeDown();
        void freeRight();
        void freeLeft();
        void setCenter();
        bool isMoving();
        void resetMoving();
        void resetDirection();
        void chooseDirection();
        void Move();
        void checkBomb();
        void setBombPos();
        void poseBomb();
        bool checkBrick();
        bool inBomb();
        bool checkPlayer();
        std::vector<int> checkBombHit();
        std::vector<int> _choiceDestination;
        IndieStudio::Pos _destination = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationUp = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationDown = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationRight = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _destinationLeft = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _currentPos = IndieStudio::Pos{0,0,0};
        IndieStudio::Pos _spawnPos = IndieStudio::Pos{0,0,0};
        bool _freeUp = false;
        bool _freeDown = false;
        bool _freeRight = false;
        bool _freeLeft = false;
        bool _canStay = true;
        bool _canBomb = true;
        std::vector<std::shared_ptr<IndieStudio::Character>> _characAll;
        std::shared_ptr<IndieStudio::Character> _characVec;
        std::vector<std::shared_ptr<IndieStudio::Bomb>> _bombVec;
        std::vector<std::shared_ptr<IndieStudio::Pos>> _freePos;
        std::vector<IndieStudio::IEntity *> _brick;
        std::vector<IndieStudio::Pos> _bombPos;

    };
}