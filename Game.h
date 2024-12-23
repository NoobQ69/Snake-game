#ifndef GAME
#define GAME
struct Point
{
	int x; int xo;
	int y; int yo;
	int dx;int dy;
};
struct color
{
	int fillcolor;
	int flangecolor;
};
struct Score
{
	int score;
	char name[26];
};
typedef struct color color;
typedef struct Point Point;
typedef struct Score Score;
// do hoa
void showtext(int x,int y,char *str);
void setbar(int top,int left,int right,int bottom);
void setpieslice(int x,int y,int gd,int gc,int r,int color1,int color2);

void drawpoint(int x,int y,int r);
void drawsnake(Point snake[],color colors,int snakelength);
void drawfood();
void drawgame(Point snake[],color colors,int snakelength);
void drawgame2P(Point snake[],color colors,int snakelength);
// xu li logic cho game
bool checkfood();
void classic(Point snake[],Point direction,int &snakelength);
void modern(Point snake[],Point direction,int &snakelength);
void changeDir(int get);
void mainloop(void (*typegame)(Point arr[],Point direction,int &l));
void mainloop2(void (*typegame)(Point arr[],Point direction,int &l));
void setGame();
void auxSetGame();
// ghi score cho game
bool CheckFileEmpty();
void InitialScore();
void CopyHighScore();
int CheckHighScore(int scoreG);
void ShowHighScore();

#endif
