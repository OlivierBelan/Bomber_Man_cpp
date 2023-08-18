/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Map
*/

#include "Map.hpp"
#include <thread>
#include <functional>
IndieStudio::Map::Map(IndieStudio::IGraphical &graphical, std::string graphisme, int x, int y, int densityBrick, int densityWall) :
	_graphical(graphical)
{
	init_pos_start();
	if (densityBrick == 100)
		densityBrick -= 10;
	this->generate_map(x < 6 ? 6 : x, y < 6 ? 6 : y, set_Graphisme(graphisme));
	set_Density_Wall(100 - densityWall);
	set_Density_Brick(100 - densityBrick);
}

IndieStudio::Map::Map(IndieStudio::IGraphical &graphical, std::string graphisme, std::string map) :
	_graphical(graphical)
{
	if (set_Txt_Map(map) == 0)
		generate_map_by_txt(set_Graphisme(graphisme));
	else
		generate_map(15, 15, get_texture_64());
}

//          GENERATION

void IndieStudio::Map::generate_map(int x, int y, std::vector<std::string> const texture_Path) noexcept
{
	std::string allah;
	bool check = false;
	srand(time(NULL));
	this->_x_map = x;
	this->_y_map = y;
	for (int j = 0, k = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, CUBE_SIDE, texture_Path.at(FLOOR)));
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_SIDE, texture_Path.at(WALL)));
			else {
				if (i % 2 == 0 && j > 1 && j < y - 2 && j % 2 == 0 && i > 0 && i < x - 1)
					this->_wall_inside_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_SIDE, texture_Path.at(WALL)));
				else {
					check = true;
					this->_cube_Destruc_map[k].push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_SIDE, texture_Path.at(BRICK)));
				}
			}
		}
		if (check == true) {
			k++;
			check = false;
		}
	}
	create_Start_Positon();
}

void IndieStudio::Map::generate_map_by_txt(std::vector<std::string> texture_Path) noexcept
{
	bool check = false;
	for (unsigned int j = 0, k = 0; j < _map_txt_vec.size(); j++) {
		for (unsigned int i = 0; i < _map_txt_vec[j].size(); i++) {
			this->_floor_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z, CUBE_SIDE, texture_Path.at(FLOOR)));
			if (_map_txt_vec[j][i] == '#')
				this->_wall_Vec.push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_SIDE, texture_Path.at(WALL)));
			if (_map_txt_vec[j][i] == 'B') {
				check = true;
				this->_cube_Destruc_map[k].push_back(createCubes(CUBE_X + (i * CUBE_SIDE), CUBE_Y + (j * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_SIDE, texture_Path.at(BRICK)));
			}
			if (_map_txt_vec[j][i] == 'P') {
				_pos_start.push_back({CUBE_X + (i * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_Y + (j * CUBE_SIDE)});
			}
			if(_map_txt_vec[j][i] == '.') {
				this->_free_Pos.push_back(IndieStudio::Pos{CUBE_X + (i * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_Y + (j * CUBE_SIDE)});
				this->_free_Absolute_Pos.push_back(std::shared_ptr<IndieStudio::Pos>(new IndieStudio::Pos{CUBE_X + (i * CUBE_SIDE), CUBE_Z + CUBE_SIDE, CUBE_Y + (j * CUBE_SIDE)}));
			}
		}
		if (check == true) {
			k++;
			check = false;
		}
	}
	adjustment_Position_Start();
}

