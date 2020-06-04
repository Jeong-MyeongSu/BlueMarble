#include "BMherder.h"

point playerxy[4][40];
land landinfo[40];
info playerinfo[4];
buy buyselect[28];

extern pnum;
extern dice1, dice2;
extern *p[];
extern expocount;

int diecount = 0;

void playGame() {
	int ch;
	
	gotoxy(1, 51); puts("게임 인원을 선택 하세요 ◁   ▷");
	gotoxy(28, 51); printf("%d", pnum);
	
	int flag = 1;
	while(flag) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (pnum > 2) {
					pnum--;
				}
				gotoxy(28, 51); printf("%d", pnum);
				break;
			case RIGHT:
				if (pnum < 4) {
					pnum++;
				}
				gotoxy(28, 51); printf("%d", pnum);
				break;
			}
		}
		else {
			switch (ch) {
			case ' ':
				flag = 0;
				break;
			}
		}
	}
	if (pnum == 2) {
		UpdateCash(1, 400);
		UpdateCash(2, 400);
	}
	else if (pnum == 3) {
		UpdateCash(1, 350);
		UpdateCash(2, 350);
		UpdateCash(3, 350);
	}
	else {
		UpdateCash(1, 300);
		UpdateCash(2, 300);
		UpdateCash(3, 300);
		UpdateCash(4, 300);
	}
	printPlayer();
	printUserBox();
	
	for (int i = 0; i <= Maxturn; i++) {
		gotoxy(52, 13);  printf("%d ", Maxturn - i);
		if (pnum == 2) { 
			if (playerinfo[0].die == 0) {
				Player(1, playerinfo[0].cash);
			}
			if (playerinfo[1].die == 0) {
				Player(2, playerinfo[1].cash);
			}
			if (diecount == 1) {
				for (int j = 0; j < 2; j++) {
					if (playerinfo[j].die == 0) {
						gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", j+1);
						gotoxy(40, 14);  printf("                           ");
						gotoxy(40, 51);  printf("                                      ");
						exit(0);
					}
				}
			}
		}
		else if (pnum == 3) {
			if (playerinfo[0].die == 0) {
				Player(1, playerinfo[0].cash);
			}
			if (playerinfo[1].die == 0) {
				Player(2, playerinfo[1].cash);
			}
			if (playerinfo[2].die == 0) {
				Player(3, playerinfo[2].cash);
			}
			if (diecount == 2) {
				for (int j = 0; j < 3; j++) {
					if (playerinfo[j].die == 0) {
						gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", j + 1);
						gotoxy(40, 14);  printf("                           ");
						gotoxy(40, 51);  printf("                                      ");
						exit(0);
					}
				}
			}
			
		}
		else {
			if (playerinfo[0].die == 0) {
				Player(1, playerinfo[0].cash);
			}
			if (playerinfo[1].die == 0) {
				Player(2, playerinfo[1].cash);
			}
			if (playerinfo[2].die == 0) {
				Player(3, playerinfo[2].cash);
			}
			if (playerinfo[3].die == 0) {
				Player(4, playerinfo[3].cash);
			}
			if (diecount == 3) {
				for (int j = 0; j < 4; j++) {
					if (playerinfo[j].die == 0) {
						gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", j + 1);
						gotoxy(40, 14);  printf("                           ");
						gotoxy(40, 51);  printf("                                      ");
						exit(0);
					}
				}
			}
		}
	}
	//가장 높은 자산 승리
	if (playerinfo[0].asset > playerinfo[1].asset && playerinfo[0].asset > playerinfo[2].asset && playerinfo[0].asset > playerinfo[3].asset) {
		gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", 0 + 1);
		gotoxy(40, 14);  printf("                           ");
		gotoxy(40, 51);  printf("                                      ");
		exit(0);
	}
	if (playerinfo[1].asset > playerinfo[0].asset && playerinfo[1].asset > playerinfo[2].asset && playerinfo[1].asset > playerinfo[3].asset) {
		gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", 1 + 1);
		gotoxy(40, 14);  printf("                           ");
		gotoxy(40, 51);  printf("                                      ");
		exit(0);
	}
	if (playerinfo[2].asset > playerinfo[0].asset && playerinfo[2].asset > playerinfo[1].asset && playerinfo[2].asset > playerinfo[3].asset) {
		gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", 2 + 1);
		gotoxy(40, 14);  printf("                           ");
		gotoxy(40, 51);  printf("                                      ");
		exit(0);
	}
	if (playerinfo[3].asset > playerinfo[0].asset && playerinfo[3].asset > playerinfo[1].asset && playerinfo[3].asset > playerinfo[1].asset) {
		gotoxy(40, 13);  printf("축하합니다 %dp 승리입니다. ", 3 + 1);
		gotoxy(40, 14);  printf("                           ");
		gotoxy(40, 51);  printf("                                      ");
		exit(0);
	}


}

