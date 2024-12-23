#include <string>
#include <conio.h>
#include <time.h>
#include <winbgim.h>
#include <iostream>
#include "Game.h"


using namespace std;

extern int lever;
extern int snakelength1;
extern int snakelength2;
extern color snakecolor;
extern color snakecolor2;
extern bool endgame;
extern char *Pscore;
extern char P2score[5];
extern Point *snake1;
extern Point *snake2;
int typeG = 1;
int main()
{
	srand(time(NULL));
    initwindow(1200,600);
    int i = 0;
    char ARR[3];
    setcolor(7);
    settextstyle(3,0,5);
    rectangle(365,230,790,320);
    snakecolor.fillcolor = 10;
    snakecolor.flangecolor = 2;
    snakecolor2.fillcolor = 9;
    snakecolor2.flangecolor = 1;
    InitialScore(); // doc file score txt ban dau
    while (i <= 100)
    {
        if(i < 10)setcolor(15);
        else if(i < 20)setcolor(7);
        else if(i < 30)setcolor(8);
        else if(i < 40)setcolor(0);
        else if(i < 50)setcolor(8);
        else if(i < 60)setcolor(7);
        else if(i < 70)setcolor(15);
        else if(i < 80)setcolor(14);
        else if(i < 90)setcolor(12);
        else setcolor(4);
        outtextxy(390,250,"Game Loading");
        sprintf(ARR,"%d",i);
        outtextxy(665,250,ARR);
        outtextxy(735,250,"%");
        delay(2);
        if(i == 100)
        {
            delay(100);
            cleardevice();
            setcolor(5);
            settextstyle(4,0,5);
            PlaySound(TEXT("Eshop.wav"), NULL, SND_ASYNC);
            delay(100);
            outtextxy(370,250,"Load complete");
            delay(1700);
        }
        i++;
    }
x1:
    cleardevice();
    clearmouseclick(WM_LBUTTONDOWN);
    setbkcolor(0);
    cleardevice();
    for(int i = 0; i < 2000; i++)
    {
        putpixel(rand()%1200,rand()%600,rand()%getmaxcolor());
    }
    PlaySound(TEXT("Theme.wav"), NULL, SND_ASYNC | SND_LOOP);
    //TEN GAME
    setcolor(7);
    //rectangle(300,30,900,200);
    setlinestyle(SOLID_LINE,1000,THICK_WIDTH);
    setfillstyle(SOLID_FILL,0);
    bar(302,32,898,198);
    bar(402,212,798,578);
    bar3d(300,30,900,200,20,1);
    bar3d(400,210,800,580,18,1);

    setfillstyle(SOLID_FILL,8);
    rectangle(470,220,730,280);//1 ngang 60 dai 260
    bar(450,219,470,282);
    rectangle(470,290,730,350);//2
    bar(450,289,470,352);
    rectangle(470,360,730,420);//3
    bar(450,359,470,422);
    rectangle(470,430,730,490);//4
    bar(450,429,470,492);
    rectangle(470,500,730,560);//5
	bar(450,499,470,562);

    setcolor(14);
    settextstyle(3,0,8);
    delay(100);
    outtextxy(330,70,"GAME SNAKE");
    settextstyle(4,0,4);
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 450 || mousey() > 560 || mousey() < 220 || mousex() > 730)
        {
            //MENU GAME
            showtext(480,230,"New game");
            showtext(480,300,"High score");
            showtext(530,370,"About");
            showtext(538,440,"More");
            showtext(550,510,"Quit");

            setbar(120,320,170,370);
            setbar(170,370,220,420);
            setbar(120,420,170,470);
            setbar(70,370,120,420);
            setpieslice(1060,340,0,360,30,14,2);
            setpieslice(1000,440,0,360,30,1,4);
        }
        clearmouseclick(WM_LBUTTONDOWN);
        if(mousey() <= 280)//////Part 1
        {
x5:
			cleardevice();
			clearmouseclick(WM_LBUTTONDOWN);
        	setbkcolor(0);
        	cleardevice();
        	PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
        		setcolor(15);
            	settextstyle(3,0,7);
        		outtextxy(400,100,"Choose Player");
        		settextstyle(3,0,5);
        		outtextxy(540,380,"Return");
        		setcolor(7);
        		outtextxy(540,230,"1 Player");
        		outtextxy(540,310,"2 Player");
        		
        		setcolor(8);
        		rectangle(440,220,780,290);
        		rectangle(440,300,780,365);
        		rectangle(440,375,780,440);
        	while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 440 || mousex() > 780 || mousey() < 220 || mousey() > 440)
        	{
				delay(50);// delay de bat duoc mouseclick, neu khong set up delay se gay loi!
        	}
			if(mousey() <= 290)
			{
				typeG = 1;
			}
			else if(mousey() <= 370)
			{
				typeG = 2;
			}
			else
			{
					clearmouseclick(WM_LBUTTONDOWN);
					delay(10);
					goto x1;
			}
