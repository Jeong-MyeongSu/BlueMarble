#include "BMherder.h"

char BlueMarble[22] = { "B l u e  M a r b l e" };
char box[8][17] = {
		"□□□□□",
		"□      □",
		"□      □",
		"□      □",
		"□□□□□"
};
char userbox[10][20] = {
		"□□□□□□□□□",
		"□              □",
		"□              □",
		"□              □",
		"□              □",
		"□              □",
		"□              □",
		"□□□□□□□□□"
};

point playerxy[4][40];
land landinfo[40];
info playerinfo[4];


extern pnum;



void InitInterface() {
	int i, c;
	resz(122, 60);
	//테두리
	for (i = 0; i < 100; i++) {
		gotoxy(i, 49); putch('-');
	}
	for (i = 0; i < 50; i++) {
		gotoxy(99, i); putch('|');
	}

	//브루마블 글씨
	gotoxy(38, 23);
	c = 0;
	for (i = 0; i < 23; i++) {
		if (c == 4) {
			c = 0;
		}
		if (i % 2 == 0) {
			selectColor(c);
			c++;
		}

		printf("%c", BlueMarble[i]);
	}

	setColor(WHITE);
	printBox();
	printCityName();
	pirntInfo();
	


}

void printBox() {

	int i;
	
	for (i = 0; i < 6; i++) {
		gotoxy(2, 41 + i); puts(box[i]);
		gotoxy(2, 37 + i); puts(box[i]);
		gotoxy(2, 33 + i); puts(box[i]);
		gotoxy(2, 29 + i); puts(box[i]);
		gotoxy(2, 25 + i); puts(box[i]);
		gotoxy(2, 21 + i); puts(box[i]);
		gotoxy(2, 17 + i); puts(box[i]);
		gotoxy(2, 13 + i); puts(box[i]);
		gotoxy(2, 9 + i); puts(box[i]);
		gotoxy(2, 5 + i); puts(box[i]);
		gotoxy(2, 1 + i); puts(box[i]);
	}
	for (i = 0; i < 6; i++) {
		gotoxy(10, 1 + i); puts(box[i]);
		gotoxy(18, 1 + i); puts(box[i]);
		gotoxy(26, 1 + i); puts(box[i]);
		gotoxy(34, 1 + i); puts(box[i]);
		gotoxy(42, 1 + i); puts(box[i]);
		gotoxy(50, 1 + i); puts(box[i]);
		gotoxy(58, 1 + i); puts(box[i]);
		gotoxy(66, 1 + i); puts(box[i]);
		gotoxy(74, 1 + i); puts(box[i]);
		gotoxy(82, 1 + i); puts(box[i]);
	}
	for (i = 0; i < 6; i++) {
		gotoxy(82, 41 + i); puts(box[i]);
		gotoxy(82, 37 + i); puts(box[i]);
		gotoxy(82, 33 + i); puts(box[i]);
		gotoxy(82, 29 + i); puts(box[i]);
		gotoxy(82, 25 + i); puts(box[i]);
		gotoxy(82, 21 + i); puts(box[i]);
		gotoxy(82, 17 + i); puts(box[i]);
		gotoxy(82, 13 + i); puts(box[i]);
		gotoxy(82, 9 + i); puts(box[i]);
		gotoxy(82, 5 + i); puts(box[i]);
	}
	for (i = 0; i < 6; i++) {
		gotoxy(10, 41 + i); puts(box[i]);
		gotoxy(18, 41 + i); puts(box[i]);
		gotoxy(26, 41 + i); puts(box[i]);
		gotoxy(34, 41 + i); puts(box[i]);
		gotoxy(42, 41 + i); puts(box[i]);
		gotoxy(50, 41 + i); puts(box[i]);
		gotoxy(58, 41 + i); puts(box[i]);
		gotoxy(66, 41 + i); puts(box[i]);
		gotoxy(74, 41 + i); puts(box[i]);

	}

}

