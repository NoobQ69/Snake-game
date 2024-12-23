#include <iostream>
#include <winbgim.h>
#include <conio.h>
#include <time.h>
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXX 820
#define MAXY 420
#define MINX 20
#define MINY 20
#define Background 15

int lever;
int snakelength1;
int snakelength2;
bool endgame = false;
extern int typeG;
Point *snake1 = new Point[3600];
Point *snake2 = new Point[3600];
Point dir1;//direction 
Point dir2;
Point food;
color snakecolor;
color snakecolor2;
Score scoregame[5];
char *Pscore = new char[5];
char P2score[5]; 
const int DIRECTION = 10;
extern int typeG;
using namespace std;
//Do hoa cho game
void showtext(int x,int y,char *str)
{
	setcolor(rand()%(15)+1);
	outtextxy(x,y,str);
	delay(50);
}
void setbar(int top,int left,int right,int bottom)
{
	setfillstyle(SOLID_FILL,12);
	bar(top,left,right,bottom);
	delay(100);
	setfillstyle(SOLID_FILL,4);
	bar(top,left,right,bottom);
}
void setpieslice(int x,int y,int gd,int gc,int r,int color1 = 0,int color2 = 0)
{
	setfillstyle(SOLID_FILL,color1);
	pieslice(x,y,gd,gc,r);
	delay(50);
	setfillstyle(SOLID_FILL,color2);
	pieslice(x,y,gd,gc,r);
}
// Set up cho game
void auxSetGame()
{
	int c = getcolor();
	PlaySound(TEXT("startgame.wav"),NULL,SND_ASYNC);
	setcolor(8);
	settextstyle(3,0,5);
	rectangle(352,172,498,238);
	outtextxy(370,180,"Ready");
	delay(1000);
	bar(350,170,500,240);//dai 150, ngang 70
	setcolor(7);
	rectangle(352,172,498,238);
	outtextxy(380,180,"Start");
	delay(1000);
	bar(350,170,500,240); 
	setcolor(c);
}

void setGame()
{
	setbkcolor(Background);
	cleardevice();
	endgame = false;
	setfillstyle(SOLID_FILL,1);
	setwindowtitle("Snake Game"); // nhin len goc trai man hinh do hoa :D
	// ve map cho game
	bar(MINX,MINY,MAXX,MINY+5); // canh tren
	bar(MAXX,MINY,MAXX-5,MAXY); // canh phai
	bar(MINX,MAXY,MAXX,MAXY-5); // canh duoi
	bar(MINX,MINY,MINX+5,MAXY); // canh trai

	setcolor(7);
	setfillstyle(SOLID_FILL,8);
	int b[] = {1005,260, 1005,255, 1000,255, 1010,240, 1020,255, 1015,255, 1015,260, 1005,260};
	fillpoly(8,b);//up
	int c[] = {1005,320, 1005,325, 1000,325, 1010,340, 1020,325,1015,325,1015,320,1005,320};
	fillpoly(8,c);//down
	int d[] = {980,285, 975,285, 975,280, 960,290, 975,300, 975,295,980,295,980,290};
	fillpoly(8,d);//left
	int e[] = {1040,285, 1045,285, 1045,280, 1060,290, 1045,300, 1045,295, 1040,295, 1040,285};
	fillpoly(8,e);//right
	circle(1010,290,30);
	settextstyle(3,0,2);

	outtextxy(1000,210,"up");
	outtextxy(1065,278,"right");
	outtextxy(925,278,"left");
	outtextxy(990,340,"down");
	rectangle(980,400,1050,450);
	rectangle(900,460,1050,510);
	setcolor(8);
	outtextxy(1060,410,"Quit game");
	outtextxy(1060,470,"Pause/Resum");
	settextstyle(3,0,4);
	outtextxy(990,408,"Esc");
	outtextxy(920,470,"Space");

	dir1.x = 10;//set up huong di chuyen dau tien cho snake
	dir1.y = 0;
	dir2.x = 0;
	dir2.y = 10;
	snakelength1 = 3;
	snake1[0].x = 400;
	snake1[0].y = 200;
	snake1[1].x = 390;
	snake1[1].y = 200;
	snake1[2].x = 380;
	snake1[2].y = 200;
	
	snakelength2 = 3;
	snake2[0].x = 200;
	snake2[0].y = 200;
	snake2[1].x = 200;
	snake2[1].y = 190;
	snake2[2].x = 200;
	snake2[2].y = 180;
	setfillstyle(1,Background);
	bar(25,25,815,415);
	do
	{
		food.x = (rand() % 78 + 3)*10;
		food.y = (rand() % 38 + 3)*10;
	}
	while(checkfood() == false);
	snakecolor.fillcolor;
	snakecolor.flangecolor;
	snakecolor2.fillcolor;
	snakecolor2.flangecolor;
}

