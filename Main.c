//#include <stdio.h>
// #include <GLFW/glfw3.h>

#include <ncurses.h>
#include <math.h>
#include "Math.c"

int main(){
	//printf("olá mundo");
	
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	printw("Ola mundo :)\n");
	
	for(int i = 0; i < 128; i++){
		int ch = getch();
		move(15+10*sin(i*0.1),i);
		addch(ch | A_UNDERLINE);
	}

	endwin();
	
	return 0;
}
