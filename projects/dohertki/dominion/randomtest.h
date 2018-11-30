


#ifndef _RANDOMTEST_H
#define _RANDOMTEST_H



#include "dominion.h"





 struct gameState state_chk ={
        2,                    //Number of players
        {10,8,8,8,46,40,30},  //suplyCount[curse,estate,duchy,province,]
        {0,0}, //embargoTokens
        0,     //outpostPlayed
        0,     //Oupost Turn
        1,     // whoseTurn;
        0,     //int phase;
        1,     //int numActions; * Starts at 1 each turn */
        0,     //int coins; * Use as you see fit! */
        0,     //int numBuys; * Starts at 1 each turn */
        {{0,7,2,13},{4,7,6,12}},    //hand[MAX_PLAYERS][MAX_HAND];
        {3,3},  // handCount[MAX_PLAYERS];
        {{0,1,2,3,4,5,6,7,10,25},{0,1,2,3,4,5,6,7,10,25}},    //deck[MAX_PLAYERS][MAX_DECK];
        {0,10},              //deckCount[MAX_PLAYERS];
        {{4,4,13,1,14},{4,4,13,1,14}},    //discard[MAX_PLAYERS][MAX_DECK];
        {0},    //discardCount[MAX_PLAYERS];
        {0},    // playedCards[MAX_DECK];
         0     // playedCardCount;
    };



//Choose random cards for deck, hand and discard piles
int randomizePiles(int player, int h_max, struct gameState *rnd_state);

//Save values 'player' into 'checker' player posistion
int copyPlayerState(int player, int checker, struct gameState *chk_state);
//Check if 'delta' additional actions added to game.
void checkNewAction( int delta, struct gameState *act_state);
//Check if drawCard() funcions correctly
void checkDrawCard(int player, int checker, struct gameState *draw_state);

#endif