void Player(int player , int cash) { //플레이어가 주사위를 던지고 이동하는 함수, 무인도인지 기차여행중인지 확인하여 움직인다.
	gotoxy(42, 14); printf("%dp 턴 입니다", player);
	if (playerinfo[player-1].tflag == 0) { //기차 여행인지 확인 기차여행이면 1 아니면 0
		ThrowDice();
		if (playerinfo[player - 1].unisland == 0 || dice1 == dice2) { // 무인도인지 확인 무인도가 아니면 0, 더블이면 무인도 빠져나옴
			MovePlayer(player);
			playerinfo[player - 1].unisland = 0;
			GetEvent(player, playerinfo[player-1].position);
		}
		else if (playerinfo[player - 1].unisland == 1) {
			gotoxy(1, 51); printf("무인도 끝.                            ");
			delay(500);
			playerinfo[player - 1].unisland = 0;
		}
		else {
			(playerinfo[player - 1].unisland)--;
			gotoxy(1, 51); printf("%d 턴 남았습니다.                     ", playerinfo[player - 1].unisland);
			delay(500);
		}
	}
	else if (playerinfo[player - 1].tflag == 1 && cash >= 20) {
		GetTrain(player);
		GetEvent(player, playerinfo[player - 1].position);
	}
	else {
		gotoxy(1, 51); printf("기차여행 할 현금이 부족합니다         ");
		playerinfo[player - 1].tflag = 0;
		delay(500);
		ThrowDice();
		MovePlayer(player);
		GetEvent(player, playerinfo[player - 1].position);
	}
}

void ThrowDice() { //주사위 던지는 함수
	int ch;
	int flag = 1;
	

	gotoxy(1, 51); puts("스페이스바를 눌러 주사위를 굴리세요.  ");
	
	while (flag) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
		}
		else {
			if (IsKeyDown(VK_SPACE)) {
				//dice1 = random(dice)+1;
				//dice2 = random(dice)+1;
				dice1 = random(dice)+1;
				dice2 = random(dice)+1;
					
				flag = 0;
			}
		}
	}
	
	gotoxy(1, 51); printf("%d, %d                                  ", dice1, dice2);
	delay(2000);
}
void MovePlayer(int player) { //플레이어가 움직이는 함수 한바퀴 돌면 월급 받는것도 같이함

	gotoxy(playerxy[player-1][playerinfo[player - 1].position].x, playerxy[player-1][playerinfo[player - 1].position].y); puts("  ");
	playerinfo[player - 1].position = playerinfo[player - 1].position + (dice1 + dice2);
	if (playerinfo[player - 1].position >= 40) {
		playerinfo[player - 1].position = playerinfo[player - 1].position - 40;
		UpdateCash(player, 30);
	}
	gotoxy(playerxy[player-1][playerinfo[player - 1].position].x, playerxy[player-1][playerinfo[player - 1].position].y);
	if (player == 1) {
		setColor(RED); puts("①");
	}
	else if (player == 2) {
		setColor(BLUE); puts("②");
	}
	else if (player == 3) {
		setColor(YELLOW); puts("③");
	}
	else {
		setColor(GREEN); puts("④");
	}
	setColor(WHITE);
	delay(500);
}