void IndieStudio::Map::generateBySave(std::string map) noexcept
{
	auto delCubeVec = [this](std::vector<IndieStudio::IEntity *> &cube) {
		for(unsigned int i = 0; i != cube.size(); i++) {
			this->_graphical.deleteEntity(cube[i]);
		}
	};
	auto delCubeMap = [this]() {
		for (unsigned int j = 0; j < this->_cube_Destruc_map.size(); j++) {
			for (unsigned int i = 0; i != this->_cube_Destruc_map[j].size(); i++) {
				this->_graphical.deleteEntity(this->_cube_Destruc_map[j][i]);
			}
	}
	};
	delCubeVec(_floor_Vec);
	delCubeVec(_cube_Destruc_Vec);
	delCubeVec(_wall_Vec);
	delCubeVec(_wall_inside_Vec);
	delCubeMap();
	this->_free_Pos.clear();
	this->_free_Absolute_Pos.clear();
	this->_floor_Vec.clear();
	this->_pos_start.clear();
	this->_cube_Destruc_map.clear();
	this->_wall_Vec.clear();
	this->_wall_inside_Vec.clear();
	this->_cube_Destruc_Vec.clear();
	if (set_Txt_Map(map) == 0)	
		generate_map_by_txt(set_Graphisme(_graphisme));
	else
		generate_map(15, 15, get_texture_64());
}
IndieStudio::IEntity *IndieStudio::Map::createCubes(float x, float z, float y, float size, std::string texturePath) noexcept
{
	IndieStudio::IEntity *cube = this->_graphical.createCube(
		size,
		texturePath,
		IndieStudio::Pos(x, y, z));
	return (cube);
}

void IndieStudio::Map::delete_Wall(IndieStudio::IEntity *del)
{
	for (auto i = _wall_inside_Vec.begin(); i != _wall_inside_Vec.end(); i++) {
		if (*i == del) {
			this->_graphical.deleteEntity(del);
			this->_free_Absolute_Pos.push_back(std::shared_ptr<IndieStudio::Pos>(new IndieStudio::Pos((*i)->getPosition())));
			this->_wall_inside_Vec.erase(i);
			return;
		}
	}
}

void IndieStudio::Map::delete_Cube(IndieStudio::IEntity *del)
{
	for (unsigned int j = 0; j != this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			if (*i == del) {
				this->_free_Pos.push_back((*i)->getPosition());
				this->_free_Absolute_Pos.push_back(std::shared_ptr<IndieStudio::Pos>(new IndieStudio::Pos((*i)->getPosition())));
				this->_graphical.deleteEntity(del);
				this->_cube_Destruc_map[j].erase(i);
				return;
			}
		}
	}
}

//             GET

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getFloorCube(void) const noexcept
{
	return (this->_floor_Vec);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getBrickCube(void) noexcept
{
	std::vector<IndieStudio::IEntity *> cube;

	for (unsigned int j = 0; j < this->_cube_Destruc_map.size(); j++) {
		for (auto i = this->_cube_Destruc_map[j].begin(); i != this->_cube_Destruc_map[j].end(); i++) {
			cube.push_back(*i);
		}
	}
	return (cube);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getWallCube(void) const noexcept
{
	auto cube = this->_wall_Vec;
	for (auto i = _wall_inside_Vec.begin(); i != _wall_inside_Vec.end(); i++) {
		cube.push_back(*i);
	}
	return (cube);
}

std::vector<IndieStudio::Pos> IndieStudio::Map::get_Position_Start() const noexcept
{
	return (_pos_start);
}

std::vector<std::string> IndieStudio::Map::get_texture_64() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(FLOOR_TEXTURE_64);
	texture.push_back(WALL_TEXTURE_64);
	texture.push_back(BRICK_TEXTURE_64);
	return (texture);
}

std::vector<std::string> IndieStudio::Map::get_texture_128() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(FLOOR_TEXTURE_128);
	texture.push_back(WALL_TEXTURE_128);
	texture.push_back(BRICK_TEXTURE_128);
	return (texture);
}

std::vector<std::string> IndieStudio::Map::get_texture_256() const noexcept
{
	std::vector<std::string> texture;
	texture.push_back(FLOOR_TEXTURE_256);
	texture.push_back(WALL_TEXTURE_256);
	texture.push_back(BRICK_TEXTURE_256);
	return (texture);
}

