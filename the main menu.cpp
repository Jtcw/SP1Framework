// This is the main file to hold everthing together

#include "Framework\timer.h"
#include "game.h"
#include<iostream>

StopWatch g_timer;            // Timer function to keep track of time and the frame rate
bool g_quitGame = false;      // Set to true if you want to quit the game
const unsigned char FPS = 5; // FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame
enum state 
{ 
	GAME = 1,
	OPTIONS,
	SCOREBOARD,
	HOME, 
	END 
};


void mainLoop();

// TODO:
// Bug in waitUnitil. it waits for the time from getElapsedTime to waitUntil, but should be insignificant.
int main()
{
	startmenu();
}
int play()
{
	init();      // initialize your variables
    mainLoop();  // main loop
    shutdown();  // do clean up, if any. free memory.
	
	return 0;
}

void startmenu()
{
	std::cout<<  "  ******    ***  ********  ******  ***  ***   ***   *** *** ***   *** ********   ***   \n"
		    " ********  ***** ******** ******** ***  ***   ****  *** *** ****  *** ********  *****  \n"
		    " ***  *** **   **  ****   ***  *** ***  ***   ***** *** *** ***** ***      *** **   ** \n" 
			" ***      **   **  ****   ***      ********   ***** *** *** ***** ***      *** **   ** \n"
			" ***      *******  ****   ***      ********   ********* *** ********* ***  *** ******* \n"
			" ***  *** *******  ****   ***  *** ***  ***   *** ***** *** *** ***** ***  *** ******* \n"
			" ******** **   **  ****   ******** ***  ***   ***  **** *** ***  **** ******** **   ** \n" 
			"  ******  **   **  ****    ******  ***  ***   ***   *** *** ***   ***  ******  **   ** "<<std::endl;
	std::cout<<"[1]START"<<std::endl;
	std::cout<<"[2]OPTIONS"<<std::endl;
	std::cout<<"[3]SCOREBOARD"<<std::endl;
	std::cout<<"[4]EXIT PROGRAM"<<std::endl;
	int a ;
	std::cin >> a;
	state stage = GAME;
	while(stage != END)
	{
		if(a == 1)
		{
			system("cls");
GAME:play();
			system("pause");
		
		}
		else if (a == 2)
		{

		}
		else if (a == 3)
		{
			system("cls");
			SCOREBOARD:;
		}
		else if (a == 4)
		{
			system("CLS");
			HOME:shutdown();
			system("pause");
		}
	}
}
// This main loop calls functions to get input, update and render the game
// at a specific frame rate
void mainLoop()
{
	
    g_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
    while (!g_quitGame)      // run this loop until user wants to quit 
	{        
        getInput();                         // get keyboard input
        update(g_timer.getElapsedTime());   // update the game
		render();
		// render the graphics output to screen
        g_timer.waitUntil(frameTime);   
		// Frame rate limiter. Limits each frame to a specified time in ms.      
	}    

}
