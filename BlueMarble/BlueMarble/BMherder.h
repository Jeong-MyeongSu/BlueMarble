#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define RED (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define BLUE (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define PINK (RED | BLUE)
#define WHITE (RED | GREEN | BLUE)
#define GREEN (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define YELLOW (RED | GREEN)
#define SKYBLUE (GREEN | BLUE)
#define ORIGINAL 0x0007
#define GRAY 0x0008
#define BROWN 0x04

#define RED_BG (BACKGROUND_RED | BACKGROUND_INTENSITY)
#define BLUE_BG (BACKGROUND_BLUE | BACKGROUND_INTENSITY)
#define PINK_BG (RED_BG | BLUE_BG)
#define WHITE_BG (RED_BG | GREEN_BG | BLUE_BG)
#define GREEN_BG (BACKGROUND_GREEN | BACKGROUND_INTENSITY)
#define YELLOW_BG (RED_BG | GREEN_BG)
#define SKYBLUE_BG (GREEN_BG | BLUE_BG)

#define delay(n) Sleep(n)							// n/1000초만큼 시간 지연
#define randomize() srand((unsigned)time(NULL))		// 난수 발생기 초기화
#define random(n) (rand() % (n))					//0~n까지의 난수 발생

#define Maxturn 30
#define dice 6


#define LEFT 75
#define UP 72
#define RIGHT 77
#define DOWN 80

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

//플레이어의 인터페이스상의 좌표
typedef struct {
	int x;
	int y;

}point;

typedef struct {  //도시 정보
	int property;
	int vacationhome;
	int vhflag;
	int building;
	int bdflag;
	int hotel;
	int htflag;
	int pd;
	int expo;
	int mountain;
}land;

typedef struct { //플레이어 정보
	int cash;
	int asset;
	int landall;
	int die;
	int position;
	int tflag;
	int unisland;
}info;

typedef struct {
	int select;
	char* land;
}buy;

//basic.h
void putixy(int x, int y, int d);
void putsxy(int x, int y, char* c);
void putchxy(int x, int y, char c);
void clrscr();
void gotoxy(int x, int y);
void setcursortype(CURSOR_TYPE c);
void resz(int w, int h);
void setColor(WORD Attribute);
void selectColor(int block);
int wherex();
int wherey();
BOOL IsKeyDown(int Key);

//interface.h
void InitInterface();
void printBox();
void printCityName();
void printPlayer();
void pirntInfo();
void printUserBox();
void UpdateCash(int user, int cash);
void PrintLand(int player, int position);
void DeleteAllLand(int player);

//initgame.h
void InitGame();

//playGame.h
void playGame();
void ThrowDice();
void MovePlayer(int player);
void GetEvent(int player, int position);
void GetTrain(int player);
void Player(int player, int cash);
void GetRandom(int revent, int pn, int player);
void RandomMovePlayer(int player, int revent, int pn);
void TreadLand(int player, int position, int cash);
void buyland(int player, int position, int cash);
void rebuyland(int player, int position, int cash);
void paylandevent(int player, int position, int cash, int debt);
void bankuptcy(int player, int position, int cash, int debt);
void payland(int player, int debt);
void TreadPark(int player, int position, int cash);
void TreadMountain(int player, int position, int cash);
void Expo(int player, int position);