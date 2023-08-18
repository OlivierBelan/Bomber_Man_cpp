/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include "IGraphical.hpp"
#include <fstream>
#include <irrlicht.h>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <vector>

static const int NB_BONUS = 10;
static const std::string RED_FIRE_BONUS = "assets/powerUp/fireUp.png";//"assets/map/64/red_punch.png";
static const std::string RED_SPEED_BONUS = "assets/powerUp/speedUp.png";//"assets/map/64/red_speed.png";
static const std::string RED_BOMB_BONUS = "assets/powerUp/bombUp.png";//"assets/map/64/red_bomb.png";
static const std::string BLUE_FIRE_BONUS = "assets/powerUp/fireDown.png";//"assets/map/64/blue_punch.png";
static const std::string BLUE_SPEED_BONUS = "assets/powerUp/speedDown.png";//"assets/map/64/blue_speed.png";
static const std::string BLUE_BOMB_BONUS = "assets/powerUp/bombDown.png";//"assets/map/64/blue_bomb.png";

static const float CUBE_BONUS_Y = 60.f;


namespace IndieStudio {
    class Bonus {
        public:
            Bonus(IndieStudio::IGraphical &graphical, int density = 33);
            ~Bonus();
            IndieStudio::IEntity *createCubes(float, float, float, float ,const std::string) noexcept;
            void create_Bonus(void) noexcept;
            std::vector<std::string> get_texture_Bonus() const noexcept;
            std::vector<IndieStudio::IEntity *> getRedBonusFire() noexcept;
            std::vector<IndieStudio::IEntity *> getRedBonusBomb() noexcept;
            std::vector<IndieStudio::IEntity *> getRedBonusSpeed() noexcept;
            std::vector<IndieStudio::IEntity *> getBlueBonusFire() noexcept;
            std::vector<IndieStudio::IEntity *> getBlueBonusBomb() noexcept;
            std::vector<IndieStudio::IEntity *> getBlueBonusSpeed() noexcept;
            int getBonus(IndieStudio::Pos, std::vector<IndieStudio::IEntity *>) noexcept;
            int getMalus(IndieStudio::Pos, std::vector<IndieStudio::IEntity *>) noexcept;
            std::vector<IndieStudio::Pos> getFreePosition() noexcept;
            void addFreePosition(std::vector<IndieStudio::Pos>) noexcept;
            void animeBonus() noexcept;
            void delete_Cube(IndieStudio::IEntity *);
            void destroy_Bonus();
        protected:
        private:
            enum enumBonus {
            RED_BOMB,
            RED_FIRE,
            RED_SPEED,
            BLUE_BOMB,
            BLUE_FIRE,
            BLUE_SPEED
            };
            IndieStudio::IGraphical &_graphical;
            std::vector<IndieStudio::IEntity *> _Bonus_Red_Speed_Vec;
            std::vector<IndieStudio::IEntity *> _Bonus_Red_Fire_Vec;
            std::vector<IndieStudio::IEntity *> _Bonus_Red_Bomb_Vec;
            std::vector<IndieStudio::IEntity *> _Bonus_Blue_Speed_Vec;
            std::vector<IndieStudio::IEntity *> _Bonus_Blue_Fire_Vec;
            std::vector<IndieStudio::IEntity *> _Bonus_Blue_Bomb_Vec;
            std::vector<IndieStudio::Pos> _free_Pos;
            float high = 60.f;
            bool direction = false;
            float _density;
            float _min_density = 0;
    };
}

#endif /* !BONUS_HPP_ */
