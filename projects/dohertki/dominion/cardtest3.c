



//unittest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 /*
 
 The Adeventurer
 Reveal cards from your deck until you reveal 2 Treasure cards.
 Put those Treasure cards in your hand and discard the other revealed cards.
  
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
        {{0,7,2},{4,7,6}},    //hand[MAX_PLAYERS][MAX_HAND];
        {3,3},  // handCount[MAX_PLAYERS];
        {{0,1,2,3,4,5,6,7,10,25},{0,1,2,3,4,5,6,7,10,25}},    //deck[MAX_PLAYERS][MAX_DECK];
        {0,10},              //deckCount[MAX_PLAYERS];
        {{4,4,13,1,14},{4,4,13,1,14}},    //discard[MAX_PLAYERS][MAX_DECK];
        {0},    //discardCount[MAX_PLAYERS];
        {0},    // playedCards[MAX_DECK];
         0     // playedCardCount;
    };

int main(){

    int i, j;
    int coins = 0;
    int in_deck_count;
    int in_hand_count;
    int out_deck_count;
    int out_hand_count;
    int match =0;
    int mismatch =0;
    int player;
    
    //Get game status before card played    
    player = state_chk.whoseTurn;
    in_hand_count = state_chk.handCount[player];
    in_deck_count = state_chk.deckCount[player];
    int pile[][MAX_DECK] =  {{0,1,2,3,4,5,6,7,10,25},{4,4,13,1,14}};
    int size_y = 10;	
    int size_x= 10;
        
   
    cardEffect(7, -1, -1, -1, &state_chk,1 , &coins);


 //Get new game status
    out_hand_count = state_chk.handCount[player];
    out_deck_count = state_chk.deckCount[player];
    
    if(out_deck_count == in_deck_count - 5 ){
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
    cardEffect(7, -1, -1, -1, &state_chk, 1 , &coins);

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
        printf("FAILED: deck missing cards after shuffle");
    }
    if(mismatch > 0){
        printf("SUCCESS: deck in new order following shuffle \n");
    }else{
        printf("FAILED: deck in same order after shuffle ");
    }    





    return 0;
}




