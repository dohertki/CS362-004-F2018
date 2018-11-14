#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "rngs.h"
#include "interface.h"
#include "dominion.h"



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
