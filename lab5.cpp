#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void setcolor(int fg,int bg)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void gotoxy(int x, int y)
{
COORD c = { x, y };
SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void draw_ship(int x, int y)
{
	gotoxy(x,y);
	setcolor(2,4); 
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x,y);
	setcolor(2,0);
	printf("        ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x,y);
	setcolor(2,0);
	printf("^");
}
void erase_bullet(int x, int y)
{
	gotoxy(x,y);
	setcolor(2,0);
	printf("   ");
}
void setcursor(bool visible)
{
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO lpCursor;
lpCursor.bVisible = visible;
lpCursor.dwSize = 20;
SetConsoleCursorInfo(console,&lpCursor);
}
int main()
{
	char ch ='.',drt = 'S';
	int x = 40, y = 10;//ship
	int bx[5],by[5],bc = 0;//bullet
	setcursor(0);
	draw_ship(x, y);
	do {
		/*window size */
		if (x == 80) { erase_ship(x, y), draw_ship(--x, y); }
		else if (x == 0) { erase_ship(x, y), draw_ship(++x, y); }
		else if (y == 20) { erase_ship(x, y), draw_ship(x, --y); }
		else if (y == 0) { erase_ship(x, y), draw_ship(x, ++y); }
		
		/*hit check*/
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { drt = 'L';}	//left
			else if (ch == 'd') { drt = 'R';}	//right
			else if (ch == 'w') { drt = 'U';}	//up
			else if (ch == 's') { drt = 'D';}	//down
			else if (ch == 'e') { drt = 'S';}	//stop
			else if (ch == ' '&& bc < 5) 		//bullet status & position
			{
				bx[bc]=x+3;
				by[bc]=y-1;
				draw_bullet(bx[bc],by[bc]);
				bc += 1;
			}
			fflush(stdin);
		}
		
		/*direction check*/
		if (drt == 'L') {erase_ship(x,y),draw_ship(--x,y);}
		else if (drt == 'R') {erase_ship(x,y),draw_ship(++x,y);}
		else if (drt == 'U') {erase_ship(x,y),draw_ship(x,--y);}
		else if (drt == 'D') {erase_ship(x,y),draw_ship(x,++y);}
		else if (drt == 'S') {;}
		
		/*bullet movement*/
		if ( bc == 1 ){
			erase_bullet(bx[0],by[0]);
			if (by[0] > 0){draw_bullet(bx[0],--by[0]);}
			else bc-=1;	
		}
		else if ( bc == 2 ){
			erase_bullet(bx[0],by[0]);
			erase_bullet(bx[1],by[1]);
			if (by[0] > 0){draw_bullet(bx[0],--by[0]);}
			if (by[1] > 0){draw_bullet(bx[1],--by[1]);}
			else bc-=1;	
		}
		else if ( bc == 3 ){
			erase_bullet(bx[0],by[0]);
			erase_bullet(bx[1],by[1]);
			erase_bullet(bx[2],by[2]);
			if (by[0] > 0){draw_bullet(bx[0],--by[0]);}
			if (by[1] > 0){draw_bullet(bx[1],--by[1]);}
			if (by[2] > 0){draw_bullet(bx[2],--by[2]);}
			else bc-=1;	
		}
		else if ( bc == 4 ){
			erase_bullet(bx[0],by[0]);
			erase_bullet(bx[1],by[1]);
			erase_bullet(bx[2],by[2]);
			erase_bullet(bx[3],by[3]);
			if (by[0] > 0){draw_bullet(bx[0],--by[0]);}
			if (by[1] > 0){draw_bullet(bx[1],--by[1]);}
			if (by[2] > 0){draw_bullet(bx[2],--by[2]);}
			if (by[3] > 0){draw_bullet(bx[3],--by[3]);}
			else bc-=1;	
		}
		else if ( bc == 5 ){
			erase_bullet(bx[0],by[0]);
			erase_bullet(bx[1],by[1]);
			erase_bullet(bx[2],by[2]);
			erase_bullet(bx[3],by[3]);
			erase_bullet(bx[4],by[4]);
			if (by[0] > 0){draw_bullet(bx[0],--by[0]);}
			if (by[1] > 0){draw_bullet(bx[1],--by[1]);}
			if (by[2] > 0){draw_bullet(bx[2],--by[2]);}
			if (by[3] > 0){draw_bullet(bx[3],--by[3]);}
			if (by[4] > 0){draw_bullet(bx[4],--by[4]);}
			else bc-=1;	
		}
	Sleep(50);
	} while (ch != 'x');
	return 0;
}