void printCityName() {

	gotoxy(4, 42); puts("Start");
	setColor(SKYBLUE_BG);
	gotoxy(4, 38); puts("서귀포");
	setColor(WHITE);
	gotoxy(4, 34); puts("랜  덤");
	setColor(SKYBLUE_BG);
	gotoxy(4, 30); puts("제  주");
	setColor(WHITE);
	gotoxy(4, 26); puts("랜  덤");
	setColor(BLUE);
	gotoxy(4, 22); puts("북한산");
	setColor(SKYBLUE_BG);
	gotoxy(4, 18); puts("경  주");
	setColor(RED);
	gotoxy(4, 14); puts("공원 1");
	setColor(SKYBLUE_BG);
	gotoxy(4, 10); puts("안  동");
	gotoxy(4, 6); puts("통  영");
	setColor(WHITE);
	gotoxy(4, 2); puts("무인도");

	setColor(BLUE_BG);
	gotoxy(12, 2); puts("강  릉");
	gotoxy(20, 2); puts("원  주");
	setColor(WHITE);
	gotoxy(28, 2); puts("랜  덤");
	setColor(BLUE_BG);
	gotoxy(36, 2); puts("춘  천");
	setColor(BLUE);
	gotoxy(44, 2); puts("설악산");
	setColor(BLUE_BG);
	gotoxy(52, 2); puts("청  주");
	gotoxy(60, 2); puts("천  안");
	setColor(WHITE);
	gotoxy(68, 2); puts("랜  덤");
	setColor(BLUE_BG);
	gotoxy(76, 2); puts("세  종");
	setColor(WHITE);
	gotoxy(84, 2); puts("엑스포");

	setColor(PINK_BG);
	gotoxy(84, 6); puts("목  포");
	setColor(WHITE);
	gotoxy(84, 10); puts("랜  덤");
	setColor(PINK_BG);
	gotoxy(84, 14); puts("여  수");
	gotoxy(84, 18); puts("전  주");
	setColor(BLUE);
	gotoxy(84, 22); puts("지리산");
	setColor(PINK_BG);
	gotoxy(84, 26); puts("포  항");
	setColor(WHITE);
	gotoxy(84, 30); puts("랜  덤");
	setColor(PINK_BG);
	gotoxy(84, 34); puts("울  산");
	gotoxy(84, 38); puts("대  구");
	setColor(WHITE);
	gotoxy(84, 42); puts("기  차");

	setColor(RED_BG);
	gotoxy(76, 42); puts("인  천");
	gotoxy(68, 42); puts("대  전");
	setColor(RED);
	gotoxy(60, 42); puts("공원 2");
	setColor(RED_BG);
	gotoxy(52, 42); puts("광  주");
	setColor(BLUE);
	gotoxy(44, 42); puts("한라산");
	setColor(WHITE);
	gotoxy(36, 42); puts("랜  덤");
	setColor(RED_BG);
	gotoxy(28, 42); puts("부  산");
	setColor(WHITE);
	gotoxy(20, 42); puts("랜  덤");
	setColor(RED_BG);
	gotoxy(12, 42); puts("서  울");

	setColor(WHITE);
}

void printPlayer(){

	if (pnum == 2) {
		setColor(RED);
		gotoxy(playerxy[0][0].x, playerxy[0][0].y); puts("①");
		setColor(BLUE);
		gotoxy(playerxy[1][0].x, playerxy[1][0].y); puts("②");
	}
	else if (pnum == 3) {
		setColor(RED);
		gotoxy(playerxy[0][0].x, playerxy[0][0].y); puts("①");
		setColor(BLUE);
		gotoxy(playerxy[1][0].x, playerxy[1][0].y); puts("②");
		setColor(YELLOW);
		gotoxy(playerxy[2][0].x, playerxy[2][0].y); puts("③");
	}
	else {
		setColor(RED);
		gotoxy(playerxy[0][0].x, playerxy[0][0].y); puts("①");
		setColor(BLUE);
		gotoxy(playerxy[1][0].x, playerxy[1][0].y); puts("②");
		setColor(YELLOW);
		gotoxy(playerxy[2][0].x, playerxy[2][0].y); puts("③");
		setColor(GREEN);
		gotoxy(playerxy[3][0].x, playerxy[3][0].y); puts("④");
	}
	setColor(WHITE);
}

void pirntInfo() {
	gotoxy(101, 1); printf("스페이스바 : 확인 ");
	gotoxy(101, 2); printf("  좌우키   : 이동");
	gotoxy(43, 13); printf("남은 턴 : ");
	
}

