/*
Game Name: ASPHALT 2D

Developed by
Md. Seratul Arshad

Course teacher: Nashid Habib Barna

*/
# include "iGraphics.h"

double wLen=656;//468;			// Window's length
double wHig=700;//728;			// Window's hight


int x=349, y=0;				    // my car's co-ordinate
int  time1=5, time2 = 2;	    // time for animating car & iland

int cl=68, ch=128;			    // every car's -------'cl' for width & 'ch' for length



int score=0;//for score count and display
int level=0;// for level count and display
char scoreText[50];
char levelText[50];

//////////////enymy/////////////

double encarX1 = 273;			// Enemy car's co-ordinate
double encarY1 = 1000;
double encarX2 = 349;
double encarY2 = 1200;
double encarX3 = 423;
double encarY3 = 1700;
double encarX4 = 497;
double encarY4 = 1500;

/////////////////////////////////////

int grassX = 580;
int grassY = 900;
int grassX1 = 580;
int grassY1 = 1000;
int grassX2 = 190;
int grassY2 = 800;
int grassX3 = 190;
int grassY3 = 1100;

/******** Enemy Car Speed************/
double speed = 0.3;
double enCarSpeed1 = speed;
double enCarSpeed2 = speed;
double enCarSpeed3 = speed;
double enCarSpeed4 = speed;

///////road move///////////
int roadX=342;
int roadY[7] = {100,199,298,397,496,595,694};
int roadX2=490;
int roadY2[7] = {100,199,298,397,496,595,694};
int	no_of_island = 7;

///////////////////////////////
int load=(int)time(NULL);   /// for loading
double load_count=0;



int i;						// 'i' for loop control
int game = 1;				// 'game' for menu , game start , game over control
int pause= 3;				// for pause & resume control
int menu = 6;

void animateRoad();

void Delay();
bool play = true;

int r = 255;
int g = 255;
int b = 255;