void GetEvent(int player, int position) { //이벤트 발생 함수 무인도, 기차여행, 엑스포, 공원, 산, 도시 밟으면 이벤트 발생하게 만듬
	int revent;
	int pn;
	int i;
	int mountain = 0;
	int landcount = 0;
	if (position == 30) {
		playerinfo[player - 1].tflag = 1;
		gotoxy(101, 45); printf("기차여행             ");
		gotoxy(101, 46); printf("다음 턴에 20 을 지불 ");
		gotoxy(101, 47); printf("하고 원하는 곳으로   ");
		gotoxy(101, 48); printf("이동한다             ");
		gotoxy(101, 49); printf("                     ");
	}
	if (position == 10 && playerinfo[player - 1].unisland == 0) {
		playerinfo[player - 1].unisland = 3;
		gotoxy(101, 45); printf("무인도               ");
		gotoxy(101, 46); printf("더블이 나오지 않으면 ");
		gotoxy(101, 47); printf("3턴동안 이동할수 없다");
		gotoxy(101, 48); printf("                     ");
		gotoxy(101, 49); printf("                     ");
	}
	if (position == 1 || position == 3 || position == 6 || position == 8 || position == 9 || position == 11 || position == 12 || position == 14 || position == 16 || position == 17 || position == 19 || position == 21 || position == 23 || position == 24 || position == 26 || position == 28 || position == 29 || position == 31 || position == 32 || position == 34 || position == 37 || position == 39) {
		if (landinfo[position].property == 0) {
			gotoxy(101, 45); printf("소유권 없는 빈 땅    ");
			gotoxy(101, 46); printf("별장 : %d            ", landinfo[position].vacationhome);
			gotoxy(101, 47); printf("빌딩 : %d            ", landinfo[position].building);
			gotoxy(101, 48); printf("호텔 : %d            ", landinfo[position].hotel);
			gotoxy(101, 49); printf("총 금액 : %d         ", (landinfo[position].vacationhome) + (landinfo[position].building) + (landinfo[position].hotel));
		}
		else if(landinfo[position].property == player){
			gotoxy(101, 45); printf("자신의 땅 입니다.    ");
			gotoxy(101, 46); printf("별장 : %d            ", landinfo[position].vacationhome); 
			if (landinfo[position].vhflag == 1) { gotoxy(112, 46); printf("(o)");}
			else { gotoxy(112, 46); printf("(x)"); }
			gotoxy(101, 47); printf("빌딩 : %d            ", landinfo[position].building);     
			if (landinfo[position].bdflag == 1) { gotoxy(112, 47); printf("(o)"); }
			else { gotoxy(112, 47); printf("(x)"); }
			gotoxy(101, 48); printf("호텔 : %d            ", landinfo[position].hotel);		 
			if (landinfo[position].htflag == 1) { gotoxy(112, 48); printf("(o)"); }
			else { gotoxy(112, 48); printf("(x)"); }
			gotoxy(101, 49); printf("총 금액 : %d(%d)    ", (landinfo[position].vacationhome) + (landinfo[position].building) + (landinfo[position].hotel), (landinfo[position].vacationhome * landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag));
		}
		else {
			gotoxy(101, 45); printf("%dp 소유의 땅 입니다.",landinfo[position].property);
			gotoxy(101, 46); printf("별장 : %d            ", landinfo[position].vacationhome * landinfo[position].vhflag);
			gotoxy(101, 47); printf("빌딩 : %d            ", landinfo[position].building * landinfo[position].bdflag);
			gotoxy(101, 48); printf("호텔 : %d            ", landinfo[position].hotel * landinfo[position].htflag);
			gotoxy(101, 49); printf("총 금액 : %d         ", (landinfo[position].vacationhome * landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag));
		}
		TreadLand(player, playerinfo[player-1].position, playerinfo[player-1].cash);
	}
	if (position == 7 || position == 33) {
		if (landinfo[position].property == 0) {
			gotoxy(101, 45); printf("소유권 없는 빈 공원  ");
			gotoxy(101, 46); printf("밟으면 밟을 수록     ");
			gotoxy(101, 47); printf("가격이 오른다.       ");
			gotoxy(101, 48); printf("                     ");
			gotoxy(101, 49); printf("                     ");
			landinfo[position].pd = 0;
		}
		else if (landinfo[position].property == player) {
			gotoxy(101, 45); printf("자신 의 공원 입니다  ");
			gotoxy(101, 46); printf("가격 : %d            ", landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd);
			gotoxy(101, 47); printf("밟으면 밟을 수록     ");
			gotoxy(101, 48); printf("가격이 오른다.       ");
			gotoxy(101, 49); printf("x%d                  ",landinfo[position].pd);
		}
		else {
			gotoxy(101, 45); printf("%dp 의 공원 입니다   ", landinfo[position].property);
			gotoxy(101, 46); printf("가격 : %d            ", landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd);
			gotoxy(101, 47); printf("밟으면 밟을 수록     ");
			gotoxy(101, 48); printf("가격이 오른다.       ");
			gotoxy(101, 49); printf("x%d                  ", landinfo[position].pd+1);
		}
		if (landinfo[position].property > 0) {
			landinfo[position].pd += 1;
		}
		TreadPark(player, position, playerinfo[player - 1].cash);
	}
	if (position == 5 || position == 15 || position == 25 || position == 35) {
		if (landinfo[position].property == 0) {
			gotoxy(101, 45); printf("소유권 없는 빈 산    ");
			gotoxy(101, 46); printf("산을 많이 보유 하고  ");
			gotoxy(101, 47); printf("있을 수록 가격이     ");
			gotoxy(101, 48); printf("오른다               ");
			gotoxy(101, 49); printf("금액 : 15            ");
		}
		else if (landinfo[position].property == player) {
			gotoxy(101, 45); printf("자신 의 산   입니다  ");
			gotoxy(101, 46); printf("산을 많이 보유 하고  ");
			gotoxy(101, 47); printf("있을 수록 가격이     ");
			gotoxy(101, 48); printf("오른다               ");
			gotoxy(101, 49); printf("                     ");
		}
		else {
			gotoxy(101, 45); printf("%dp 의 산   입니다   ", landinfo[position].property);
			for (i = 0; i < 40; i++) {
				if (landinfo[i].property == landinfo[position].property) {
					mountain += landinfo[i].mountain;
				}
			}
			gotoxy(101, 46); printf("가격 : %d            ", mountain);
			gotoxy(101, 47); printf("산을 많이 보유 하고  ");
			gotoxy(101, 48); printf("있을 수록 가격이     ");
			gotoxy(101, 49); printf("오른다               ");
		}
		TreadMountain(player, position, playerinfo[player - 1].cash);
	}
	if (position == 20) {
		gotoxy(101, 45); printf("엑스포               ");
		gotoxy(101, 46); printf("원하는 땅에 엑스포를 ");
		gotoxy(101, 47); printf("개최하여 땅값을      ");
		gotoxy(101, 48); printf("올린다.              ");
		gotoxy(101, 49); printf("                     ");
		if (playerinfo[player - 1].cash >= 10 ) {
			for (i = 0; i < 40; i++) {
				if (i != 5 && i != 15 && i != 25 && i != 35 && i != 7 && i != 33) {
					if (landinfo[i].property == player) {
						landcount++;
					}
				}
		
			}
			if (landcount == 0) {
				gotoxy(1, 51); puts("엑스포 개최할 땅이없습니다.           ");
			}
			else {
				UpdateCash(player, -10);
				Expo(player, position);
				expocount++;
				for (i = 0; i < 40; i++) {
					if (landinfo[i].expo != 1) {
						gotoxy(60, 6); printf("엑스포 지역 : %s", p[i]);
						gotoxy(60, 7); printf("x%d", expocount);
					}
				}
			}
		}
		else {
			gotoxy(1, 51); puts("엑스포 개최할 돈이 부족합니다.        ");
			delay(1000);
		}
	}
	if (position == 2 || position == 4 || position == 13 || position == 18 || position == 22 || position == 27 || position == 36 || position == 38) {
		gotoxy(101, 45); printf("랜  덤               ");
		gotoxy(101, 46); printf("랜덤하게 이동한다    ");
		gotoxy(101, 47); printf("1~6칸 앞뒤, 무인도,  ");
		gotoxy(101, 48); printf("엑스포, 기차중 랜덤  ");
		gotoxy(101, 49); printf("                     ");
		revent = random(10) + 1; // 1~9 랜덤 1~6 이동 7무인도 8엑스포 9기차 10 출발지
		pn = random(2) + 1;//1나오면 + 2나오면 -
		GetRandom(revent, pn, player);
		GetEvent(player, playerinfo[player - 1].position);
	}
}