x3:
        	cleardevice();
        	clearmouseclick(WM_LBUTTONDOWN);
        	setbkcolor(0);
        	int namefunction;
        	PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
        		setcolor(15);
            	settextstyle(3,0,7);
        		outtextxy(440,100,"Game Type");
        		settextstyle(3,0,5);
        		outtextxy(540,380,"Return");
        		setcolor(7);
        		outtextxy(540,230,"Classic");
        		
        		setcolor(8);
        		rectangle(440,220,780,290);
        		rectangle(440,300,780,365);
        		rectangle(440,375,780,440);
        	while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 440 || mousex() > 780 || mousey() < 220 || mousey() > 440)
        	{
        		showtext(540,310,"Modern");
				delay(50);// delay de bat duoc mouseclick, neu khong set up delay se gay loi!
        	}
        	
        		if(mousey() <= 290)
        		{
        			cleardevice();
        			clearmouseclick(WM_LBUTTONDOWN);
        			namefunction = 1;
        			PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
        			setcolor(15);
        			rectangle(465,205,485,495);
        			settextstyle(3,0,8);
        			outtextxy(450,40,"Classic");
        			settextstyle(3,0,5);
        			setcolor(8);
        			outtextxy(460,150,"Choose levers");
        			setcolor(7);
        			outtextxy(500,200,"1.Easy");
        			setcolor(11);
        			outtextxy(500,250,"2.Medium");
        			setcolor(3);
        			outtextxy(500,300,"3.Hard");
        			setcolor(9);
        			outtextxy(500,350,"4.Very hard");
        			setcolor(1);
        			outtextxy(500,400,"5.Expert");
        			setcolor(15);
        			outtextxy(500,450,"Return");
        			while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 495 || mousex() > 650 || mousey() < 195 || mousey() > 500)
        			{
        				delay(50);
        			}
        			if(mousey()<245)
        			{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 1;
        					showtext(500,200,"1.Easy");
        					i++;
						}
					}
					else if(mousey()<300)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 2;
        					showtext(500,250,"2.Medium");
        					i++;
						}	
					}
					else if(mousey()<350)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 3;
        					showtext(500,300,"3.Hard");
        					i++;
						}
					}
					else if(mousey()<400)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 4;
        					showtext(500,350,"4.Very hard");
        					i++;
						}
					PlaySound(TEXT("soundhard.wav"),NULL,SND_ASYNC);
					delay(800);
					}
					else if(mousey()<450)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 5;
        					showtext(500,400,"5.Expert");
        					i++;
						}
						PlaySound(TEXT("snake69.wav"),NULL,SND_ASYNC);
						delay(800);
					}
					else
					{
						PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
						delay(500);
						goto x3;
					}
				}
				else if(mousey() <= 370)
				{
        			cleardevice();
					clearmouseclick(WM_LBUTTONDOWN);
					namefunction = 2;
        			PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
        			setcolor(15);
        			bar3d(460,205,480,495,10,1);
        			settextstyle(4,0,7);
        			outtextxy(430,60,"Modern");
        			settextstyle(3,0,5);
        			setcolor(8);
        			outtextxy(460,150,"Choose levers");
        			setcolor(4);
        			outtextxy(500,200,"1.Easy");
        			setcolor(12);
        			outtextxy(500,250,"2.Medium");
        			setcolor(14);
        			outtextxy(500,300,"3.Hard");
        			setcolor(2);
        			outtextxy(500,350,"4.Very hard");
        			setcolor(1);
        			outtextxy(500,400,"5.Expert");
        			setcolor(15);
        			outtextxy(500,450,"Return");

        			while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 495 || mousex() > 650 || mousey() < 195 || mousey() > 500)
        			{
        				delay(50);
        			}
        			if(mousey()<245)
        			{ 
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 1;
        					showtext(500,200,"1.Easy");
        					i++;
						}
					}
					else if(mousey()<300)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 2;
        					showtext(500,250,"2.Medium");
        					i++;
						}	
					}
					else if(mousey()<350)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 3;
        					showtext(500,300,"3.Hard");
        					i++;
						}
					}
					else if(mousey()<400)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 4;
        					showtext(500,350,"4.Very hard");
        					i++;
						}
					PlaySound(TEXT("soundhard.wav"),NULL,SND_ASYNC);
					delay(800);
					}
					else if(mousey()<450)
					{
        			i = 0;
        			PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
        				while (i <= 15)
        				{
        					lever = 5;
        					showtext(500,400,"5.Expert");
        					i++;
						}
						PlaySound(TEXT("snake69.wav"),NULL,SND_ASYNC);
						delay(800);
					}
					else
					{
						PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
						delay(500);
						goto x3;
					}
				}
				else
				{
					clearmouseclick(WM_LBUTTONDOWN);
					delay(10);
					goto x5;
				}
				if(typeG == 1) // 1P*****************************************************************
				{
				setlinestyle(SOLID_LINE,0,NORM_WIDTH);
				clearmouseclick(WM_LBUTTONDOWN);
				setGame();
				auxSetGame();
				while(!endgame)
				{
					delay(250-(lever-1)*55);
					namefunction == 1 ? mainloop(classic) : mainloop(modern); 
					drawgame(snake1,snakecolor,snakelength1);
				}
				int flag = CheckHighScore(snakelength1*lever*10 - lever*30);
				setcolor(6);
				settextstyle(3,0,5);
				if (flag == 0)  PlaySound(TEXT("Gameover.wav"),NULL,SND_ASYNC);
				bar(300,120,540,330);
				rectangle(300,120,540,330);
				outtextxy(320,140,"Game Over");
				outtextxy(320,200,"Play Again?");
				settextstyle(3,0,4);
				setcolor(10);
				outtextxy(310,282,"Yes");
				setcolor(12);
				outtextxy(480,282,"No");
				setcolor(0);
				rectangle(308,280,368,320); // dai 60 rong 40
				rectangle(470,280,530,320);
x4:
				clearmouseclick(WM_LBUTTONDOWN);
				while(!ismouseclick(WM_LBUTTONDOWN))
				{
					delay(10);
				}
				if(ismouseclick(WM_LBUTTONDOWN))
				{
				
					if(mousex() < 368 && mousex() > 308 && mousey() < 320 && mousey() > 280)
					{
						PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
						delay(400);
						clearmouseclick(WM_LBUTTONDOWN);
						goto x5;
					}
					else if(mousex() < 530 && mousex() > 470 && mousey() < 320 && mousey() > 280)
					{
						PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
						delay(400);
						clearmouseclick(WM_LBUTTONDOWN);
						goto x1;
					}
					else
					{
						clearmouseclick(WM_LBUTTONDOWN);
						goto x4;
					}
				}
				}
				else // 2 P****************************************************************************8
				{
				setlinestyle(SOLID_LINE,0,NORM_WIDTH);
				clearmouseclick(WM_LBUTTONDOWN);
				setGame();
				auxSetGame();
				while(!endgame)
				{
					delay(250-(lever-1)*55);
					namefunction == 1 ? mainloop(classic) : mainloop(modern);
					drawgame(snake1,snakecolor,snakelength1);
					namefunction == 1 ? mainloop2(classic) : mainloop2(modern);
					drawgame2P(snake2,snakecolor2,snakelength2);
				}
				int sc1 = snakelength1*lever*10 - lever*30;
				int sc2 = snakelength2*lever*10 - lever*30;
				settextstyle(3,0,5);
				if(sc1 > sc2)
				{
					rectangle(290,170,550,240);
					PlaySound(TEXT("highscoreE.wav"), NULL, SND_ASYNC);
					outtextxy(300,180,"Player 1 win !");
					delay(2000);
				}
				else if(sc1 < sc2)
				{
					rectangle(290,170,550,240);
					PlaySound(TEXT("highscoreE.wav"), NULL, SND_ASYNC);
					outtextxy(300,180,"Player 2 win !");
					delay(2000);
				}
				else
				{
					rectangle(290,170,550,240);
					PlaySound(TEXT("draw.wav"), NULL, SND_ASYNC);
					outtextxy(360,180,"Draw !");
					delay(2000);
				}
				setcolor(6);
				settextstyle(3,0,5);
				bar(291,120,550,330);
				rectangle(290,120,550,330);
				outtextxy(320,140,"Game Over");
				outtextxy(320,200,"Play Again?");
				settextstyle(3,0,4);
				setcolor(10);
				outtextxy(310,282,"Yes");
				setcolor(12);
				outtextxy(480,282,"No");
				setcolor(0);
				rectangle(308,280,368,320); // dai 60 rong 40
				rectangle(470,280,530,320);
	x6:
				clearmouseclick(WM_LBUTTONDOWN);
				while(!ismouseclick(WM_LBUTTONDOWN))
				{
					delay(10);
				}
				if(ismouseclick(WM_LBUTTONDOWN))
				{
				
					if(mousex() < 368 && mousex() > 308 && mousey() < 320 && mousey() > 280)
					{
						PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
						delay(400);
						clearmouseclick(WM_LBUTTONDOWN);
						goto x5;
					}
					else if(mousex() < 530 && mousex() > 470 && mousey() < 320 && mousey() > 280)
					{
						PlaySound(TEXT("Choose.wav"),NULL,SND_ASYNC);
						delay(400);
						clearmouseclick(WM_LBUTTONDOWN);
						goto x1;
					}
					else
					{
						clearmouseclick(WM_LBUTTONDOWN);
						goto x6;
					}
				}
				}
		} 
		else if(mousey() <= 350)
		{
			cleardevice();
			PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
			while(!ismouseclick(WM_LBUTTONDOWN))
			{
			delay(50);
			rectangle(300,70,900,500);
			settextstyle(4,0,6);
			showtext(410,80,"High score");
			ShowHighScore();
			}
			 
			 goto x1;
		}
		else if(mousey() <= 420)
		{
			cleardevice();
			PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
			while(!ismouseclick(WM_LBUTTONDOWN))
			{
				settextstyle(4,0,6);
				showtext(300,60,"Do an game C++");
				setcolor(15);
				settextstyle(4,0,3);
				outtextxy(300,200,"Ngay thuc hien : 1/8/2021");
				outtextxy(300,250,"Ngay hoan thanh : 10/8/2021");
				outtextxy(300,300,"Game duoc phat trien tu");
				outtextxy(300,330,"do an game ran san moi cua");
				outtextxy(300,360,"trang web Lap Trinh Khong Kho.");
			}
			goto x1;
		}
		else if(mousey() < 490)
		{
			cleardevice();
			PlaySound(TEXT("Intro.wav"),NULL,SND_ASYNC);
			Point temp;
			temp.x = 550; temp.y = 230;
			// mau 1
			setcolor(2);
			setfillstyle(SOLID_FILL,10);
			for(int i = 0;i < 5;i++)
			{
				drawpoint(temp.x,temp.y,10);
				temp.x -= 20;
			}
			//mau 2
			temp.x = 550; temp.y = 290;
			setcolor(4);
			setfillstyle(SOLID_FILL,12);
			for(int i = 0;i < 5;i++)
			{
				drawpoint(temp.x,temp.y,10);
				temp.x -= 20;
			}
			// mau 3
			temp.x = 550; temp.y = 350;
			setcolor(5);
			setfillstyle(SOLID_FILL,13);
			for(int i = 0;i < 5;i++)
			{
				drawpoint(temp.x,temp.y,10);
				temp.x -= 20;
			}
			// mau 4
			temp.x = 550; temp.y = 470;
			setcolor(8);
			setfillstyle(SOLID_FILL,7);
			for(int i = 0;i < 5;i++)
			{
				drawpoint(temp.x,temp.y,10);
				temp.x -= 20;
			}
			// mau 5
			temp.x = 550; temp.y = 410;
			setcolor(4);
			setfillstyle(SOLID_FILL,14);
			for(int i = 0;i < 5;i++)
			{
				drawpoint(temp.x,temp.y,10);
				temp.x -= 20;
			}
			setcolor(7);
			rectangle(20,20,1180,560);
			setcolor(2);
			setfillstyle(SOLID_FILL,0);
			settextstyle(4,0,5);
			outtextxy(200,100,"Change Your Snake Color");
			bar3d(650,200,750,250,10,1);bar3d(650,260,750,310,10,1);bar3d(650,320,750,370,10,1);bar3d(650,380,750,430,10,1);bar3d(650,440,750,490,10,1);
			setcolor(15);
			settextstyle(3,0,3);
			outtextxy(658,210,"Change");outtextxy(658,270,"Change");outtextxy(658,330,"Change");outtextxy(658,390,"Change");outtextxy(658,450,"Change");
			while(!ismouseclick(WM_LBUTTONDOWN) || mousex() < 650 || mousex() > 750 || mousey() < 200 || mousey() > 500)
			{
				delay(100);
			}
			clearmouseclick(WM_LBUTTONDOWN);
			if(mousey() <= 255)
			{
				PlaySound(TEXT("gameclick.wav"),NULL,SND_ASYNC);
				delay(400);
				snakecolor.fillcolor = 10;
				snakecolor.flangecolor = 2;
			}
			else if(mousey() <= 315)
			{
				PlaySound(TEXT("gameclick.wav"),NULL,SND_ASYNC);
				delay(400);
				snakecolor.fillcolor = 12;
				snakecolor.flangecolor = 4;
			}
			else if(mousey() <= 375)
			{
				PlaySound(TEXT("gameclick.wav"),NULL,SND_ASYNC);
				delay(400);
				snakecolor.fillcolor = 13;
				snakecolor.flangecolor = 5;
			}
			else if(mousey() <= 445)
			{
				PlaySound(TEXT("gameclick.wav"),NULL,SND_ASYNC);
				delay(400);
				snakecolor.fillcolor = 14;
				snakecolor.flangecolor = 4;
			}
			else
			{
				PlaySound(TEXT("gameclick.wav"),NULL,SND_ASYNC);
				delay(400);
				snakecolor.fillcolor = 7;
				snakecolor.flangecolor = 8;
			}
			goto x1;	
		}
		else
		{
			delay(10);
			exit(0);
		}
    }
    delete[] Pscore;
    delete[] snake1;
    delete[] snake2;
    closegraph();
    return 0;
}