void iDraw(){
	iClear();

	/***********Loading**************/

	if(menu==6){
		if((int)time(NULL)-load<5)
		{
			r =rand() % 255;
			g =rand() % 200;
			b =rand() % 255;
		iSetColor(r,g,b);
		iText(275,350,"Loading...",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(6,166,14);
		iFilledRectangle(0,300,load_count+=.2,20);
		iSetColor(0,0,0);
		iFilledRectangle(0,300,100,20);
		iFilledRectangle(556,300,100,20);


	    }
		else{
			menu=0;
		}

	}
	/********************************/

	if(menu == 0){
		iShowBMP(0,0,"pic\\menu.bmp");//Home console

		if(play)
		 {
		 PlaySound("pic\\formula.wav", NULL, SND_ASYNC);// | SND_LOOP);
		 play =false;
		 }
		//iShowBMP(x,y, "pic\\food.bmp");
	}



	else if(menu == 1){

		 if(pause == 1){


				/******* Road ******/
				iShowBMP(260,0, "pic\\road.bmp");
				iSetColor(119,147,60);
				iFilledRectangle(575,0,80,700);
				iFilledRectangle(180,0,80,700);

				/*******************************/


				/*****Enymy Car*********/
				iShowBMP(encarX1,encarY1, "pic\\enemycar1.bmp");
				iShowBMP(encarX2,encarY2, "pic\\enemycar7.bmp");
				iShowBMP(encarX3,encarY3, "pic\\enemycar3.bmp");
				iShowBMP(encarX4,encarY4, "pic\\enemycar4.bmp");


				/*******************End enymycar*******************************/

				    /***********Tree************/

				iShowBMP(grassX,grassY, "pic\\tree.bmp");//tree
				iShowBMP(grassX1,grassY1, "pic\\grass.bmp");
				iShowBMP(grassX2,grassY2, "pic\\grass.bmp");
				iShowBMP(grassX3,grassY3, "pic\\tree.bmp");

				    /**************Tree End***************/

				for(i=0; i<no_of_island; i++){
					iShowBMP(roadX,roadY[i], "pic\\iland.bmp");
					iShowBMP(roadX2,roadY2[i], "pic\\iland.bmp");
		        }

				iShowBMP(x,y, "pic\\mycar.bmp");        //My Car

				/***********  Car Collision**********/

		if( y+ch>=encarY1 && y+ch<=encarY1+ch && x+cl>=encarX1 && x+cl<=encarX1+cl ||
			y+ch>=encarY1 && y+ch<=encarY1+ch && x>=encarX1 && x<=encarX1+cl ||

			y+ch>=encarY2 && y+ch<=encarY2+ch && x+cl>=encarX2 && x+cl<=encarX2+cl ||
			y+ch>=encarY2 && y+ch<=encarY2+ch && x>=encarX2 && x<=encarX2+cl ||

			y+ch>=encarY3 && y+ch<=encarY3+ch && x+cl>=encarX3 && x+cl<=encarX3+cl ||
			y+ch>=encarY3 && y+ch<=encarY3+ch && x>=encarX3 && x<=encarX3+cl ||

			y+ch>=encarY4 && y+ch<=encarY4+ch && x+cl>=encarX4 && x+cl<=encarX4+cl ||
			y+ch>=encarY4 && y+ch<=encarY4+ch && x>=encarX4 && x<=encarX4+cl
		  )

		{
			menu = 4;

		}


		/************************************************************/



				//Score //

				iSetColor(255,0,0);
				iText(30,590,"Score:", GLUT_BITMAP_TIMES_ROMAN_24);
				_itoa(score,scoreText,10);
				iText(90,590,scoreText, GLUT_BITMAP_TIMES_ROMAN_24);

				//------------------------------//

				//Level//
				iSetColor(255,0,0);
				iText(30,550,"Level:", GLUT_BITMAP_TIMES_ROMAN_24);
				_itoa(level,levelText,10);
				iText(90,550,levelText, GLUT_BITMAP_TIMES_ROMAN_24);

				//----------------------------------------------//



		}


	}



	else if(menu == 2){

		iShowBMP(0,0, "pic\\instruc.bmp");
		//(x,y, "pic\\food.bmp");
	}


	else if(menu == 3){
		exit(0);
	}

	else if(menu==4){
		pause=0;
		int ax=score;
		iShowBMP(0, 0, "pic\\gameover.bmp");
		iSetColor(255, 255, 255);
		iText(240, 300, "Your Score :", GLUT_BITMAP_TIMES_ROMAN_24);
		char ScoreString[5];
		itoa(ax, ScoreString, 10);
		iText(370, 300, ScoreString, GLUT_BITMAP_TIMES_ROMAN_24);
		pause=007;
		score=0;
		level=0;
		menu=5;
	}
	else if(menu==5){
		Delay();

		double encarX1 = 273;			// Enemy car's co-ordinate
		double encarY1 = 1000;
		double encarX2 = 349;
		double encarY2 = 1200;
		double encarX3 = 423;
		double encarY3 = 1700;
		double encarX4 = 497;
		double encarY4 = 1500;
		double speed = 0.3;
		double enCarSpeed1 = speed;
		double enCarSpeed2 = speed;
		double enCarSpeed3 = speed;
		double enCarSpeed4 = speed;

		pause=1;


		menu=0;  //to go main menu


	}


	if(pause==0){
		play=false;
			 if(!play){
				 PlaySound(0,0,0);

			 }
		iSetColor(255,0,0);
		iText(180,350,"Press 'r' to resume the game", GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//animatescore();
	animateRoad();
	//animateEnCar();
}


/************ Delay Func*********/
void Delay(){
	for (i = 0; i < 10; i++) {        // delay of one second delay(0.1);
			float number_of_seconds=1;        // Converting time into milli_seconds
			float milli_seconds = 200 * number_of_seconds;
			// Stroing start time
			clock_t start_time = clock();
			// looping till required time is not acheived
			while (clock() < start_time + milli_seconds);

			//printf("%d seconds have passed\n", i + 1);//for testing
		}
}

/*********** Rode Move*************/
void animateRoad(){
	if(pause==1){

		for(i=0; i<no_of_island; i++){
			roadY[i] = roadY[i] - 2;		// for 1st iland  5
			if(roadY[i]<=1){
				roadY[i] = 700;
			}

			roadY2[i] = roadY2[i] - 2;		// for 2nd iland
			if(roadY2[i]<=1){
				roadY2[i] = 700;
			}

		}
	}
}

///////////////////////////////////

/************* Enymy Car Move***********/

void animateEnCar(){
	if(pause==1){
		//if(game ==1){
			if(score % 200 == 0 ){
				enCarSpeed1 +=speed;
				enCarSpeed2 +=speed;
				enCarSpeed3 +=speed;
				enCarSpeed4 +=speed;
			}
			encarY1 -= enCarSpeed1;
			encarY2 -= enCarSpeed2;
			encarY3 -= enCarSpeed3;			/// Enemy car speed initilize
			encarY4 -= enCarSpeed4;

			if(encarY1 <= -50){//128
				encarY1 =2800;
			}
			if(encarY2 <= -50){
				encarY2 =1750;
			}
			if(encarY3 <= -50){
				encarY3 =900;
			}
			if(encarY4 <= -50){
				encarY4 =1050;
			}


		//}
	}
}

//////////////////////////////////////////
void animateTree(){
	if(pause==1){
		grassY-=4;
		grassY1-=3;
		grassY2-=3;
		grassY3-=3;

		if(grassY <= -128){
			grassY =2600;
			}
		if(grassY1 <= -128){
			grassY1 =2200;
			}
		if(grassY2 <= -128){
			grassY2 =2200;
			}
		if(grassY3 <= -128){
			grassY3 =2600;
			}
	}
}

/*********  Score increase *************/

void animatescore(){
	if(pause==1){
		score ++;
		if(score % 200 == 0){
			level++;
		}

	}
}

////////////////////////////////////////



void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if(mx>= 480 && mx<= 648  && my>= 455  && my<= 506 ){          //Play button
			pause=1,
			menu = 1;
			play = false;
			if(!play){

		        PlaySound(0,0,0);
		    }
			play=true;
		}


		if(mx>= 480 && mx<= 648  && my>= 360  && my<= 412){             //Instruction button
			menu = 2;
		}

		if(mx>= 480 && mx<= 648  && my>= 267  && my<= 320){              //Exit button
			menu = 3;
		}

		if(mx>= 222 && mx<= 394  && my>= 82  && my<= 148){              //Exit button
			menu = 0;
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key){
		if(key == 'p')
		{
			pause = 0;

		}
		if(key == 'r')
		{
			pause = 1;

		}
		if(key == 'q')
		{
			exit(0);
		}
		if(key == 'h')
		{
			PlaySound("pic\\jeep_horn",NULL,SND_ASYNC);
		}

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
	printf("X = %d and Y = %d\n",x,y);
	if(pause==1){

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_INSERT)
	{

	}
	if(key==GLUT_KEY_LEFT )
		if(x > 274){
			x=x-15;//20
		}
			//x--;

	if(key==GLUT_KEY_RIGHT)
		if(x < 489 ){
			x=x+15;
		}  //x++;

	if(key==GLUT_KEY_UP)
		if(y < 585 ){
			y=y+15;
		}  //y++;

	if(key==GLUT_KEY_DOWN)
		if(y > 0){
			y=y-15;
		}	//y--;
	}
}


int main()
{
	iSetTimer(time1, animateEnCar);
	iSetTimer(100, animatescore);
	iSetTimer(time2,animateTree);

	iInitialize(wLen, wHig, "ASPHALT 2D");
	return 0;
}
