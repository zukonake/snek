#include <cstdlib>
//
#include <curses.h>
//
#include <typedef.hpp>
#include "map.hpp"

Map::Map( Point const &position, Point const &size ) :
	mPosition( position ),
	mSize( size ),
	window( newwin( mSize.y + 2 , mSize.x + 2, mPosition.y, mPosition.x ))
{
	mApple.x = rand() % size.x;
	mApple.y = rand() % size.y;
}

Map::~Map()
{
	delwin( window );
}

void Map::render() const
{
	mvwaddch( window, mApple.y + 1, mApple.x + 1, '@' );
	box( window, '|', '-' );
}

void Map::createApple()
{
	mApple.x = rand() % mSize.x;
	mApple.y = rand() % mSize.y;
}

Point const &Map::getSize() const noexcept
{
	return mSize;
}

Apple const &Map::getApple() const noexcept
{
	return mApple;
}
