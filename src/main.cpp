#include <cstdlib>
#include <ctime>
//
#include <curses.h>
//
#include <map.hpp>
#include <snake.hpp>

Map map({ 20, 20 });

Snake snake( map, { 10, 10 });

int main()
{
	srand( time( NULL ));
	initscr();
	halfdelay( 2 );
	while( !snake.isDead())
	{
		char choice = getch();
		switch( choice )
		{
			case 'w':
				snake.move( UP );
				break;
			
			case 'a':
				snake.move( LEFT );
				break;
			
			case 's':
				snake.move( DOWN );
				break;
			
			case 'd':
				snake.move( RIGHT );
				break;
			
			default:
				snake.move();
				break;
		}
		clear();
		snake.render();
		map.render();
		move( 0, 0 );
		refresh();
	}
	endwin();
	return 0;
}
