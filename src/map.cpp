#include <cstdlib>
//
#include <curses.h>
//
#include <typedef.hpp>
#include "map.hpp"

Map::Map( Point const &size ) :
	mSize( size )
{
	mApple.x = rand() % size.x;
	mApple.y = rand() % size.y;
}

void Map::render() const
{
	mvaddch( mApple.y, mApple.x, '@' );
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
