#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "rngs.h"
#include "interface.h"
#include "dominion.h"
#include "dominion.h"
#include <string.h>
#include <time.h>
#include <assert.h>


int randomizePiles(int player, int h_max, struct gameState *rnd_state){
    //Set the deck size
    int i;
    int deck_size = rand()%h_max;
    int hand_size = 5;
    int discard_size = h_max - deck_size;
    int card;
    
    rnd_state->handCount[player] = hand_size;
    rnd_state->deckCount[player] = deck_size;
    rnd_state->discardCount[player] = discard_size;


    for( i = 0; i< deck_size; i++){
        card = rand()%27;
     //  assert(&(rnd_state->deck[player][i])!= NULL) 
       //     printf("There is no room in deck storage %d\n", deck_size);
        rnd_state->deck[player][i] = card;
    }

    for( i = 0; i< hand_size ; i++){
        card = rand()%27;
     //   assert(rnd_state->deck[player][i]!= NULL)
       //     printf("There is no room in hand storage %d \n", hand_size);
        rnd_state->hand[player][i] = card;
    }

    for( i = 0; i< discard_size; i++){
        card = rand()%27; 
     //   assert(rnd_state->deck[player][i]!= NULL)
       //     printf("There is no room in discard storage %d \n", discard_size);
        rnd_state->discard[player][i] = card;   
    }

    return 0;
}

int copyPlayerState(int player, int checker, struct gameState *chk_state){
   
    int i;

    chk_state->handCount[checker] = chk_state->handCount[player];
    chk_state->discardCount[checker] = chk_state->discardCount[player];
    chk_state->deckCount[checker] = chk_state->deckCount[player];
    for( i = 0; i< 500; i++){
        chk_state->hand[checker][i] = chk_state->hand[player][i];
        chk_state->deck[checker][i] = chk_state->deck[player][i]; 
        chk_state->discard[checker][i] = chk_state->discard[player][i];   
    }

    chk_state->numActions = 1;
    return 0; 
};


void checkNewAction( int delta, struct gameState *act_state){
    delta++;
    if( act_state->numActions == delta){
        printf("SUCCESS: Action increased by %d\n", delta-1);
      
    }else{
        printf("FAILED: Actions increased by %d\n", act_state->numActions - 1);
    }
}


void checkDrawCard(int player, int checker, struct gameState *draw_state){
    int in_deck_count = draw_state->deckCount[checker];
    int in_hand_count = draw_state->handCount[checker];
    int top_card = draw_state->deck[checker][in_deck_count -1];
    int out_deck_count = draw_state->deckCount[player];
    int out_hand_count = draw_state->handCount[player];
    int in_dicard_count = draw_state->discardCount[checker];
    if(in_deck_count == 0 && out_deck_count == --in_dicard_count){
        printf("PASSED: deck count before draw %d, deck count after draw %d\n", in_deck_count, out_deck_count);        
    }else if(out_deck_count == in_deck_count -1 ){
        printf("PASSED: deck count before draw %d, deck count after draw %d\n", in_deck_count, out_deck_count);    
    }else{
        printf("FAILED: deck count before draw %d, deck count after draw %d\n", in_deck_count, out_deck_count);    
        
    }
    

    if(out_hand_count == in_hand_count +1 ){
        printf("PASSED: hand count before draw %d, hand count after draw %d\n", in_hand_count, out_hand_count);    
    }else{
        printf("FAILED: hand count before draw %d, hand count after draw %d\n", in_hand_count, out_hand_count);    
    }


    if(top_card == draw_state->hand[player][out_hand_count - 1]){
        printf("PASSED: card successfully drawn deck to hand\n");
    }else{
        printf("FAILED: card not successfully drawn deck to hand\n");
    }

}
