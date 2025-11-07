//#include <stdio.h>
// #include <GLFW/glfw3.h>
#include <ncurses.h>

int main(){
	//printf("olá mundo");
	
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	// noecho();
	
	for(int i = 0; i < 20; i++){
		printw("Ola mundo :)\n");

		int ch = getch();
		if(ch == KEY_F(1)){
			printw("F1\n");
		}
	}

	endwin();
	
	return 0;
}
