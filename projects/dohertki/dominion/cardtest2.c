//unittest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 /*
 
 The Great Hall
 +1 Card
 +1 Action
  Action-Victory (+1 )
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
        {{0,1,2},{4,16,6}},    //hand[MAX_PLAYERS][MAX_HAND];
        {3,3},  // handCount[MAX_PLAYERS];
        {{0,1,2,3,4,5,6,7,10,25},{0,1,2,3,4,5,6,7,10,25}},    //deck[MAX_PLAYERS][MAX_DECK];
        {10,10},              //deckCount[MAX_PLAYERS];
        {{0,0},{1,0}},    //discard[MAX_PLAYERS][MAX_DECK];
        {0},    //discardCount[MAX_PLAYERS];
        {0},    // playedCards[MAX_DECK];
         0     // playedCardCount;
    };

int main(){

    int i;
    int coins = 0;
    int in_actions;
    int in_deck_count;
    int in_hand_count;
    int out_deck_count;
    int out_hand_count;
    int flag_card = 0;
    int draw_one = 0;
    int player = 1;
    in_actions = state_chk.numActions;



    cardEffect(16, -1, -1, -1, &state_chk, 1 , &coins);

    for( i = 0; i < state_chk.handCount[player] ; i++){
        if(state_chk.hand[player][i] == 16){
            flag_card = 1;
        }
        if(state_chk.hand[player][i] == 25){
            draw_one = 1;
        }    
        
    }


    if(flag_card != 1 ){
        printf("PASSED: Great Hall dropped from hand \n");    
    }else{
        printf("FAILED: Great Hall failed to be discarded\n" );    
    }

    if(draw_one == 1 ){
        printf("PASSED: First card drawn to hand\n");    
    }else{
        printf("FAILED: First card failed to be drawn\n");    
    }
  
    if(in_actions == state_chk.numActions -1){
        printf("PASSED: Player has one additional action\n");
    }else{
        printf("FAILED: Player failed to get one additional action\n");
    }   








    return 0;
}