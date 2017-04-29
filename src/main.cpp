#include <cstdlib>
#include <unistd.h>
#include <ctime>
//
#include <curses.h>
//
#include <map.hpp>
#include <snake.hpp>


int main()
{
	srand( time( NULL ));
	initscr();
	curs_set( 0 );
	noecho();
	Map map({ 0, 0 }, { 15, 15 });
	Snake snake( map, { 12, 12 });
	Map map2({ 16, 0 }, { 10, 10 });
	Snake snake2( map2, { 5, 5 });
	clear();
	refresh();
	timeout( 100 );
	while( !snake.isDead() && !snake2.isDead())
	{
		map.render();
		snake.render();
		map2.render();
		snake2.render();
		move( map.getSize().y + 2, 0 );
		//printw( "Score: " );
		//printw( "%d", snake.getScore());
		wrefresh( map.window );
		wrefresh( map2.window );
		switch( getch())
		{
			case 'w':
				snake.setDirection( UP );
				snake2.setDirection( UP );
				break;
			
			case 'a':
				snake.setDirection( LEFT );
				snake2.setDirection( LEFT );
				break;
			
			case 's':
				snake.setDirection( DOWN );
				snake2.setDirection( DOWN );
				break;
				
			case 'd':
				snake.setDirection( RIGHT );
				snake2.setDirection( RIGHT );
				break;
				
			default:
				break;
		}
		snake.move();
		snake2.move();
		wclear( map.window );
		wclear( map2.window );
	}
	wclear( map.window );
	printw( "U are ded m8." );
	refresh();
	//sleep( 1 );
	endwin();
	return 0;
}