void GetTrain(int player) { //기차여행 이동 함수
		UpdateCash(player, -20);
		int ch, flag, num;
		gotoxy(1, 51); puts("이동할 위치를 선택하세요 ◁         ▷");
		gotoxy(29, 51); printf("%s", p[0]);

		flag = 1;
		num = 0;
		while (flag) {
			ch = getch();
			if (ch == 0xE0 || ch == 0) {
				ch = getch();
				switch (ch) {
				case LEFT:
					if (num > 31) {
						num--;
					}
					else if (num == 31) {
						num = num - 2;
					}
					else if (num <= 29 && num >= 1) {
						num--;
					}
					else {
						num = 39;
					}
					gotoxy(29, 51); printf("%s", p[num]);
					break;
				case RIGHT:
					if (num < 29) {
						num++;
					}
					else if (num == 29) {
						num = num + 2;
					}
					else if (num >= 31 && num < 39) {
						num++;
					}
					else {
						num = 0;
					}
					gotoxy(29, 51); printf("%s", p[num]);
					break;
				}
			}
			else {
				if (IsKeyDown(VK_SPACE)) {
					flag = 0;
				}
			}
		}
		gotoxy(playerxy[player - 1][playerinfo[player-1].position].x, playerxy[player - 1][playerinfo[player - 1].position].y); puts("  ");
		playerinfo[player - 1].position = num;
		if (playerinfo[player - 1].position >= 0 && playerinfo[player - 1].position <= 29) {
			UpdateCash(player, 30);
		}
		playerinfo[player-1].tflag = 0;
		gotoxy(playerxy[player - 1][playerinfo[player - 1].position].x, playerxy[player - 1][playerinfo[player - 1].position].y);
		if (player == 1) {
			setColor(RED); puts("①");
		}
		else if (player == 2) {
			setColor(BLUE); puts("②");
		}
		else if (player == 3) {
			setColor(YELLOW); puts("③");
		}
		else {
			setColor(GREEN); puts("④");
		}

		setColor(WHITE);
		delay(500);
}

void GetRandom(int revent, int pn, int player) { //랜덤 이벤트 밟았을때 생긴 변수를 받아 몇칸 이동과 특정지역 이동을 나눔(해보니 조잡해짐;)
	if (revent >= 1 && revent <=6 && pn == 1) {
		gotoxy(15, 40); printf("%d 칸 앞으로                          ",revent);
		delay(500);
		RandomMovePlayer(player, revent, 1);
		delay(500);
	}
	else if (revent >= 1 && revent <= 6 && pn == 2) {
		gotoxy(15, 40); printf("%d 칸 뒤로                            ", revent);
		delay(500);
		RandomMovePlayer(player, revent, -1);
		delay(500);
	}
	if (revent >= 7) {
		delay(500);
		RandomMovePlayer(player, revent, 1);
		delay(500);
	}
	
	
}

void RandomMovePlayer(int player,int revent, int pn) {  //랜덤 이벤트 밟았을때 생긴 변수를 받아 이동 수행 함수
	
	gotoxy(playerxy[player-1][playerinfo[player - 1].position].x, playerxy[player-1][playerinfo[player - 1].position].y); puts("  ");
	if (revent >= 1 && revent <= 6) {
		playerinfo[player - 1].position = playerinfo[player - 1].position + revent * pn;
		if (playerinfo[player - 1].position >= 40) {
			playerinfo[player - 1].position = playerinfo[player - 1].position - 40;

			UpdateCash(player, 30);
		}
		if (playerinfo[player - 1].position == 0) {
			UpdateCash(player, 30);
		}
		if (playerinfo[player - 1].position < 0) {
			playerinfo[player - 1].position = 40 + playerinfo[player - 1].position;
		}
	}
	else if (revent == 7) {
		gotoxy(15, 40); printf("무인도로 가시오.                      ");
		if (playerinfo[player - 1].position == 13 || playerinfo[player - 1].position == 18 || playerinfo[player - 1].position == 22 || playerinfo[player - 1].position == 27 || playerinfo[player - 1].position == 36 || playerinfo[player - 1].position == 38) {
			UpdateCash(player, 30);
		}
		playerinfo[player - 1].position = 10;
	}
	else if (revent == 8) {
		gotoxy(15, 40); printf("엑스포로 가시오.                      ");
		if (playerinfo[player - 1].position == 22 || playerinfo[player - 1].position == 27 || playerinfo[player - 1].position == 36 || playerinfo[player - 1].position == 38) {
			UpdateCash(player, 30);
		}
		playerinfo[player - 1].position = 20;
	}
	else if (revent == 9) {
		gotoxy(15, 40); printf("기차여행으로 가시오                   ");
		if (playerinfo[player - 1].position == 36 || playerinfo[player - 1].position == 38) {
			UpdateCash(player, 30);
		}
		playerinfo[player - 1].position = 30;
	}
	else {
		gotoxy(15, 40); printf("출발지로 가시오.(+30)                 ");
		playerinfo[player - 1].position = 0;
		UpdateCash(player, 30);
	}
	gotoxy(playerxy[player-1][playerinfo[player - 1].position].x, playerxy[player-1][playerinfo[player - 1].position].y);
	if (player == 1) {
		setColor(RED); puts("①");
	}
	else if (player == 2) {
		setColor(BLUE); puts("②");
	}
	else if (player == 3) {
		setColor(YELLOW); puts("③");
	}
	else {
		setColor(GREEN); puts("④");
	}
	setColor(WHITE);
	delay(500);
}