IndieStudio::IEntity *IndieStudio::Map::get_Cube_By_Position(IndieStudio::Pos pos)
{
	auto brick = getBrickCube();
	for (unsigned int i = 0; i < brick.size(); i++) {
		if (brick.at(i)->getPosition() == pos)
			return (brick.at(i));
	}
	auto wall = getWallCube();
	for (unsigned int i = 0; i < wall.size(); i++) {
		if (wall.at(i)->getPosition() == pos)
			return (wall.at(i));
	}
	return(nullptr);
}

std::vector<IndieStudio::Pos> IndieStudio::Map::getFreePos(void) noexcept
{
	return (this->_free_Pos);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getAllCube(void) noexcept
{
	auto add = [this](std::vector<IndieStudio::IEntity *> &dest, std::vector<IndieStudio::IEntity *> src) {
		for (unsigned i = 0; i != src.size(); i++)
			dest.push_back(src[i]);
			return(dest);
	};
	std::vector<IndieStudio::IEntity *> cube; 
	add(cube,getBrickCube());
	add(cube,getWallCube());
	return (cube);
}

std::vector<std::shared_ptr<IndieStudio::Pos>> IndieStudio::Map::getFree_Absolute_Pos(void) noexcept
{
	return (this->_free_Absolute_Pos);
}

std::vector<IndieStudio::IEntity *> IndieStudio::Map::getWallInsideCube(void) noexcept
{
	return (this->_wall_inside_Vec);
}
std::vector<IndieStudio::IEntity *> IndieStudio::Map::getWallOutsideCube(void) noexcept
{
	return(this->_wall_Vec);
}

//              SET

int IndieStudio::Map::set_Txt_Map(std::string map)
{
	std::ifstream file(map);
	std::string line;
	if (file.is_open()) {
		while (getline(file, line))
			_map_txt_vec.push_back(reverseStr(line));
		file.close();
		adjustment_Map_Txt();
		return (check_format_map_txt());
	} else {
		std::cout << "Can't open file, " << map << ". Random generation map used\n";
		return (-1);
	}
	return (0);
}

std::vector<std::string> IndieStudio::Map::set_Graphisme(std::string const path) const noexcept
{
	if ("256" == path)
		return (get_texture_256());
	else if ("128" == path)
		return (get_texture_128());
	else if ("64" == path)
		return (get_texture_64());
	std::cout << "Graphism " << path << " doesnt exist, only 64, 128 and 256 exist. It set to 64 by default\n";
	return (get_texture_64());
}

void IndieStudio::Map::set_Density_Brick(float percent)
{
	auto nb = (percent / 100) * this->getBrickCube().size();
	for (unsigned int i = 0; i < nb; i++) {
		auto randPos = rand()%(this->getBrickCube().size()-1 + 1) + 0;
			delete_Cube(this->getBrickCube()[randPos]);
	}
}

void IndieStudio::Map::set_Density_Wall(float percent)
{
	auto nb = (percent / 100) * this->getWallInsideCube().size();
	for (unsigned int i = 0; i < nb; i++) {
		auto randPos = rand()%(this->getWallInsideCube().size()-0 + 1) + 0;
			delete_Wall(this->getWallInsideCube()[randPos]);
	}
}

void IndieStudio::Map::init_pos_start() noexcept
{
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
	_pos_start.push_back(IndieStudio::Pos{0,0,0});
}

//              CHECK

int IndieStudio::Map::check_format_map_txt() noexcept
{
	for (unsigned int j = 0; j < _map_txt_vec.size(); j++) {
		for (unsigned int i = 0; i < _map_txt_vec[j].size() - 1; i++) {
			if (_map_txt_vec[j][i] == '.' || _map_txt_vec[j][i] == '#' || _map_txt_vec[j][i] == 'B' || _map_txt_vec[j][i] == 'P' || _map_txt_vec[j][i] == ' ')
				;
			else {
				std::cout << "Bad Format, Format : Wall = '#', Brick = 'B', Empty = '.', Positon Player = 'P'. Random generation Used\n";
				return (-1);
			}
		}
	}
	return (0);
}

//            OTHER

void IndieStudio::Map::adjustment_Position_Start() noexcept
{
	if (_pos_start.size() < 4) {
		for (int i = _pos_start.size() - 1; i != 4; i++) {
			_pos_start.push_back({0, 0, 0});
		}
	}
	for (auto i = _pos_start.begin(); i != _pos_start.end(); i++) {
		i->_y += 10;
		i->_x += 5;
	}
}

void IndieStudio::Map::adjustment_Map_Txt()
{
	std::vector<std::string> res = _map_txt_vec;
	std::string line;
	std::string letter;

	_map_txt_vec.clear();
	for (int i = res.size() - 1; i != -1; i--) {
		_map_txt_vec.push_back(res.at(i));
	}
	res.clear();
	for (unsigned int i = 0; i != _map_txt_vec[0].size(); i++) {
		for (unsigned int j = 0; j != _map_txt_vec.size(); j++) {
			letter = _map_txt_vec[j][i];
			line.append(letter);
		}
		res.push_back(line);
		line = "";
	}
	_map_txt_vec.clear();
	_map_txt_vec = res;
}

std::string IndieStudio::Map::reverseStr(std::string &str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
		std::swap(str[i], str[n - i - 1]);
	return (str);
}

void IndieStudio::Map::create_Start_Positon(void) noexcept
{
	_pos_start.clear();
	delete_Cube(this->_cube_Destruc_map[1].at(0));
	delete_Cube(this->_cube_Destruc_map[0].at(1));
	_pos_start.push_back(this->_cube_Destruc_map[0].at(0)->getPosition());
	delete_Cube(this->_cube_Destruc_map[0].at(0));
	delete_Cube(this->_cube_Destruc_map[1].at(this->_cube_Destruc_map[1].size() - 1));
	delete_Cube(this->_cube_Destruc_map[0].at(this->_cube_Destruc_map[0].size() - 2));
	_pos_start.push_back(this->_cube_Destruc_map[0].at(this->_cube_Destruc_map[0].size() - 1)->getPosition());
	delete_Cube(this->_cube_Destruc_map[0].at(this->_cube_Destruc_map[0].size() - 1));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 2].at(0));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(1));
	_pos_start.push_back(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(0)->getPosition());
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(0));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 2].at(this->_cube_Destruc_map[1].size()));
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(this->_cube_Destruc_map[0].size()));
	_pos_start.push_back(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(this->_cube_Destruc_map[0].size())->getPosition());
	delete_Cube(this->_cube_Destruc_map[_cube_Destruc_map.size() - 1].at(this->_cube_Destruc_map[0].size()));
	adjustment_Position_Start();
}

