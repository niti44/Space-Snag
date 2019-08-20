#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include<stdio.h>

void rocket(int i,int j)
{
	//draw triangle and set colour
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, BLUE);
	line(200+i, 200+j, 200+i, 225+j);
	line(200+i, 225+j, 250+i, 212+j);
	line(250+i, 212+j, 200+i, 200+j);
	floodfill(201+i, 212+j, WHITE);

	//draw rectangle and set colour
	setcolor(WHITE);
	setfillstyle(HATCH_FILL, GREEN);
	bar(100+i, 225+j, 200+i, 200+j);
	//draw two triangles on each side of the bar
	//triangle1
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, RED);
	line(85+i, 185+j, 170+i, 200+j);
	line(170+i, 200+j, 100+i, 200+j);
	line(100+i, 200+j, 85+i, 185+j);
	floodfill(105+i, 199+j, WHITE);

	//triangle2
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, RED);
	line(85+i, 240+j, 170+i, 225+j);
	line(170+i, 225+j, 100+i, 225+j);
	line(100+i, 225+j, 85+i, 240+j);
	floodfill(101+i, 226+j, WHITE);

}

int main() {
	int gd = DETECT, gm;
	int i, x, y, j = 0, k = 0, s = 0, test = 0, l = 0, r, score = 0;
	char ch[50];
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	while(1)
	{

		for (i = 0;i <= 500;i = i +9)
		{
			delay(40);
			cleardevice();
			r = rand() % 250 + 1;
			for (k = 0;k < 30;k++)
			{
				x = rand() % (getmaxx());
				y = rand() % (getmaxy());
				putpixel(x, y, 15);
			}


			if (kbhit())
			{
				i = i - 70;
				getch();
				rocket(j, i);


			}
			rocket(j, i);
			s = 700 - l;
			setfillstyle(HATCH_FILL,8);
			bar3d(750 - l, 200 - test, 700 - l, 300 - test,20,1);
			setfillstyle(SOLID_FILL, GREEN);
			floodfill(700-l + 2, ((400-test)+(200-test))/2, WHITE);
			setfillstyle(SOLID_FILL, YELLOW);
			floodfill(((750-l) + (700-l)) / 2, 200-test- 2, WHITE);
			l = l + 15;
			setfillstyle(SOLID_FILL,BROWN);
			bar(800-l, 0, 100-l, 5);
			bar(800-l,460,100-l,455);
			setcolor(WHITE);
			sprintf(ch, "score %d", score);
			outtextxy(500, 2, ch);
			
			if (s < 30)
			{
				l = 0;
				test = r;
				l = l + 9;
				sprintf(ch,"score %d",score++);
			}
			if (((700 - l) <= 250) && ((225 + i) > (200 - test)) && (200 + i) < (300 - test) && ((185 + i) < (300 - test)) && ((240 + i) > (200 - test)))
			{
				outtext("GAME OVER");
				sprintf(ch, "score %d", score);
				exit(0);


			}
			if (((240 + i) > 450) || ((185 + i) < 5))
			{

				outtext("GAME OVER");
				sprintf(ch, "score %d", score);
				exit(0);
			}

		       
		}

	}

	getch();
	closegraph();
	return 0;
}