void TreadLand(int player, int position, int cash) {   //도시를 밟았을때 이벤트 함수
	int ch, flag, num;
	num = 1;
	flag = 1;
	
	if (landinfo[position].property == 0) {
		gotoxy(1, 51); printf("땅을 구입 하시겠습니까?  ◁        ▷ ");
		gotoxy(30, 51); printf("YES");
		while (flag) {
			ch = getch();
			if (ch == 0xE0 || ch == 0) {
				ch = getch();
				switch (ch) {
				case LEFT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("YES");
					}
					else {
						gotoxy(30, 51); printf("N O");
					}
					break;
				case RIGHT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("YES");
					}
					else {
						gotoxy(30, 51); printf("N O");
					}
					break;
				}
			}
			else {
				if (IsKeyDown(VK_SPACE)) {
					flag = 0;
				}
			}
		}
		if (num == 1 && landinfo[position].vacationhome <= cash) {
			buyland(player, position, playerinfo[player-1].cash);
		}
		else if (num == 1 && landinfo[position].vacationhome > cash) {
			gotoxy(1, 51); printf("건물을 구입할 현금이 부족합니다.      ");
			delay(1000);
		}
	}
	else if (landinfo[position].property == player) {
		gotoxy(1, 51); printf("건물을 더 구입하시겠습니까?◁      ▷ ");
		gotoxy(31, 51); printf("YES");
		while (flag) {
			ch = getch();
			if (ch == 0xE0 || ch == 0) {
				ch = getch();
				switch (ch) {
				case LEFT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(31, 51); printf("YES");
					}
					else {
						gotoxy(31, 51); printf("N O");
					}
					break;
				case RIGHT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(31, 51); printf("YES");
					}
					else {
						gotoxy(31, 51); printf("N O");
					}
					break;
				}
			}
			else {
				if (IsKeyDown(VK_SPACE)) {
					flag = 0;
				}
			}
		}
		if (num == 1) {
			if(landinfo[position].vhflag == 0 || landinfo[position].bdflag == 0 || landinfo[position].htflag == 0){
				if (landinfo[position].vhflag == 0 && (landinfo[position].vacationhome * (-(landinfo[position].vhflag - 1))) <= cash || landinfo[position].bdflag == 0 && (landinfo[position].building * (-(landinfo[position].bdflag - 1))) <= cash || landinfo[position].htflag == 0 && (landinfo[position].hotel * (-(landinfo[position].htflag - 1))) <= cash) {
					rebuyland(player, position, playerinfo[player-1].cash);
				}
				else {
					gotoxy(1, 51); printf("살수 있는 건물이 없습니다.            ");
					delay(1000);
				}
			}
			else {
				gotoxy(1, 51); printf("모든 건물을 구입했습니다.             ");
				delay(1000);
			}
		}
	}
	else {
		gotoxy(1, 51); printf("다른 플레이어의 땅입니다.             ");
		gotoxy(1, 52); printf("-%d", ((landinfo[position].vacationhome * landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag))*landinfo[position].expo);
		delay(2000);
		gotoxy(1, 52); printf("       ");
		if (cash >= ((landinfo[position].vacationhome * landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag))*landinfo[position].expo) {
			UpdateCash(player, -(((landinfo[position].vacationhome * landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag))*landinfo[position].expo));
			UpdateCash(landinfo[position].property, ((landinfo[position].vacationhome* landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag))*landinfo[position].expo);
		}
		else {
			paylandevent(player, position, playerinfo[player-1].cash, ((landinfo[position].vacationhome* landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag))*landinfo[position].expo);
			
		}
	}
}

