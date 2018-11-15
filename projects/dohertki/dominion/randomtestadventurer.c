//randomtestadventure.c


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
 
 The Adeventurer
 Reveal cards from your deck until you reveal 2 Treasure cards.
 Put those Treasure cards in your hand and discard the other revealed cards.
  
 */
 
 




// handPos
// currentPlayer
// gameState
// gameState.deckCount
// gameState.handCount[currentPlayer]
// gamestate.discoutn[currentPlayer]
// 



int main(){

    int i, j, x;
    int coins = 0;
    int in_deck_count;
    int in_hand_count;
    int out_deck_count;
    int out_hand_count;
    int match =0;
    int mismatch =0;
    int player;
    int hand_coin = 0;
    srand(time(0));
    //Get game status before card played    
    player = state_chk.whoseTurn;
    in_hand_count = state_chk.handCount[player];
    in_deck_count = state_chk.deckCount[player];
    int pile[][MAX_DECK] =  {{0,1,2,3,4,5,6,7,10,25},{4,4,13,1,14}};
    int size_y = 10;	
    int size_x= 10;
    
   
    hand_coin = countHandCoins(player, &state_chk);
     for( x = 0; x < 100; x++){
    //    printf("Coin value of hand before card draw %d\n", hand_coin);
    
        randomizePiles(0,101, &state_chk);  
        randomizePiles(1,101, &state_chk);
        copyPlayerState(player, 3, &state_chk);  
        cardEffect(7, -1, -1, -1, &state_chk,1 , &coins);
     
        printf("Random Test # %d\n", x);
    hand_coin = countHandCoins(1, &state_chk);
    
    printf("Coin value of hand before after draw %d\n", hand_coin);
    }
    printf("hello\n");
 //Get new game status
    out_hand_count = state_chk.handCount[player];
    out_deck_count = state_chk.deckCount[player];
    
    if(out_deck_count == in_deck_count - 3 ){
        printf("PASSED: deck count before adventurer %d, deck count after adventurer %d\n", in_deck_count, out_deck_count);    
    }else{
        printf("FAILED: deck count before adventurer %d, deck count after adventurer %d\n", in_deck_count, out_deck_count);    
        
    }

    out_hand_count = state_chk.handCount[player];

    if(out_hand_count == in_hand_count + 2 ){
        printf("PASSED: hand count before adventurer %d, hand count after adventurer %d\n", in_hand_count, out_hand_count);    
    }else{
        printf("FAILED: hand count before adventurer %d, hand count after adventurer %d\n", in_hand_count, out_hand_count);    
        
    }

    player = 0;
    state_chk.whoseTurn = 0;
    cardEffect(7, -1, -1, -1, &state_chk, 4 , &coins);

	printf("Deck size %d\n", size_x);
	
	for(i = 0; i < size_x; i++){
		for(j =0; j < size_y; j++){
	        if(state_chk.deck[player][i] == pile[player][j]){  
	            printf(" %d: %d %d\n", i, state_chk.deck[player][i],  pile[player][j]);
	            state_chk.deck[player][i]  = -1;
	            pile[player][j] =-1;
	            match ++;            
	            break ;
	            
	        }else{
                mismatch++;

            }
		
        
			
					}
		
	}
    if(match == size_x){
        printf("SUCCESS: the number of matches %d after shuffle\n", match);
    }else{
        printf("FAILED: deck missing cards after shuffle\n");
    }
    if(mismatch > 0){
        printf("SUCCESS: deck in new order following shuffle \n");
    }else{
        printf("FAILED: deck in same order after shuffle \n ");
    }    


    printf("hand count %d\n", state_chk.handCount[3]);


    return 0;
}




