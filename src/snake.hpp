#pragma once

#include <vector>
//
#include <typedef.hpp>

class Map;

class Snake
{
public:
	Snake( Map &map, Point const &position );
	
	void move( Direction const &direction );
	void move();
	void render() const;
	bool isDead() const;
private:
	void eat();
	
	std::vector< Segment > mBody;
	Map &mMap;
	Direction mDirection;
};