void drawpoint(int x,int y,int r)
{
	circle(x,y,r);
	floodfill(x,y,getcolor());
}

void drawsnake(Point snake[],color colors,int snakelength)
{
	setcolor(colors.flangecolor);
	setfillstyle(1,colors.fillcolor);
	for(int i = 0;i < snakelength;i++)
	{
		drawpoint(snake[i].x,snake[i].y,5);
	}
	// delete dot cuoi khi ran di chuyen
	setfillstyle(1,Background);
	drawpoint(snake[snakelength-1].xo,snake[snakelength-1].yo,5);
	setcolor(Background);
	circle(snake[snakelength-1].xo,snake[snakelength-1].yo,5);
}

void drawfood()
{
	setcolor(rand() % 15 + 1);
	setfillstyle(SOLID_FILL,rand() % 15 + 1);
	drawpoint(food.x,food.y,5);
	setfillstyle(SOLID_FILL,Background);
}

void drawgame(Point snake[],color colors,int snakelength)
{
	// ve snake va ve food
	drawsnake(snake,colors,snakelength);
	drawfood();
	setcolor(8);
	settextstyle(3,0,4);
	//show score
	char arr[10];
	if(typeG == 1) 
	{
		outtextxy(850,20,"Your Score :");
		outtextxy(850,120,"Best Score :");
		sprintf(arr,"%d",scoregame[0].score);
		outtextxy(1100,120,arr);
	}
	else outtextxy(850,20,"P1 Score :");
	sprintf(Pscore,"%d",snakelength*lever*10-lever*30);
	outtextxy(1100,20,Pscore);
}

void drawgame2P(Point snake[],color colors,int snakelength)//draw 2 ng choi
{
	// ve snake va ve food
	drawsnake(snake,colors,snakelength);
	setcolor(9);
	settextstyle(3,0,4);
	//show score
	outtextxy(850,80,"P2 Score :");
	sprintf(P2score,"%d",snakelength*lever*10-lever*30);
	outtextxy(1100,80,P2score);
}

bool checkfood() // ham nay kiem tra food co trung voi snake hay khong
{
	for(int i = 0;i < snakelength1;i++)
	{
		if(food.x == snake1[i].x && food.y == snake1[i].y)
		{
			return false;
		}
	}
	for(int i = 0;i < snakelength2;i++)
	{
		if(food.x == snake2[i].x && food.y == snake2[i].y)
		{
			return false;
		}
	}
	return true;
}

void classic(Point snake[],Point direction,int &snakelength)
{
	for(int i = 0; i < snakelength; i++)
	{
		if(i == 0)
		{
			snake[0].xo = snake[0].x;
			snake[0].yo = snake[0].y;
			snake[0].x += direction.x;
			snake[0].y += direction.y;
		}
		else
		{
			snake[i].xo = snake[i].x;
			snake[i].yo = snake[i].y;
			snake[i].x = snake[i-1].xo;
			snake[i].y = snake[i-1].yo;
		}
		if(snake[i].x >= MAXX) snake[i].x = MINX+10;
		if(snake[i].x <= MINX) snake[i].x = MAXX-10;
		if(snake[i].y >= MAXY) snake[i].y = MINY+10;
		if(snake[i].y <= MINY) snake[i].y = MAXY-10;
		
		if(typeG == 2)
		{
				if(i != 0 &&((snake1[0].x == snake2[i].x && snake1[0].y == snake2[i].y) || (snake2[0].x == snake1[i].x && snake2[0].y == snake1[i].y)))
				endgame = true;
		}
		if(i != 0 && (snake[0].x == snake[i].x && snake[0].y == snake[i].y))
		{
			PlaySound(TEXT("bonk2.wav"),NULL,SND_ASYNC);
			delay(1000);
			endgame = true;
		}
	}
		if(snake[0].x == food.x && snake[0].y == food.y)
		{
			PlaySound(TEXT("eat.wav"),NULL,SND_ASYNC);
			snake[snakelength].x = snake[snakelength-1].xo;
			snake[snakelength].y = snake[snakelength-1].yo;
			snakelength++;
			do
			{
				food.x = (rand() % 78 + 3)*10;
				food.y = (rand() % 38 + 3)*10;
			}
			while(checkfood() == false);
		}
}