void IndieStudio::Map::clearFreePos() noexcept
{
	this->_free_Pos.clear();
}

void IndieStudio::Map::generateSave()
{
	std::vector<std::string> save_txt;
	auto isCube = [](IndieStudio::Pos pos, std::vector<IndieStudio::IEntity*> cube) {
		for (unsigned int i = 0; i != cube.size(); i++) {
			if (cube[i]->getPosition() == pos)
				return (true);
		}
		return (false);
	};
	for (float y = 0, i = 0; y != this->_y_map * CUBE_SIDE; y += CUBE_SIDE, i++) {
		for (float x = 0, j = 0; x != this->_x_map * CUBE_SIDE; x += CUBE_SIDE, j++) {
			//std::cout << "POS = " << this->_wall_Vec[i]->getPosition()._x << " " <<this->_wall_Vec[i]->getPosition()._y << " " <<this->_wall_Vec[i]->getPosition()._z << "\n";
			if (isCube(IndieStudio::Pos{y,CUBE_SIDE,x}, this->_wall_Vec) == true)
				std::cout << "#";
			else if (isCube(IndieStudio::Pos{y,CUBE_SIDE,x}, this->_wall_inside_Vec) == true)
				std::cout << "#";
			else if (isCube(IndieStudio::Pos{y,CUBE_SIDE,x}, getBrickCube()) == true)
				std::cout << "B";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
}

IndieStudio::Map::~Map()
{
}