void buyland(int player, int position, int cash) { //처음 땅을 구매할때 사용하는 함수
	landinfo[position].vhflag = 0;
	landinfo[position].bdflag = 0;
	landinfo[position].htflag = 0;
	int ch, num, flag, buy1, buy2, buy3;
	num = 1;
	flag = 1;
	buy1 = -1;
	buy2 = -1;
	buy3 = -1;
	gotoxy(1, 51); printf("구입할 건물을 선택하세요 ◁ ▷        ");
	gotoxy(3, 53); printf("별장"); gotoxy(11, 53); printf("빌딩"); gotoxy(19, 53); printf("호텔"); gotoxy(27, 53); printf("확인"); gotoxy(3, 53);
	while (flag) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (num > 1) {
					num--;
					if (num == 1)
						gotoxy(3, 53);
					else if (num == 2)
						gotoxy(11, 53);
					else if (num == 3)
						gotoxy(19, 53);
					else
						gotoxy(27, 53);

				}
				break;
			case RIGHT:
				if (num < 4) {
					num++;
					if (num == 1)
						gotoxy(3, 53);
					else if (num == 2)
						gotoxy(11, 53);
					else if (num == 3)
						gotoxy(19, 53);
					else
						gotoxy(27, 53);

				}
				break;
			}
		}
		else {
			if (IsKeyDown(VK_SPACE) && num == 4) {
				flag = 0;
				setColor(WHITE);
				gotoxy(3, 53); printf("                                      ");
			}
			else if (IsKeyDown(VK_SPACE) && num == 3) {
				buy3 = buy3 * (-1);
				if (buy3 == 1) {
					setColor(GREEN);
					gotoxy(19, 53); printf("호텔");
				}
				else {
					setColor(WHITE);
					gotoxy(19, 53); printf("호텔");
				}
			}
			else if (IsKeyDown(VK_SPACE) && num == 2) {
				buy2 = buy2 * (-1);
				if (buy2 == 1) {
					setColor(GREEN);
					gotoxy(11, 53); printf("빌딩");
				}
				else {
					setColor(WHITE);
					gotoxy(11, 53); printf("빌딩");
				}
			}
			else if (IsKeyDown(VK_SPACE) && num == 1) {
				buy1 = buy1 * (-1);
				if (buy1 == 1) {
					setColor(GREEN);
					gotoxy(3, 53); printf("별장");
				}
				else {
					setColor(WHITE);
					gotoxy(3, 53); printf("별장");
				}
			}
		}
	}
	if (buy1 == 1 || buy2 == 1 || buy3 == 1) {
		landinfo[position].property = player;
	}
		
	if (buy1 == 1)
		landinfo[position].vhflag = buy1;
	if (buy2 == 1)
		landinfo[position].bdflag = buy2;
	if (buy3 == 1)
		landinfo[position].htflag = buy3;
	if (cash < ((landinfo[position].vacationhome * landinfo[position].vhflag) + (landinfo[position].building * landinfo[position].bdflag) + (landinfo[position].hotel * landinfo[position].htflag))) {
		gotoxy(1, 51); printf("건물을 구입할 현금이 부족합니다.      ");
		delay(1000);
	
		buyland(player, position, cash);
	}
	else {
		UpdateCash(player, (-(landinfo[position].vacationhome * landinfo[position].vhflag) - (landinfo[position].building * landinfo[position].bdflag) - (landinfo[position].hotel * landinfo[position].htflag)));
	}
	PrintLand(player, position);
}


void rebuyland(int player, int position, int cash) {  //자신의 땅의 건물을 더지을 때 사용하는 함수
	int ch, num, flag, buy1, buy2, buy3, buyflag1, buyflag2, buyflag3, buy;
	buy = 0;
	num = 1;
	flag = 1;
	buyflag1 = landinfo[position].vhflag;
	buyflag2 = landinfo[position].bdflag;
	buyflag3 = landinfo[position].htflag;
	buy1 = landinfo[position].vhflag;
	buy2 = landinfo[position].bdflag;
	buy3 = landinfo[position].htflag;
	gotoxy(1, 51); printf("구입할 건물을 선택하세요 ◁ ▷        ");
	if (buy1 == 0) {
		gotoxy(3, 53); printf("별장");
	}
	if (buy2 == 0) {
		gotoxy(11, 53); printf("빌딩");
	}
	if (buy3 == 0) {
		gotoxy(19, 53); printf("호텔");
	}
	gotoxy(27, 53); printf("확인"); gotoxy(3, 53);
	while (flag) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (num > 1) {
					num--;
					if (num == 1)
						gotoxy(3, 53);
					else if (num == 2)
						gotoxy(11, 53);
					else if (num == 3)
						gotoxy(19, 53);
					else
						gotoxy(27, 53);

				}
				break;
			case RIGHT:
				if (num < 4) {
					num++;
					if (num == 1)
						gotoxy(3, 53);
					else if (num == 2)
						gotoxy(11, 53);
					else if (num == 3)
						gotoxy(19, 53);
					else
						gotoxy(27, 53);

				}
				break;
			}
		}
		else {
			if (IsKeyDown(VK_SPACE) && num == 4) {
				flag = 0;
				setColor(WHITE);
				gotoxy(3, 53); printf("                                      ");
			}
			else if (IsKeyDown(VK_SPACE) && num == 3) {
				if (buy3 == 0) {
					buy3++;
					setColor(GREEN);
					gotoxy(19, 53); printf("호텔");
				}
			}
			else if (IsKeyDown(VK_SPACE) && num == 2) {
				if (buy2 == 0) {
					buy2++;
					setColor(GREEN);
					gotoxy(11, 53); printf("빌딩");
				}
			}
			else if (IsKeyDown(VK_SPACE) && num == 1) {
				if (buy1 == 0) {
					buy1++;
					setColor(GREEN);
					gotoxy(3, 53); printf("별장");
				}
			}
		}
	}
	landinfo[position].vhflag = buy1;
	landinfo[position].bdflag = buy2;
	landinfo[position].htflag = buy3;
	
	if (buyflag1 != landinfo[position].vhflag) {
		buy += (landinfo[position].vhflag * landinfo[position].vacationhome);
	}
	if (buyflag2 != landinfo[position].bdflag) {
		buy += (landinfo[position].bdflag * landinfo[position].building);
	}
	if (buyflag3 != landinfo[position].htflag) {
		buy += (landinfo[position].htflag * landinfo[position].hotel);
	}
	if (buy <= cash) {
		UpdateCash(player, (-buy));
		PrintLand(player, position);
	}
	else {
		delay(1000);
		rebuyland(player, position, cash);
	}
}

