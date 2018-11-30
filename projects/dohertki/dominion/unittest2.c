//unittest2.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main(){

    int player = 1;
    
    struct gameState test ={
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
        {3,3},  // handCount[MAX_PLAYERS];
        {{0,1,2},{1,2,3}},    //int deck[MAX_PLAYERS][MAX_DECK];
        {0},    //int deckCount[MAX_PLAYERS];
        {{0,0},{1,0}},    //int discard[MAX_PLAYERS][MAX_DECK];
        {0}, //int discardCount[MAX_PLAYERS];
        {0},   //int playedCards[MAX_DECK];
         0    //int playedCardCount;
    };



    printf("Unit test 2 \n");



    updateCoins(player, &test, 10);

    if(test.coins == 16){
        printf("PASSED- Add value of 1 copper, 1 silver, 1 gold, and 10, The values of the coins is %d\n", test.coins);
    }else{
        printf("FAILED- Add value of 1 copper, 1 silver, 1 gold, and 10, The values of the %d coins is incorrect\n", test.coins);
    }
    
    
     test.hand[1][0] = 0;
     test.hand[1][1] = 0;
     test.hand[1][2] = 0;
     
    

    updateCoins(player, &test, 10);

    if(test.coins == 10){
        printf("PASSED- Add value of 0 copper, 0 silver, 0 gold, and 10, The values of the coins is %d \n", test.coins);
    }else{
        printf("FAILED- Add value of 0 copper, 0 silver, 0 gold, and 10, The values of the %d coins is incorrect \n", test.coins);
    }
     
     test.hand[1][0] = 4;
     

    updateCoins(player, &test, 0);

    if(test.coins == 1){
        printf("PASSED- Add value of 1 copper, 0 silver, 0 gold, and 0, The values of the coins is %d \n", test.coins);
    }else{
        printf("FAILED- Add value of 1 copper, 0 silver, 0 gold, and 0, The values of the %d coins is incorrect \n", test.coins);
    }
    
     
     test.hand[1][0] = 5;
     
    

    updateCoins(player, &test, 0);

    if(test.coins == 2){
        printf("PASSED- Add value of 0 copper, 1 silver, 0 gold, and 0, The values of the coins is %d \n", test.coins);
    }else{
        printf("FAILED- Add value of 0 copper, 1 silver, 0 gold, and 0, The values of the %d coins is incorrect \n", test.coins);
    }
    
    
    return 0;
}

















/*


int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;
	
  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
	{
	  state->coins += 1;
	}
      else if (state->hand[player][i] == silver)
	{
	  state->coins += 2;
	}
      else if (state->hand[player][i] == gold)
	{
	  state->coins += 3;
	}	
    }	

  //add bonus
  state->coins += bonus;

  return 0;
}
*/
