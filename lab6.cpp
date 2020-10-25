#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void setcolor(int fg,int bg)
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, bg*16+fg);
}
void draw_ship(int x,int y)
{
	gotoxy(x,y);setcolor(2,4); printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x,y);setcolor(2,0);printf("        ");
}
void draw_bullet(int x,int y)
{
	gotoxy(x,y);setcolor(2,0);printf("^");
}
void clear_bullet(int x,int y)
{
	gotoxy(x,y);setcolor(0,0);printf(" ");
}
void draw_star(int x,int y)
{
	gotoxy(x,y);setcolor(7,0);printf("*");
}
void spawn_star()
{
	int i,x,y;
	srand( time( NULL ) );
	for (i = 0;i < 20;i++){
		x = rand()%61;
		y = rand()%4;	
		draw_star(x+10,y+2);
	}
}
void new_star(int x,int y)
{
	setcolor(7,0),
	srand( time( NULL ) );
	x = rand()%61;
	y = rand()%4;
	gotoxy(x+10,y+2);printf("*");
}
void score(int x,int y,int point){
	gotoxy(x=75,y=0);setcolor(1,8);printf(" %d ",point);
}
char cursor(int x, int y){
HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
char buf[2]; COORD c = {x,y}; DWORD num_read;
if(
!ReadConsoleOutputCharacter(hStd,(LPTSTR)buf,1,c,(LPDWORD)&num_read) )

return '\0';
else
return buf[0];

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
	char ch='.';
	int x=38,y=20;
	int point = 0;
	int bx,by,i;
	int bullet = 0;
	spawn_star();
	draw_ship(x,y);
	score(x,y,point);
	setcursor(0);
	do {
		if (x == 80) { erase_ship(x, y),draw_ship(x=0, y); }
		else if (x == 0) {erase_ship(x, y), draw_ship(x=80, y); }
		if (_kbhit()){
			ch=_getch();
			if(ch=='a') {erase_ship(x, y),draw_ship(--x,y);}
			if(ch=='s') {erase_ship(x, y),draw_ship(++x,y);}
			if(bullet!=1 && ch==' ') {bullet=1; bx=x+3; by=y-1;}
			fflush(stdin);
		}
		if (bullet==1) {
			clear_bullet(bx,by);
			if (by==2) {bullet=0;} 
			if(cursor(bx,by-1)== '*'){
				score(x,y,++point);
				new_star(x,y);
				Beep(783.99,100);
				clear_bullet(bx,by-1);	
			}
			if (by > 2) { draw_bullet(bx,--by);}
		}
		Sleep(80);
		
		} while (ch!='x');
		
return 0;
}