void printUserBox() {
	int i;

	if (pnum == 2) {
		for (i = 0; i < 8; i++) {
			gotoxy(101, 6 + i); puts(userbox[i]);
		}
		gotoxy(103, 7); puts("1p");
		gotoxy(103, 8); printf("총 자산 : %d", playerinfo[0].asset);
		gotoxy(103, 9); printf("현금 : %d", playerinfo[0].cash);
		for (i = 0; i < 8; i++) {
			gotoxy(101, 16 + i); puts(userbox[i]);
		}
		gotoxy(103, 17); puts("2p");
		gotoxy(103, 18); printf("총 자산 : %d", playerinfo[1].asset);
		gotoxy(103, 19); printf("현금 : %d", playerinfo[1].cash);
	}
	else if (pnum == 3) {
		for (i = 0; i < 8; i++) {
			gotoxy(101, 6 + i); puts(userbox[i]);
		}
		gotoxy(103, 7); puts("1p");
		gotoxy(103, 8); printf("총 자산 : %d", playerinfo[0].asset);
		gotoxy(103, 9); printf("현금 : %d", playerinfo[0].cash);
		for (i = 0; i < 8; i++) {
			gotoxy(101, 16 + i); puts(userbox[i]);
		}
		gotoxy(103, 17); puts("2p");
		gotoxy(103, 18); printf("총 자산 : %d", playerinfo[1].asset);
		gotoxy(103, 19); printf("현금 : %d", playerinfo[1].cash);
		for (i = 0; i < 8; i++) {
			gotoxy(101, 26 + i); puts(userbox[i]);
		}
		gotoxy(103, 27); puts("3p");
		gotoxy(103, 28); printf("총 자산 : %d", playerinfo[2].asset);
		gotoxy(103, 29); printf("현금 : %d", playerinfo[2].cash);
	}
	else {
		for (i = 0; i < 8; i++) {
			gotoxy(101, 6 + i); puts(userbox[i]);
		}
		gotoxy(103, 7); puts("1p");
		gotoxy(103, 8); printf("총 자산 : %d", playerinfo[0].asset);
		gotoxy(103, 9); printf("현금 : %d", playerinfo[0].cash);
		for (i = 0; i < 8; i++) {
			gotoxy(101, 16 + i); puts(userbox[i]);
		}
		gotoxy(103, 17); puts("2p");
		gotoxy(103, 18); printf("총 자산 : %d", playerinfo[1].asset);
		gotoxy(103, 19); printf("현금 : %d", playerinfo[1].cash);
		for (i = 0; i < 8; i++) {
			gotoxy(101, 26 + i); puts(userbox[i]);
		}
		gotoxy(103, 27); puts("3p");
		gotoxy(103, 28); printf("총 자산 : %d", playerinfo[2].asset);
		gotoxy(103, 29); printf("현금 : %d", playerinfo[2].cash);
		for (i = 0; i < 8; i++) {
			gotoxy(101, 36 + i); puts(userbox[i]);
		}
		gotoxy(103, 37); puts("4p");
		gotoxy(103, 38); printf("총 자산 : %d", playerinfo[3].asset);
		gotoxy(103, 39); printf("현금 : %d", playerinfo[3].cash);
	}
	
}



void UpdateCash(int user, int cash) {
	int i;
	int vacationhome = 0, building = 0, hotel = 0;
	
	playerinfo[user - 1].cash = playerinfo[user - 1].cash + cash;
	
	for (i = 0; i < 40; i++) {
		if (landinfo[i].property == user) {
			vacationhome += (landinfo[i].vacationhome * landinfo[i].vhflag);
			building += (landinfo[i].building * landinfo[i].bdflag);
			hotel += (landinfo[i].hotel * landinfo[i].htflag);
		}
	}
	playerinfo[user - 1].landall = vacationhome + building + hotel;
	playerinfo[user - 1].asset = playerinfo[user - 1].cash + playerinfo[user - 1].landall;
	

	if (user == 1) {
		if (playerinfo[user - 1].asset < 100 && playerinfo[user - 1].asset >= 10) {
			gotoxy(113, 8); printf("%d  ", playerinfo[user - 1].asset);
		}
		if (playerinfo[user - 1].asset < 10) {
			gotoxy(113, 8); printf("%d   ", playerinfo[user - 1].asset);
		}
		gotoxy(113, 8); printf("%d", playerinfo[user - 1].asset);
		gotoxy(110, 9); printf("%d ", playerinfo[user - 1].cash);
		
		
	}
	else if (user == 2) {
		if (playerinfo[user - 1].asset < 100 && playerinfo[user - 1].asset >= 10) {
			gotoxy(113, 18); printf("%d  ", playerinfo[user - 1].asset);
		}
		if (playerinfo[user - 1].asset < 10) {
			gotoxy(113, 18); printf("%d   ", playerinfo[user - 1].asset);
		}
		gotoxy(113, 18); printf("%d", playerinfo[user - 1].asset);
		gotoxy(110, 19); printf("%d ", playerinfo[user - 1].cash);
		
		
	}
	else if (user == 3) {
		if (playerinfo[user - 1].asset < 100 && playerinfo[user - 1].asset >= 10) {
			gotoxy(113, 28); printf("%d  ", playerinfo[user - 1].asset);
		}
		if (playerinfo[user - 1].asset < 10) {
			gotoxy(113, 28); printf("%d   ", playerinfo[user - 1].asset);
		}
		gotoxy(113, 28); printf("%d", playerinfo[user - 1].asset);
		gotoxy(110, 29); printf("%d ", playerinfo[user - 1].cash);
		
		
	}
	else {
		if (playerinfo[user - 1].asset < 100 && playerinfo[user - 1].asset >= 10) {
			gotoxy(113, 38); printf("%d  ", playerinfo[user - 1].asset);
		}
		if (playerinfo[user - 1].asset < 10) {
			gotoxy(113, 38); printf("%d   ", playerinfo[user - 1].asset);
		}
		gotoxy(113, 38); printf("%d", playerinfo[user - 1].asset);
		gotoxy(110, 39); printf("%d ", playerinfo[user - 1].cash);
		
		
	}
}

