//randomtestcard1


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
 
 The Smithy
 Draw +3 cards
 "the player immediately draws X number of cards from his
Deck. If there are not enough cards in his Deck, he draws as many as he
can, shuffles the Discard pile to form a new Deck, and then draws the
rest. If he still does not have enough cards left after forming a new Deck,
he just draws as many as he can."
 */
 

int main(){

    int i, x;
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
    int test_count = 1000;    
    //Get game status before card played    
  
    srand(time(0));

    
    //Get game status before card played    
    player = state_chk.whoseTurn;
   
   
     for( x = 0; x < test_count; x++){
    //    printf("Coin value of hand before card draw %d\n", hand_coin);
    
        randomizePiles(1,10, &state_chk);
        copyPlayerState(player, 3, &state_chk);  
        //Get pre-draw status        
        in_hand_count = state_chk.handCount[player];
        in_deck_count = state_chk.deckCount[player];
        
        cardEffect(13, -1, -1, -1, &state_chk,1 , &coins);

        //Get post-draw status
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
    
        printf("Finished test # %d\n", x + 1);
    }

    return 0;
}

