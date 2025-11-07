//#include <stdio.h>
// #include <GLFW/glfw3.h>

#include <ncurses.h>

#include "Math.c"

int main(){
	//printf("olá mundo");
	
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	printw("Ola mundo :)\n");
	
	for(int i = 0; i < 20; i++){
		int ch = getch();
		/*if(ch == KEY_F(1)){
			printw("F1 :)\n");
		} else {
			printw("%c",ch);
		}*/
		addch(ch);
	}
	
	endwin();
	
	return 0;
}
