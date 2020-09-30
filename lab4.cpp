#include<stdio.h>
#include<conio.h>
#include<Windows.h>
void draw_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("      ");
}
int main()
{
	char ch = ' ';
	int x = 40, y = 10;
	draw_ship(x, y);
	do {
		if (x == 80) { draw_ship(--x, y); }
		if (x == 0) { draw_ship(++x, y); }
		if (y == 20) { erase_ship(x, y), draw_ship(x, --y); }
		if (y == 0) { erase_ship(x, y), draw_ship(x, ++y); }
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 'd') { draw_ship(++x, y); }
			if (ch == 'w') { erase_ship(x,y),draw_ship(x, --y); }
			if (ch == 's') { erase_ship(x,y),draw_ship(x, ++y); }
			fflush(stdin);
		}
		Sleep(50);
	} while (ch != 'x');
	return 0;
}