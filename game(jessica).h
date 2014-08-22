#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"

extern StopWatch g_timer;
extern bool g_quitGame;

enum Keys
{
    K_LEFT,
    K_RIGHT,
    K_ESCAPE,
    K_COUNT
};

void startmenu();
void init();                // initialize your variables, allocate memory, etc
void getInput();            // get input from player
void update(double dt);     // update the game and the state of the game
void render();              // renders the current state of the game to the console
void shutdown();            // do clean up, free memory
void printMap();

struct Map
{
	char tile;
	int Identity;
	bool move;

	Map(char tileName, int identityNum, bool moving)
	{
		tile = tileName;
		Identity = identityNum;
		move = moving;
	}
};

#endif // _GAME_H