void PrintLand(int player, int position) { 
	if (position > 0 && position < 10) {
		if (player == 1) {
			setColor(RED);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 4, playerxy[player - 1][position].y + 1); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 4, playerxy[player - 1][position].y); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 4, playerxy[player - 1][position].y - 1); puts("ⓗ");
			}
		}
		if (player == 2) {
			setColor(BLUE);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 6, playerxy[player - 1][position].y + 1); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 6, playerxy[player - 1][position].y); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 6, playerxy[player - 1][position].y - 1); puts("ⓗ");
			}
		}
		if (player == 3) {
			setColor(YELLOW);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 4, playerxy[player - 1][position].y); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 4, playerxy[player - 1][position].y - 1); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 4, playerxy[player - 1][position].y - 2); puts("ⓗ");
			}
		}
		if (player == 4) {
			setColor(GREEN);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 6, playerxy[player - 1][position].y); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 6, playerxy[player - 1][position].y - 1); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 6, playerxy[player - 1][position].y - 2); puts("ⓗ");
			}
		}
	}
	if (position > 10 && position < 20) {
		if (player == 1) {
			setColor(RED);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y - 3); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y - 3); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 4, playerxy[player - 1][position].y - 3); puts("ⓗ");
			}
		}
		if (player == 2) {
			setColor(BLUE);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 2, playerxy[player - 1][position].y - 3); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y - 3); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y - 3); puts("ⓗ");
			}
		}
		if (player == 3) {
			setColor(YELLOW);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y - 4); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y - 4); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 4, playerxy[player - 1][position].y - 4); puts("ⓗ");
			}
		}
		if (player == 4) {
			setColor(GREEN);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 2, playerxy[player - 1][position].y - 4); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y - 4); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y - 4); puts("ⓗ");
			}
		}
	}
	if (position > 20 && position < 30) {
		if (player == 1) {
			setColor(RED);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 8, playerxy[player - 1][position].y + 1); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 8, playerxy[player - 1][position].y); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 8, playerxy[player - 1][position].y - 1); puts("ⓗ");
			}
		}
		if (player == 2) {
			setColor(BLUE);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 6, playerxy[player - 1][position].y + 1); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 6, playerxy[player - 1][position].y); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 6, playerxy[player - 1][position].y - 1); puts("ⓗ");
			}
		}
		if (player == 3) {
			setColor(YELLOW);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 8, playerxy[player - 1][position].y); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 8, playerxy[player - 1][position].y - 1); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 8, playerxy[player - 1][position].y - 2); puts("ⓗ");
			}
		}
		if (player == 4) {
			setColor(GREEN);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 6, playerxy[player - 1][position].y); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 6, playerxy[player - 1][position].y - 1); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 6, playerxy[player - 1][position].y - 2); puts("ⓗ");
			}
		}
	}
	if (position > 30 && position < 40) {
		if (player == 1) {
			setColor(RED);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x , playerxy[player - 1][position].y + 3); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2 , playerxy[player - 1][position].y + 3); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 4 , playerxy[player - 1][position].y + 3); puts("ⓗ");
			}
		}
		if (player == 2) {
			setColor(BLUE);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 2, playerxy[player - 1][position].y + 3); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y + 3); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y + 3); puts("ⓗ");
			}
		}
		if (player == 3) {
			setColor(YELLOW);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y + 2); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y + 2); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 4, playerxy[player - 1][position].y + 2); puts("ⓗ");
			}
		}
		if (player == 4) {
			setColor(GREEN);
			if (landinfo[position].vhflag == 1) {
				gotoxy(playerxy[player - 1][position].x - 2, playerxy[player - 1][position].y + 2); puts("ⓥ");
			}
			if (landinfo[position].bdflag == 1) {
				gotoxy(playerxy[player - 1][position].x, playerxy[player - 1][position].y + 2); puts("ⓑ");
			}
			if (landinfo[position].htflag == 1) {
				gotoxy(playerxy[player - 1][position].x + 2, playerxy[player - 1][position].y + 2); puts("ⓗ");
			}
		}
	}


	setColor(WHITE);
}

