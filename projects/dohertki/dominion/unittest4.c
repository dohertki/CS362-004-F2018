//unittest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>




    
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
   
    int player = 1;
    int in_deck_count;
    int in_hand_count;
    int out_deck_count;
    int out_hand_count;
    int top_card;    

  printf ("Unit Test 4: drawCard().\n");

    
    
    in_deck_count = state_chk.deckCount[player];
    in_hand_count = state_chk.handCount[player];
    top_card = state_chk.deck[player][in_deck_count -1];
    
    
    drawCard(player, &state_chk);

    out_deck_count = state_chk.deckCount[player];

    if(out_deck_count == in_deck_count -1 ){
        printf("PASSED: deck count before draw %d, deck count after draw %d\n", in_deck_count, out_deck_count);    
    }else{
        printf("FAILED: deck count before draw %d, deck count after draw %d\n", in_deck_count, out_deck_count);    
        
    }

    out_hand_count = state_chk.handCount[player];

    if(out_hand_count == in_hand_count + 1 ){
        printf("PASSED: hand count before draw %d, hand count after draw %d\n", in_hand_count, out_hand_count);    
    }else{
        printf("FAILED: hand count before draw %d, hand count after draw %d\n", in_hand_count, out_hand_count);    
        
    }

    if(top_card == state_chk.hand[player][out_hand_count - 1]){
        printf("PASSED: card successfully drawn deck to hand\n");
    }else{
        printf("FAILED: card not successfully drawn deck to hand\n");
    }

    return 0;
}