void paylandevent(int player, int position, int cash, int debt) { //land 에 걸렸는데 현금이 없을때 땅파는 함수
	int flag, num, ch;
	
	
	flag = 1; num = 1; 
	if (playerinfo[player - 1].cash + playerinfo[player - 1].landall < debt) {
		bankuptcy(player, position, cash, debt);
   }
	else {
		gotoxy(1, 51); printf("땅을 판매 하시겠습니까?  ◁        ▷ ");
		gotoxy(30, 51); printf("yes ");
		while (flag) {
			ch = getch();
			if (ch == 0xE0 || ch == 0) {
				ch = getch();
				switch (ch) {
				case LEFT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("yes ");
					}
					else {
						gotoxy(30, 51); printf("파산");
					}
					break;
				case RIGHT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("yes ");
					}
					else {
						gotoxy(30, 51); printf("파산");
					}
					break;
				}
			}
			else {
				if (IsKeyDown(VK_SPACE)) {
					flag = 0;
				}
			}
		}
		if (num == 1) {
			payland(player,debt);
			UpdateCash(player, -debt);
			UpdateCash(landinfo[position].property, debt);
			
		}
		else {
			bankuptcy(player, position, cash, debt);
		}
	}
	DeleteAllLand(player);
}

void bankuptcy(int player, int position, int cash, int debt) {
	int i;
	gotoxy(1, 51); printf("파산 하였습니다.                      ");
	delay(2000);
	playerinfo[player - 1].die = 1;
	gotoxy(playerxy[player - 1][playerinfo[player - 1].position].x, playerxy[player - 1][playerinfo[player - 1].position].y); puts("  ");
	playerinfo[player - 1].cash = 0;
	playerinfo[player - 1].asset = 0;
	for (i = 0; i < 40; i++) {
		if (landinfo[i].property == player) {
			landinfo[i].vhflag = 0;
			landinfo[i].bdflag = 0;
			landinfo[i].htflag = 0;
			landinfo[i].property = 0;
		}
	}
	DeleteAllLand(player);
	UpdateCash(player, 0);
	UpdateCash(landinfo[position].property, debt);
	diecount++;
}

void payland(int player, int debt) {
	int i, num, flag, ch, landnum = 0, buy = 1;
	num = 1; flag = 1;
	gotoxy(1, 51); puts("판매할 땅를 선택하세요 ◁ ▷          ");
	for (i = 0; i < 40; i++) {
		if (landinfo[i].property == player) {
			landnum += 1;
			gotoxy((landnum * 9) - 3, 53); printf("%s", p[i]);
			buyselect[landnum].land = p[i];
		}
	}
	gotoxy((landnum + 1) * 9 - 3, 53); printf("결 정");
	gotoxy(6, 53);
	while (flag) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (num > 1) {
					num--;
					gotoxy((num * 9) - 3, 53);
				}
				break;
			case RIGHT:
				if (num < landnum + 1) {
					num++;
					gotoxy((num * 9) - 3, 53);
				}
				break;
			}
		}
		else {
			if (IsKeyDown(VK_SPACE) && num == landnum + 1) {
				flag = 0;
			}
			else if (IsKeyDown(VK_SPACE) && num != landnum + 1 && buyselect[num].select == 0) {
				buyselect[num].select = 1;
				setColor(GREEN);
				gotoxy((num * 9) - 3, 53); printf("%s", buyselect[num].land);
			}
			else if (IsKeyDown(VK_SPACE) && num != landnum + 1 && buyselect[num].select == 1) {
				buyselect[num].select = 0;
				setColor(WHITE);
				gotoxy((num * 9) - 3, 53); printf("%s", buyselect[num].land);
			}
		}
	}
	setColor(WHITE); gotoxy(1, 53); printf("                                                                                                                 ");
	for (i = 0; i < 40; i++) {
		if (landinfo[i].property == player) {
			if (buyselect[buy].select == 1) {
				UpdateCash(player, (landinfo[i].vhflag * landinfo[i].vacationhome) + (landinfo[i].bdflag * landinfo[i].building) + (landinfo[i].htflag * landinfo[i].hotel));
				
				landinfo[i].property = 0;
				landinfo[i].vhflag = 0;
				landinfo[i].bdflag = 0;
				landinfo[i].htflag = 0;
				landinfo[i].expo = 1;
				UpdateCash(player, 0);
			}
			buy++;
		}
	}
	for (i = 0; i < 28; i++) {
		buyselect[i].select = 0;
	}
	
	if (playerinfo[player-1].cash < debt) {
		gotoxy(1, 51); puts("땅을 더 팔아야 합니다.                ");
		delay(1000);
		payland(player, debt);
	}
	for (i = 0; i < 40; i++) {
		if (landinfo[i].expo != 1) {
			gotoxy(60, 6); printf("엑스포 지역 : %s", p[i]);
			gotoxy(60, 7); printf("x%d", expocount);
			break;
		}
		else {
			gotoxy(60, 6); printf("엑스포 지역 : 없음  ");
			gotoxy(60, 7); printf("x%d", expocount);
		}
	}
}

