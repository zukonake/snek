#pragma once

#include <curses.h>
//
#include <typedef.hpp>

class Map
{
public:
	Map( Point const &position, Point const &size );
	
	~Map();
	
	void render() const;
	void createApple();
	
	Point const &getSize() const noexcept;
	Apple const &getApple() const noexcept;
private:
	Point mPosition;
	Point mSize;
	Apple mApple;
public:
	WINDOW *window;
};
