#include <curses.h>
//
#include <typedef.hpp>
#include <map.hpp>
#include "snake.hpp"

Snake::Snake( Map &map, Point const &position ) :
	mMap( map ),
	mScore( 0 )
{
	mBody.push_back( position );
}

void Snake::setDirection( Direction const &direction )
{
	mDirection = direction;
}

void Snake::move()
{
	mBody.insert( mBody.begin(), mBody[ 0 ]);
	if( mBody[ 0 ].x == mMap.getApple().x && mBody[ 0 ].y == mMap.getApple().y )
	{
		mScore++;
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
		default:
			break;
	}
}

void Snake::render() const
{
	mvwaddch( mMap.window, mBody[ 0 ].y + 1, mBody[ 0 ].x + 1, 'O' );
	for( unsigned int i = 1; i < mBody.size(); i++ )
	{
		mvwaddch( mMap.window, mBody[ i ].y + 1, mBody[ i ].x + 1, '#' );
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

unsigned int const &Snake::getScore() const noexcept
{
	return mScore;
}