void TreadPark(int player, int position, int cash) {
	int ch, flag, num;
	num = 1;
	flag = 1;

	if (landinfo[position].property == 0) {
		gotoxy(1, 51); printf("공원을 구입 하시겠습니까?◁        ▷ ");
		gotoxy(30, 51); printf("YES");
		while (flag) {
			ch = getch();
			if (ch == 0xE0 || ch == 0) {
				ch = getch();
				switch (ch) {
				case LEFT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("YES");
					}
					else {
						gotoxy(30, 51); printf("N O");
					}
					break;
				case RIGHT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("YES");
					}
					else {
						gotoxy(30, 51); printf("N O");
					}
					break;
				}
			}
			else {
				if (IsKeyDown(VK_SPACE)) {
					flag = 0;
				}
			}
		}
		if (num == 1 && landinfo[position].vacationhome <= cash) {
			landinfo[position].property = player;
			landinfo[position].vhflag = 1;
			landinfo[position].pd = 1;
			UpdateCash(player, (-landinfo[position].vacationhome));
			PrintLand(player, position);
		}
		else if (num == 1 && landinfo[position].vacationhome > cash) {
			gotoxy(1, 51); printf("공원을 구입할 현금이 부족합니다.      ");
			delay(1000);
		}
	}
	else if (landinfo[position].property == player) {
		gotoxy(1, 51); printf("이미 자신의 공원 입니다.              ");
	}
	else {
		gotoxy(1, 51); printf("다른 플레이어의 공원입니다.           ");
		gotoxy(1, 52); printf("-%d", (landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd ));
		delay(2000);
		gotoxy(1, 52); printf("      ");
		if (cash >= (landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd )) {
			UpdateCash(player, (-(landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd)));
			UpdateCash(landinfo[position].property, (landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd));
		}
		else {
			paylandevent(player, position, playerinfo[player - 1].cash, (landinfo[position].vacationhome * landinfo[position].vhflag * landinfo[position].pd));
		}
	}
}

void TreadMountain(int player, int position, int cash) {
	int ch, flag, num, i, mountain = 0;
	num = 1;
	flag = 1;

	if (landinfo[position].property == 0) {
		gotoxy(1, 51); printf("산을 구입 하시겠습니까?  ◁        ▷ ");
		gotoxy(30, 51); printf("YES");
		while (flag) {
			ch = getch();
			if (ch == 0xE0 || ch == 0) {
				ch = getch();
				switch (ch) {
				case LEFT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("YES");
					}
					else {
						gotoxy(30, 51); printf("N O");
					}
					break;
				case RIGHT:
					num = num * (-1);
					if (num == 1) {
						gotoxy(30, 51); printf("YES");
					}
					else {
						gotoxy(30, 51); printf("N O");
					}
					break;
				}
			}
			else {
				if (IsKeyDown(VK_SPACE)) {
					flag = 0;
				}
			}
		}
		if (num == 1 && landinfo[position].vacationhome <= cash) {
			landinfo[position].property = player;
			landinfo[position].vhflag = 1;
			UpdateCash(player, (-landinfo[position].mountain));
			PrintLand(player, position);
		}
		else if (num == 1 && landinfo[position].vacationhome > cash) {
			gotoxy(1, 51); printf("산을 구입할 현금이 부족합니다.        ");
			delay(1000);
		}
	}
	else if (landinfo[position].property == player) {
		gotoxy(1, 51); printf("이미 자신의 산 입니다.                ");
		delay(500);
	}
	else {
		gotoxy(1, 51); printf("다른 플레이어의 산 입니다.            ");
		for (i = 0; i < 40; i++) {
			if (landinfo[i].property == landinfo[position].property) {
				mountain += (landinfo[i].mountain);
			}
		}
		gotoxy(1, 52); printf("-%d", mountain);
		delay(2000);
		gotoxy(1, 52); printf("      ");
		if (cash >= mountain) {
			UpdateCash(player, (-mountain));
			UpdateCash(landinfo[position].property, mountain);
		}
		else {
			paylandevent(player, position, playerinfo[player - 1].cash, mountain);
		}

	}
}

void Expo(int player, int position) {
	int ch, flag, num, i;
	gotoxy(1, 51); puts("개최할 위치를 선택하세요 ◁         ▷");
	gotoxy(29, 51); printf("%s", p[0]);

	flag = 1;
	num = 0;
	while (flag) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (num > 31) {
					num--;
				}
				else if (num == 31) {
					num = num - 2;
				}
				else if (num <= 29 && num >= 1) {
					num--;
				}
				else {
					num = 39;
				}
				gotoxy(29, 51); printf("%s", p[num]);
				break;
			case RIGHT:
				if (num < 29) {
					num++;
				}
				else if (num == 29) {
					num = num + 2;
				}
				else if (num >= 31 && num < 39) {
					num++;
				}
				else {
					num = 0;
				}
				gotoxy(29, 51); printf("%s", p[num]);
				break;
			}
		}
		else {
			if (IsKeyDown(VK_SPACE)) {
				flag = 0;
			}
		}
	}
	if (num == 0 || num == 10 || num == 20 || num == 30 || num == 2 || num == 4 || num == 13 || num == 18 || num == 22 || num == 27 || num == 36 || num == 38 || num == 5 || num == 15 || num == 25 || num == 35 || num == 7 || num == 33 || landinfo[num].property != player) {
		gotoxy(1, 51); puts("잘못된 지역입니다. 다시 선택 하세요.  ");
		delay(1000);
		Expo(player, position);
	}
	else {
		for (i = 0; i < 40; i++) {
			landinfo[i].expo = 1;
		}
		landinfo[num].expo += expocount;
	}
	delay(500);
}