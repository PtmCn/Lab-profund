#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void setcolor(int fg,int bg)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void draw_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2,4);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	setcolor(2,0);
	printf("        ");
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
	char ch = ' ';
	int x = 40, y = 10;
	setcursor(0);
	draw_ship(x, y);
	do {
		if (x == 80) { erase_ship(x, y), draw_ship(--x, y); }
		if (x == 0) { erase_ship(x, y), draw_ship(++x, y); }
		if (y == 20) { erase_ship(x, y), draw_ship(x, --y); }
		if (y == 0) { erase_ship(x, y), draw_ship(x, ++y); }
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { erase_ship(x, y),draw_ship(--x, y); }
			if (ch == 'd') { Sleep(50),erase_ship(x, y),draw_ship(++x, y); }
			if (ch == 'w') { erase_ship(x,y),draw_ship(x, --y); }
			if (ch == 's') { erase_ship(x,y),draw_ship(x, ++y); }
			fflush(stdin);
		}
	} while (ch != 'x');
	return 0;
}