void modern(Point snake[],Point direction,int &snakelength)
{
	for(int i = 0;i < snakelength; i++)
	{
		if(i == 0)
		{
			snake[0].xo = snake[0].x;
			snake[0].yo = snake[0].y;
			snake[0].x += direction.x;
			snake[0].y += direction.y;
		}
		else
		{
			snake[i].xo = snake[i].x;
			snake[i].yo = snake[i].y;
			snake[i].x = snake[i-1].xo;
			snake[i].y = snake[i-1].yo;
		}
		if(snake[0].x > MAXX-5 || snake[0].x < MINX+5 || snake[0].y > MAXY-5 || snake[0].y < MINY+5)
		{
			PlaySound(TEXT("bonk2.wav"),NULL,SND_ASYNC);
			delay(1000);
			endgame = true;
			break;
		}
		if(typeG == 2)
		{
			if(i != 0 &&((snake1[0].x == snake2[i].x && snake1[0].y == snake2[i].y) || (snake2[0].x == snake1[i].x && snake2[0].y == snake1[i].y)))
			endgame = true;
		}
		if(i != 0 && (snake[0].x == snake[i].x && snake[0].y == snake[i].y))
		{
			PlaySound(TEXT("bonk2.wav"),NULL,SND_ASYNC);
			delay(1000);
			endgame = true;
		}
	}
		if(snake[0].x == food.x && snake[0].y == food.y)
		{
			PlaySound(TEXT("eat.wav"),NULL,SND_ASYNC);
			snake[snakelength].x = snake[snakelength-1].xo;
			snake[snakelength].y = snake[snakelength-1].yo;
			snakelength++;
			do
			{
				food.x = (rand() % 78 + 3)*10;
				food.y = (rand() % 38 + 3)*10;
			}
			while(checkfood() == false);
		}
}

void changeDir(int get)
{
	switch(get)
	{
		case 72 : // leen (up)
			{
				if(dir1.y != DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir1.y = -DIRECTION;
					dir1.x = 0;
				}
				break;
			}
		case 77: // phai (right)
			{
				if(dir1.x != -DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir1.y = 0;
					dir1.x = DIRECTION;
				}
				break;
			}
		case 80: //xuong (down)
			{
				if(dir1.y != -DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir1.y = DIRECTION;
					dir1.x = 0;
				}
				break;
			}
		case 75 : //trai (left)
			{
				if(dir1.x != DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir1.y = 0;
					dir1.x = -DIRECTION;
				}
				break;
			}	
		case 115: //up
			{
				if(dir2.y != DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir2.y = -DIRECTION;
					dir2.x = 0;
				}
				break;
			}
		case 99: // right
			{
				if(dir2.x != -DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir2.y = 0;
					dir2.x = DIRECTION;
				}
				break;
			}
		case 120: // down
			{
				if(dir2.y != -DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir2.y = DIRECTION;
					dir2.x = 0;
				}
				break;
			}
		case 122 :
			{
				if(dir2.x != DIRECTION)
				{
					PlaySound(TEXT("switch.wav"),NULL,SND_ASYNC);
					dir2.y = 0;
					dir2.x = -DIRECTION;
				}
				break;
			}
		case 27 : //exit game
			{
				endgame = true;
			}
			break;
	}
}


void mainloop(void (*typegame)(Point arr[],Point direction,int &l))
{
	if(!kbhit())
	{
		typegame(snake1,dir1,snakelength1);
	}
	else
	{
		char get = getch();
		if(get == -32) get = getch();
		if(get == 32)
		{
			setcolor(8);
			PlaySound(TEXT("pause1.wav"),NULL,SND_ASYNC);
			outtextxy(360,180,"Pause");
		get = getch();
		while(get != 32)
		{
			get = getch();
			delay(10);
		}
		setcolor(Background);
		PlaySound(TEXT("pause2.wav"),NULL,SND_ASYNC);
		outtextxy(360,180,"Pause");
		delay(200);
		}
		changeDir(get);
		mainloop(typegame); // goi de quy lai de thao tac voi phim di chuyen nhanh hon(toi uu toc do)
	}
}

void mainloop2(void (*typegame)(Point arr[],Point direction,int &l))
{
	if(!kbhit())
	{
		typegame(snake2,dir2,snakelength2);
	}
	else
	{
		char get = getch();
		if(get == 32)
		{
			setcolor(8);
			PlaySound(TEXT("pause1.wav"),NULL,SND_ASYNC);
			outtextxy(360,180,"Pause");
		get = getch();
		while(get != 32)
		{
			get = getch();
			delay(10);
		}
		setcolor(Background);
		PlaySound(TEXT("pause2.wav"),NULL,SND_ASYNC);
		outtextxy(360,180,"Pause");
		delay(200);
		}
		changeDir(get);
		mainloop2(typegame); // goi de quy lai de thao tac voi phim di chuyen nhanh hon(toi uu toc do)
	}
}

