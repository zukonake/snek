#pragma once

#include <typedef.hpp>

class Map
{
public:
	Map( Point const &size );
	
	void render() const;
	void createApple();
	
	Point const &getSize() const noexcept;
	Apple const &getApple() const noexcept;
private:
	Point mSize;
	Apple mApple;
};
