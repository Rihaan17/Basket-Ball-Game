#include "iGraphics.h"
int mposx,  mposy;
/*
    function iDraw() is called again and again by the system.
*/
int a,b;
int flag=0;
int ball_x=450;
int ball_y=35;
int hoopy=300;
int hoopx=10;
int hoopflag=0;
int score=0;
int menuflag=1;
int ballspeed=15;
char Gameover[200]="Ball Remaining : 4 ";
int chance = 4;


void refresh()
{

 a,b;
 flag=0;
 ball_x=450;
 ball_y=35;
 hoopy=300;
 hoopx=10;
 hoopflag=0;
 score=0;
 menuflag=1;
 ballspeed=15;
 strcpy(Gameover,"Ball Remaining : 4 ");
 chance = 4;

}

void Now_throw()
{
    if(flag==1)
    {
      ball_y+=ballspeed;
	  if(ball_y>625){
		  flag=0;
		  ball_y=35;

		  if(chance==1){
			  //iShowBMP(1,1,"over.bmp");
			  sprintf(Gameover,"Game Over");
			  chance=-1;
		  }
		  else if( chance>0){

			   chance--;
			   sprintf(Gameover,"Ball Remaining : %d ",chance);
		  }
	  }
	  if(ball_x>hoopx+100 && ball_x<hoopx+200 && ball_y>hoopy+200 && ball_y<hoopy+270)
		  {
		    flag=2;
			score++;

			ball_x = 450;
			ball_y = 35;
		  }
    }

}

void start()
{
	//iShowBMP2(1,1,"menu.bmp",255);
	iShowBMP(1,1,"start2.bmp");
}

void Maingame()
{
	//iFilledRectangle(1,1,1000,700);
	iShowBMP(1,1,"ground.bmp");
	iSetColor(255,255,255);
	iFilledRectangle(1,650,1000,50);
	iSetColor(0,0,0);
	char GameScore[200];

	sprintf(GameScore,"Score : %d",score);
	iText(886,674,GameScore);
	iText(600,674,Gameover);
	//printf("%d %d ",a,b);
  //  iShowBMP2(hoopx,290, "images\\hoop3.bmp",0);

   iShowBMP2(hoopx,hoopy, "hoop5.bmp",0);
   iShowBMP2(ball_x,ball_y,"images\\ball1.bmp",255);

	//iShowBMP(hoopx,hoopy, "hoop5.bmp");
    //iShowBMP(ball_x,ball_y,"images\\ball1.bmp");



}
void Hoop_move()
{
    if(hoopflag==0)
    {
      hoopx+=10;
      if(hoopx>=650)
      {
         hoopflag=1;
      }
    }

    else if(hoopflag==1)
    {
        hoopx-=10;
        if(hoopx<=0)
        {
          hoopflag=0;
        }
    }
}

void iDraw()
{
    //place your drawing codes here
    iClear();
    //Maingame();
	if(menuflag==1){
	start();
	}

	else{
		Maingame();
	}

	if(chance==-1)
	{
		iShowBMP(1,1,"gameover.bmp");

	}


	//iShowBMP(1,1,"images\\start1.bmp");
}

/*
    function iMouseMove() is called when the user presses and drags the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	a=mx;
	b=my;

    //place your codes here
}

/*
    function iMouse() is called when the user presses/releases the mouse.
    (mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        menuflag=0;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
    //place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
    function iKeyboard() is called whenever the user hits a key in keyboard.
    key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q' && chance >=0)
    {

        flag=1;

    }

	else if(key=='b'){

		refresh();
	}

    //place your codes for other keys here
}

/*
    function iSpecialKeyboard() is called whenver user hits special keys like-
    function keys, home, end, pg up, pg down, arraows etc. you have to use
    appropriate constants to detect them. A list is:
    GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
    GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
    GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
    GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_RIGHT)
    {
        ball_x += 10;
		if (ball_x >= 925) {
			ball_x = 925;
		}
    }

    else if(key == GLUT_KEY_LEFT)
    {
       ball_x -= 10;
	   if (ball_x <= 0) {
		   ball_x = 0;
	   }
    }
}
//
int main()
{
    //place your own initialization codes here...
    iSetTimer(60,Hoop_move);
    iSetTimer(60,Now_throw);
    iInitialize(1000, 700, "Basket Ball Game");

    return 0;
}


