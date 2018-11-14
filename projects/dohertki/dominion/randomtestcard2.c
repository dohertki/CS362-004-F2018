//randomtestcard2





#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include "randomtest.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

 /*
 
 The Village
    +1 card
    +2 action
    function starts at line 740 in dominion.c

 */
 



int main(){

    int i, x;
    int coins = 0;
 //   int in_deck_count;
 //   int in_hand_count;
  //  int out_deck_count;
  //  int out_hand_count;
    int flag_card = 0; 
    int draw_one = 0;
    int draw_two = 0;
    int draw_three = 0;
    int player;
    int test_count = 10;    
    //Get game status before card played    
  
    srand(time(0));

    /*Part 1 Static Test*/
    //Get game status before card played    
    player = state_chk.whoseTurn;
   
   // in_hand_count = state_chk.handCount[player];
   // in_deck_count = state_chk.deckCount[player];
     
     
    cardEffect(14, -1, -1, -1, &state_chk,1 , &coins);
     
     
    //Get post-draw status
   // out_hand_count = state_chk.handCount[player];
   // out_deck_count = state_chk.deckCount[player];
    
     
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
    
       
        
     
     
     /*Part 2 Automated Tests*/
     
     
     for( x = 0; x < test_count; x++){
    
    
        randomizePiles(1,10, &state_chk);
        copyPlayerState(player, 3, &state_chk);  
        
        cardEffect(14, -1, -1, -1, &state_chk,1 , &coins);

        checkNewAction(2, &state_chk);
        checkDrawCard(player, 3, &state_chk);
        
        printf("Finished test # %d\n", x + 1);
     }        
        
    return 0;
}
