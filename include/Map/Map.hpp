/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>

static const float CUBE_SIDE = 40.f;
static const int CUBE_Y = 0;
static const int CUBE_Z = 0;
static const int CUBE_X = 0;
static const int SIZE_MAP = 15;
static const std::string FLOOR_TEXTURE_256 = "assets/map/256/bedrock.png";
static const std::string WALL_TEXTURE_256 = "assets/map/256/black_concrete.png";
static const std::string BRICK_TEXTURE_256 = "assets/map/256/bricks.png";
static const std::string FLOOR_TEXTURE_128 = "assets/map/128/bedrock.png";
static const std::string WALL_TEXTURE_128 = "assets/map/128/black_concrete.png";
static const std::string BRICK_TEXTURE_128 = "assets/map/128/bricks.png";
static const std::string FLOOR_TEXTURE_64 = "assets/map/64/bedrock.png";
static const std::string WALL_TEXTURE_64 = "assets/map/64/black_concrete.png";
static const std::string BRICK_TEXTURE_64 = "assets/map/64/bricks.png";

#include "IGraphical.hpp"
#include <fstream>
#include <irrlicht.h>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
namespace IndieStudio {
	class Map {
	public:
		Map(IndieStudio::IGraphical &graphical, std::string graphisme = "64", int x = 15, int y = 32, int densityBrick = 50, int densityWall = 100);
		Map(IndieStudio::IGraphical &graphical, std::string graphisme = "64", std::string map = NULL);
		~Map();
		IndieStudio::IEntity *createCubes(float, float, float, float ,const std::string) noexcept;
		void generate_map(int, int, std::vector<std::string> texture_Path) noexcept;
		void create_Start_Positon(void) noexcept;
		std::vector<IndieStudio::IEntity *> getBrickCube(void) noexcept;
		std::vector<IndieStudio::IEntity *> getWallCube(void) const noexcept;
		std::vector<IndieStudio::IEntity *> getWallInsideCube(void) noexcept;
		std::vector<IndieStudio::IEntity *> getWallOutsideCube(void) noexcept;
		std::vector<IndieStudio::IEntity *> getFloorCube(void) const noexcept;
		void delete_Cube(IndieStudio::IEntity *);
		void set_Texture_Cube(IndieStudio::IEntity *, std::string);
		std::vector<IndieStudio::Pos> get_Position_Start() const noexcept;
		std::vector<std::string> get_texture_64() const noexcept;
		std::vector<std::string> get_texture_128() const noexcept;
		std::vector<std::string> get_texture_256() const noexcept;
		std::vector<IndieStudio::IEntity *> getAllCube(void) noexcept;
		IndieStudio::IEntity *get_Cube_By_Position(IndieStudio::Pos pos);
		void generate_map_by_txt(std::vector<std::string> texture_Path) noexcept;
		void set_Density_Brick(float);
		void set_Density_Wall(float);
		std::vector<IndieStudio::Pos> getFreePos(void) noexcept;
		std::vector<std::shared_ptr<IndieStudio::Pos>> getFree_Absolute_Pos(void) noexcept;
		void clearFreePos() noexcept;
		void generateBySave(std::string map = NULL) noexcept;
	protected:

	private:
		enum Texture {
			FLOOR,
			WALL,
			BRICK
		};
		void adjustment_Position_Start() noexcept;
		void save_Texture() noexcept;
		void delete_Wall(IndieStudio::IEntity *);
		std::vector<std::string> set_Graphisme(const std::string path) const noexcept;
		int set_Txt_Map(const std::string);
		std::vector<std::string> get_Txt_Map(void) const noexcept;
		int check_format_map_txt() noexcept;
		void adjustment_Map_Txt();
		void init_pos_start() noexcept;
		std::string reverseStr(std::string &str);
		void generateSave();


		private:
		std::map<std::string, std::vector<IndieStudio::IEntity *>> _cube;
		IndieStudio::IGraphical &_graphical;
		std::vector<IndieStudio::Pos> _pos_start;
		std::vector<IndieStudio::IEntity *> _cube_Destruc_Vec;
		std::vector<IndieStudio::IEntity *> _wall_Vec;
		std::vector<IndieStudio::IEntity *> _wall_inside_Vec;
		std::vector<IndieStudio::IEntity *> _floor_Vec;
		std::vector<IndieStudio::Pos> _free_Pos;
		std::vector<std::shared_ptr<IndieStudio::Pos>> _free_Absolute_Pos;
		std::map<int, std::vector<IndieStudio::IEntity *>> _cube_Destruc_map;
		std::vector<std::string> _map_txt_vec;
		float _x_map = 0;
		float _y_map = 0;
		std::string _graphisme = "64";
	};
}; // namespace IndieStudio

#endif /* !MAP_HPP_ */