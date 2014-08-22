// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

double elapsedTime;
double deltaTime;
bool keyPressed[K_COUNT];
COORD charLocation;
COORD consoleSize;
COORD basket;

int const MapLength=20;
int const MapHeight=10;
char GenerateMap[MapLength][MapHeight];
Map Apple('A', 1, false);
Map Orange('O', 2, false);
Map Grape('G', 3 , false);
Map Worm('W', 4, false);
Map Spaces('.', 5, false);

void init()
{
	// Set precision for floating point output
	std::cout << std::fixed << std::setprecision(3);

	SetConsoleTitle(L"SP1 Framework");

	// Sets the console size, this is the biggest so far.
	setConsoleSize(79, 28);

	// Get console width and height
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

	/* get the number of character cells in the current buffer */ 
	GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
	consoleSize.X = csbi.srWindow.Right + 1;
	consoleSize.Y = csbi.srWindow.Bottom + 1;

	// set the character to be in the center of the screen.
	charLocation.X = consoleSize.X / 2;
	charLocation.Y = consoleSize.Y / 2;

	basket.X =0;
	basket.Y =  MapLength+3;

	elapsedTime = 0.0;
}
void shutdown()
{
	colour(FOREGROUND_BLUE);
	cout<<"********* **    **     **     ***    *** ***     ***   ****         \n"
	      "********* **    **    ****    *****  *** ***    ***  ********         \n"
	      "   ***    **    **   **  **   ****** *** ***   ***  ****  ****     \n"
		  "   ***    ********  **    **  ********** ********    ****       \n"
		  "   ***    ******** ********** ********** ********      *****         \n"
		  "   ***    **    ** ***    *** *** ****** ***   ***  ***   ****        \n"
		  "   ***    **    ** ***    *** ***  ***** ***    ***  ********* \n"
		  "   ***    **    ** ***    *** ***    *** ***     ***   ****"<<endl;
	cout<<"    ****     ********* *********   ***       ***    *****     ***    ***\n"
          "  ********   ********* *********    ***     ***   ***   ***   ***    ***\n"
	      " ****  ****  ***       ***           ***   ***   ***     ***  ***    ***\n"		      
		  "  ****       ***       ***            *** ***   ****     **** ***    ***\n"
		  "    ******   ********  ********        *****    ****     **** ***    ***\n"
	      "      *****  ***       ***             ****     ****     **** ***    ***\n"
          " ****   **** ***       ***            ****       ***     ***  ****  ****\n"
	      "  *********  ********* *********     ****         ***   ***    ********  \n"
	      "   ******    ********* *********    ****            *****       ******   "<<endl;
	cout<<
		 "      ***       *****       ***    ***  ***   ***  \n"
		 "     ** **    *********    ** **   ***  ****  ***  \n"
		 "    **   **  ***     ***  **   **  ***  ***** ***  \n"
		 "   **     ** ***     *** **     ** ***  *********  \n"
		 "   ********* ***         ********* ***  *********  \n"
		 "   ********* ***    **** ********* ***  *********  \n"
		 "   **     ** ***     *** **     ** ***  *** *****  \n"
		 "   **     **  *********  **     ** ***  ***  ****  \n"
		 "   **     **   *******   **     ** ***  ***   ***   "<<endl;
	exit(1);
}

void getInput()
{    
	keyPressed[K_LEFT] = isKeyPressed(VK_LEFT);
	keyPressed[K_RIGHT] = isKeyPressed(VK_RIGHT);
	keyPressed[K_ESCAPE] = isKeyPressed(VK_ESCAPE);
}

void update(double dt)
{
	// get the delta time
	elapsedTime += dt;
	deltaTime = dt;

	// Updating the location of the character based on the key press
	if (keyPressed[K_LEFT])
	{
		basket.X--;
		Beep(1440, 30);
	}

	if (keyPressed[K_RIGHT])
	{
		basket.X++;
		Beep(1440, 30);
	}

	// quits the game if player hits the escape key
	if (keyPressed[K_ESCAPE])
		g_quitGame = true;    
}

void render()
{
	colour(0x0F);
	cls();
	const WORD colors[] = 
	{
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	gotoXY(0, 0);
	cout << "Frames Per Second: "<<1.0 / deltaTime << std::endl;
	
    gotoXY(0, 1);
	cout << "Timer: " << elapsedTime << "secs" << std::endl;

	printMap();


	gotoXY(basket);
    std::cout << "\\_/";
}

void printMap()
{
	/*cout<<
		"*******      *                          ,      ,,,,,,,,		\n"
		"*******    **                            ,,    ,,,,,,,,\n"
		"*******   **                              ,,   ,,,,,,,,\n"
		"*******  **                                ,,  ,,,,,,,,\n"
		"**********                                  ,,,,,,,,,,,\n"
		"*********                                    ,,,,,,,,,,\n"
		"********                                      ,,,,,,,,,\n"
		"********                                       ,,,,,,,,\n"
		"********                                       ,,,,,,,,\n"
		"********                                       ,,,,,,,,\n"
		"********                                       ,,,,,,,,\n"
		"*********                                     ,,,,,,,,,"<<endl;*/
	for(int x = 0 ; x < MapLength ; x++)
	{
		for(int y = 0 ; y < MapHeight ; y++)
		{
			if(x<=0)
			{

				GenerateMap[x][y]=rand()%10;

				if(GenerateMap[x][y]==Apple.Identity)
				{
					GenerateMap[x][y]=Apple.tile;

				}
				else if(GenerateMap[x][y]==Orange.Identity)
				{
					GenerateMap[x][y]=Orange.tile;
				}
				else if(GenerateMap[x][y]==Grape.Identity)
				{
					GenerateMap[x][y]=Grape.tile;
				}
				else if(GenerateMap[x][y]==Worm.Identity)
				{
					GenerateMap[x][y]=Worm.tile;
				}

				else
				{
					GenerateMap[x][y]=' ';
				}

			}
			else
			{
				GenerateMap[x][y]='.';
			}
			cout<<GenerateMap[x][y];	
		}
		cout<<endl;
	}
	for(int x=0 ; x < MapLength ; ++x)
	{
		for(int y=0 ; y < MapHeight ; ++y)
		{


		}
	}
}