///set up score cho game
bool CheckFileEmpty()
{
	FILE *f = fopen("ScoreGame.txt","r");
	long sizef = 0;
	if(f)
	{
		fseek(f,0,SEEK_END);
		sizef = ftell(f);
	}
	fclose(f);
	return sizef == 0;
}

void InitialScore() // ham nay kiem tra file duoc goi co tro^'ng ro^~ng hay khong, sau do chep ten va diem vao mang struct Score
{
	if(CheckFileEmpty())
	{
		for(int i = 0;i < 5;i++)
		{
			strcpy(scoregame[i].name,"Player");
			scoregame[i].score = 0;
		}
		CopyHighScore();
	}
	else
	{
		FILE *f = fopen("ScoreGame.txt","r");
		int i = 0;
		int countf = 0;
		char temp[20]; // 20 chu cai :D
		while (i < 5)
		{
			while(!feof(f))
			{

				fscanf(f,"%s",temp);
				++countf;
				if(countf % 2 == 1)
				{
					strcpy(scoregame[i].name,temp);
				}
				else
				{
					scoregame[i].score = atoi(temp);
					i++;
				}
			}
		}
		fclose(f);
	}
}

void CopyHighScore()
{
	FILE *f = fopen("ScoreGame.txt","w");
	for(int i = 0;i < 5; i++) // ghi vao tep only 5 nguoi choi co diem cao nhat
	{
		fputs(scoregame[i].name,f);
		fputs(" ",f);
		fprintf(f,"%d",scoregame[i].score);
		fputs("\n",f);
	}
	fclose(f);
}

int CheckHighScore(int scoreG)
{
	char Name[10] = {""};
	int flag = 0;
	int x = getcolor();
	for(int i = 0; i < 5; i++)
	{

		if(scoreG > scoregame[i].score)
		{
			if(i == 0)
			{
				settextstyle(3,0,4);
				flag = 1;
				PlaySound(TEXT("bestscore.wav"), NULL, SND_ASYNC);
				for(int i = 0; i < 25; i++)
				{
					setcolor(12); outtextxy(320,180,"BEST SCORE !!!");
					delay(50);
					setcolor(9);  outtextxy(320,180,"BEST SCORE !!!");
					delay(50);
					setcolor(14); outtextxy(320,180,"BEST SCORE !!!");
				}
			}
			else
			{
				settextstyle(3,0,4);
				flag = 1;
				PlaySound(TEXT("highscoreE.wav"), NULL, SND_ASYNC);
				for(int i = 0; i < 15; i++)
				{
					setcolor(11); outtextxy(320,180,"HIGH SCORE !");
					delay(50);
					setcolor(9);  outtextxy(320,180,"HIGH SCORE !");
					delay(50);
					setcolor(1); outtextxy(320,180,"HIGH SCORE !");
				}
			}
			settextstyle(3,0,2);
			setcolor(7);
			outtextxy(340,250,"Name Player :");
			setcolor(8);
			char temp[2];
			temp[1] = 0;
			char ch;
			int x = 0;
			while(ch != 13 && x < 10)
			{
				do
				{
					ch = getch();
				}
				while((temp[0] <= 48 && temp[0] >= 57 )||(temp[0] <= 65 && temp[0] >= 132));
				x++;
				temp[0] = ch;
				strcat(Name,temp);
				outtextxy(500,250,Name);
			}
			for(int j = 4;j > i; j--)
			{
				strcpy(scoregame[j].name,scoregame[j - 1].name);
				scoregame[j].score = scoregame[j - 1].score;
			}
			strcpy(scoregame[i].name,Name);
			scoregame[i].score = scoreG;
			break;
		}
	}
	setcolor(x);
	CopyHighScore();
	return flag;
}

void ShowHighScore()
{
	InitialScore();

	setcolor(15);
	settextstyle(3,0,4);
	char arr[10];
	int j = 0;
	for(int i = 0;i < 5 ; i++)
	{
		sprintf(arr,"%d",i+1);
		outtextxy(345,160 + j,"Top");
		outtextxy(410,160 + j,arr);
		sprintf(arr,"%d",scoregame[i].score);
		outtextxy(440,160 + j,scoregame[i].name);
		outtextxy(740,160 + j,arr);
		j += 60;
	}
}

