//randomtestcard2



#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 /*
 
 The Village
 





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
        {{0,1,2},{4,13,6}},    //hand[MAX_PLAYERS][MAX_HAND];
        {3,3},  // handCount[MAX_PLAYERS];
        {{0,1,2,3,4,5,6,7,10,25},{0,1,2,3,4,5,6,7,10,25}},    //deck[MAX_PLAYERS][MAX_DECK];
        {10,10},              //deckCount[MAX_PLAYERS];
        {{0,1,2,3,4,5,6,7,10,25},{1,0}},    //discard[MAX_PLAYERS][MAX_DECK];
        {10,2},    //discardCount[MAX_PLAYERS];
        {0},    // playedCards[MAX_DECK];
         0     // playedCardCount;
    };
int copyPlayerState(int player, gameState *chk_state){
    int checker = 4;

    chk_state->handCount[checker] = chk_state->handCount[player];

    return 0; 
}; 
 
int main(){





    int i;
    int coins = 0;
    int in_deck_count;
    int in_hand_count;
    int out_deck_count;
    int out_hand_count;
    int flag_card = 0; 
    int draw_one = 0;
    int draw_two = 0;
    int draw_three = 0;
    int player;
    
    //Get game status before card played    
    player = state_chk.whoseTurn;
    in_hand_count = state_chk.handCount[player];
    in_deck_count = state_chk.deckCount[player];


    //Card Effect: 14 = The Village
    cardEffect(14, -1, -1, -1, &state_chk,1 , &coins);

    //Get new game status
    out_hand_count = state_chk.handCount[player];
    out_deck_count = state_chk.deckCount[player];
    
    if(out_deck_count == in_deck_count - 3 ){
        printf("PASSED: deck count before smithy %d, deck count after smithy %d\n", in_deck_count, out_deck_count);    
    }else{
        printf("FAILED: deck count before smithy %d, deck count after smithy %d\n", in_deck_count, out_deck_count);    
        
    }

    out_hand_count = state_chk.handCount[player];

    if(out_hand_count == in_hand_count + 2 ){
        printf("PASSED: hand count before smithy %d, hand count after smithy %d\n", in_hand_count, out_hand_count);    
    }else{
        printf("FAILED: hand count before smithy %d, hand count after smithy %d\n", in_hand_count, out_hand_count);    
        
    }

    for( i = 0; i < state_chk.handCount[player] ; i++){
        if(state_chk.hand[player][i] == 13){
            flag_card = 1;
        }
        if(state_chk.hand[player][i] == 7){
            draw_one = 1;
        }    
        if(state_chk.hand[player][i] == 10){
            draw_two = 1;
        }    
        if(state_chk.hand[player][i] == 25){
            draw_three = 1;
        }
    }
  printf("hand count %d\n", state_chk.handCount[4]);

    if(flag_card != 1 ){
        printf("PASSED: smithy dropped from hand \n");    
    }else{
        printf("FAILED: smithy failed to be discarded\n" );    
    }
    if(draw_one == 1 ){
        printf("PASSED: First card drawn to hand\n");    
    }else{
        printf("FAILED: First card failed to be drawn\n");    
    }
    if( draw_two == 1 ){
        printf("PASSED: Second card drawn to hand \n");    
    }else{
        printf("FAILED: Second card Failed to be drawn\n");    
    }
    if( draw_three == 1){
        printf("PASSED: Third card drawn to hand \n");    
    }else{
        printf("FAILED: Third card failed to be drawn\n");    
    }


  


    return 0;
}