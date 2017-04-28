#include <curses.h>
//
#include <typedef.hpp>
#include <map.hpp>
#include "snake.hpp"

Snake::Snake( Map &map, Point const &position ) :
	mMap( map )
{
	mBody.push_back( position );
}

void Snake::move( Direction const &direction )
{
	mDirection = direction;
	move();
}

void Snake::move()
{
	mBody.insert( mBody.begin(), mBody[ 0 ]);
	if( mBody[ 0 ].x == mMap.getApple().x && mBody[ 0 ].y == mMap.getApple().y )
	{
		mMap.createApple();
	}
	else
	{
		mBody.pop_back();
	}
	switch( mDirection )
	{
		case UP:
			if( mBody[ 0 ].y == 0 )
			{
				mBody[ 0 ].y = mMap.getSize().y - 1;
			}
			else
			{
				mBody[ 0 ].y--;
			}
			break;
		
		case LEFT:
			if( mBody[ 0 ].x == 0 )
			{
				mBody[ 0 ].x = mMap.getSize().x - 1;
			}
			else
			{
				mBody[ 0 ].x--;
			}
			break;
		
		case DOWN:
			if( mBody[ 0 ].y + 1 >= mMap.getSize().y )
			{
				mBody[ 0 ].y = 0;
			}
			else
			{
				mBody[ 0 ].y++;
			}
			break;
		
		case RIGHT:
			if( mBody[ 0 ].x + 1 >= mMap.getSize().x )
			{
				mBody[ 0 ].x = 0;
			}
			else
			{
				mBody[ 0 ].x++;
			}
			break;
	}
}

void Snake::render() const
{
	for( auto &i : mBody )
	{
		mvaddch( i.y, i.x, '#' );
	}
}

bool Snake::isDead() const
{
	for( unsigned int i = 1; i < mBody.size(); i++ )
	{
		if( mBody[ i ].x == mBody[ 0 ].x && mBody[ i ].y == mBody[ 0 ].y )
		{
			return true;
		}
	}
	return false;
}