void DeleteAllLand(int player) { // 플레이어의 땅을 지운다 (짜보니 너무 길다 잘못했다 살려주라)
	int i;
	for (i = 0; i < 40; i++) {
		if (i > 0 && i < 10) {
			if (player == 1) {
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 4, playerxy[player - 1][i].y + 1); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 4, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 4, playerxy[player - 1][i].y - 1); puts("  ");
				}
			}
			if (player == 2) {
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 6, playerxy[player - 1][i].y + 1); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 6, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 6, playerxy[player - 1][i].y - 1); puts("  ");
				}
			}
			if (player == 3) {
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 4, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 4, playerxy[player - 1][i].y - 1); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 4, playerxy[player - 1][i].y - 2); puts("  ");
				}
			}
			if (player == 4) {
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 6, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 6, playerxy[player - 1][i].y - 1); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 6, playerxy[player - 1][i].y - 2); puts("  ");
				}
			}
		}
		if (i > 10 && i < 20) {
			if (player == 1) {
				setColor(RED);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y - 3); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y - 3); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 4, playerxy[player - 1][i].y - 3); puts("  ");
				}
			}
			if (player == 2) {
				setColor(BLUE);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 2, playerxy[player - 1][i].y - 3); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y - 3); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y - 3); puts("  ");
				}
			}
			if (player == 3) {
				setColor(YELLOW);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y - 4); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y - 4); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 4, playerxy[player - 1][i].y - 4); puts("  ");
				}
			}
			if (player == 4) {
				setColor(GREEN);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 2, playerxy[player - 1][i].y - 4); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y - 4); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y - 4); puts("  ");
				}
			}
		}
		if (i > 20 && i < 30) {
			if (player == 1) {
				setColor(RED);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 8, playerxy[player - 1][i].y + 1); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 8, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 8, playerxy[player - 1][i].y - 1); puts("  ");
				}
			}
			if (player == 2) {
				setColor(BLUE);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 6, playerxy[player - 1][i].y + 1); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 6, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 6, playerxy[player - 1][i].y - 1); puts("  ");
				}
			}
			if (player == 3) {
				setColor(YELLOW);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 8, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 8, playerxy[player - 1][i].y - 1); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 8, playerxy[player - 1][i].y - 2); puts("  ");
				}
			}
			if (player == 4) {
				setColor(GREEN);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 6, playerxy[player - 1][i].y); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 6, playerxy[player - 1][i].y - 1); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 6, playerxy[player - 1][i].y - 2); puts("  ");
				}
			}
		}
		if (i > 30 && i < 40) {
			if (player == 1) {
				setColor(RED);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y + 3); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y + 3); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 4, playerxy[player - 1][i].y + 3); puts("  ");
				}
			}
			if (player == 2) {
				setColor(BLUE);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 2, playerxy[player - 1][i].y + 3); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y + 3); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y + 3); puts("  ");
				}
			}
			if (player == 3) {
				setColor(YELLOW);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y + 2); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y + 2); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 4, playerxy[player - 1][i].y + 2); puts("  ");
				}
			}
			if (player == 4) {
				setColor(GREEN);
				if (landinfo[i].vhflag == 0) {
					gotoxy(playerxy[player - 1][i].x - 2, playerxy[player - 1][i].y + 2); puts("  ");
				}
				if (landinfo[i].bdflag == 0) {
					gotoxy(playerxy[player - 1][i].x, playerxy[player - 1][i].y + 2); puts("  ");
				}
				if (landinfo[i].htflag == 0) {
					gotoxy(playerxy[player - 1][i].x + 2, playerxy[player - 1][i].y + 2); puts("  ");
				}
			}
		}


		setColor(WHITE);
	}
}