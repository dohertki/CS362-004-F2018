//cardtest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 /*
 
 The Mine

 "You may trash a Treasure from your hand. Gain a Treasure to your hand costing up to $3 more than it."
 */
 
 
 
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
        {{0,1,2},{4,5,6}},    //hand[MAX_PLAYERS][MAX_HAND];
        {0,0},  // handCount[MAX_PLAYERS];
        {{0,1,2,3,4,5,6,7,10,25},{0,1,2,3,4,5,6,7,10,25}},    //deck[MAX_PLAYERS][MAX_DECK];
        {10,10},              //deckCount[MAX_PLAYERS];
        {{0,0},{1,0}},    //discard[MAX_PLAYERS][MAX_DECK];
        {0},    //discardCount[MAX_PLAYERS];
        {0},    // playedCards[MAX_DECK];
         0     // playedCardCount;
    };

int main(){

    int coins = 0;

    cardEffect(11, -1, -1, -1, &state_chk,1 , &coins);

    return 0;
}