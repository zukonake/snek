#pragma once

#include <vector>
//
#include <typedef.hpp>

class Map;

class Snake
{
public:
	Snake( Map &map, Point const &position );
	
	void setDirection( Direction const &direction );
	void move();
	void render() const;
	bool isDead() const;
	unsigned int const &getScore() const noexcept;
private:
	void eat();
	
	std::vector< Segment > mBody;
	Map &mMap;
	Direction mDirection;
	unsigned int mScore;
};
