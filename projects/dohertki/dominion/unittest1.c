//unittest1.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>





int main(){

  int cost;
  int i;
  printf("Unit test 1 \n");
  for(i=0; i <= 20; i++){
    cost = 0;
    cost = getCost(i);

    switch( i ){
      case curse:
        if( cost == 0){
          printf("PASSED- Curse cost %d copper.\n", cost);
        }else{
          printf("FAILED- Curse cost %d copper incorrect. \n", cost);
        }
        break;

    //Estate cost 2 copper
      case estate:
        if( cost == 2){
          printf("PASSED- Estate cost %d copper. \n", cost);
        }else{
          printf("FAILED- Estate cost %d copper incorrect. \n", cost);
        }
        break;

      //Duchy costs 5 copper
      case duchy:
        if( cost == 5){
          printf("PASSED- Duchy cost %d copper. \n", cost);
        }else{
          printf("FAILED- Duchy cost %d copper incorrect. \n", cost); }
               break;

      //Province costs 8 copper
      case province:
        if( cost == 8){
          printf("PASSED- Province cost %d copper. \n", cost);
        }else{
          printf("FAILED- Province cost %d copper incorrect. \n", cost);
        }
        break;

      //copper cost 0 copper
      case copper:
        if( cost == 0){
          printf("PASSED- Copper cost %d copper. \n", cost);
        }else{
          printf("FAILED- Copper cost %d copper incorrect. \n", cost);
        }
        break;

    
      //Silver costs 3 copper
      case silver:
        if( cost == 3){
          printf("PASSED- Silver cost %d copper. \n", cost);
        }else{
          printf("FAILED- Silver cost %d copper incorrect. \n", cost);
        }
        break;

    
      //Gold cost 6 copper
      case gold:
        if( cost == 6){
          printf("PASSED- Gold cost %d copper. \n", cost);
        }else{
          printf("FAILED- Gold cost %d copper incorrect. \n", cost);
        }
        break;

    
      //Adventurer cost 6 copper
      case adventurer:
        if( cost == 6){
          printf("PASSED- Adventurer cost %d copper. \n", cost);
        }else{
          printf("FAILED- Adventurer cost %d copper incorrect. \n", cost);
        }
        break;

    
      //Council Room cost 5 copper
      case council_room:
        if( cost == 5){
          printf("PASSED- Council Room cost %d copper. \n", cost);
        }else{
          printf("FAILED- Council Room cost %d copper incorrect. \n", cost);
        }
        break;

    
      //Feast cost 4 copper
      case feast:
        if( cost == 4){
          printf("PASSED- Feast cost %d copper. \n", cost);
        }else{
          printf("FAILED- Feast cost %d copper incorrect. \n", cost);
        }
        break;

      //Gardens cost 4 copper
      case gardens:
        if( cost == 4){
          printf("PASSED- Gardens cost %d copper. \n", cost);
        }else{
          printf("FAILED- Gardens cost %d copper incorrect. \n", cost);
        }
        break;

      //Mine costs 5 copper
      case mine:
        if( cost == 5){
          printf("PASSED- Mine cost %d copper. \n", cost);
        }else{    
          printf("FAILED- Mine cost %d copper incorrect. \n", cost);
        }
        break;

      //Remodel cost 4 copper
      case remodel:
        if( cost == 4){
          printf("PASSED- Remodel cost %d copper. \n", cost);
        }else{
          printf("FAILED- Remodel cost %d copper incorrect. \n", cost);
        }
        break;

      //Smithy costs 4 copper
      case smithy:
        if( cost == 4){
          printf("PASSED- Smithy cost %d copper. \n", cost);
        }else{
          printf("FAILED- Smithy cost %d copper incorrect. \n", cost);
        }
        break;

      //Village cost 3 copper
      case village:
        if( cost == 3){
          printf("PASSED- Village cost %d copper. \n", cost);
        }else{
          printf("FAILED- Village cost %d copper incorrect. \n", cost);
        }
        break;

      
      //Baron cost 4 copper
      case baron:
        if( cost == 4){
          printf("PASSED- Baron cost %d copper. \n", cost);
        }else{
          printf("FAILED- Baron cost %d copper incorrect. \n", cost);
        }
        break;

      //Great Hall costs 3 copper
      case great_hall:
        if( cost == 3){
          printf("PASSED- Great Hall cost %d copper. \n", cost);
        }else{
          printf("FAILED- Great Hall cost %d copper incorrect. \n", cost);
        }
        break;

      //Minion costs 5 copper
      case minion:
        if( cost == 5){
          printf("PASSED- Minion cost %d copper. \n", cost);
        }else{
          printf("FAILED- Minion cost %d copper incorrect. \n", cost);
        }
        break;

      //Steward costs 3 copper
      case steward:
        if( cost == 3){
          printf("PASSED- Steward cost %d copper. \n", cost);
        }else{
          printf("FAILED- Steward cost %d copper incorrect. \n", cost);
        }
        break;

      //Tribute costs 5 copper
      case tribute:
        if( cost == 5){
          printf("PASSED- Tribute cost %d copper. \n", cost);
        }else{
          printf("FAILED- Tribute cost %d copper incorrect. \n", cost);
        }
        break;

      //Ambassador cost 3 copper
      case ambassador:
        if( cost == 3){
          printf("PASSED- Ambassador cost %d copper. \n", cost);
        }else{
          printf("FAILED- Ambassador cost %d copper incorrect. \n", cost);
        }
        break;

      //Cutpurse cost 4 copper
      case cutpurse:
        if( cost == 4){
          printf("PASSED- Cutpurse cost %d copper. \n", cost);
        }else{
          printf("FAILED- Cutpurse cost %d copper incorrect. \n", cost);
        }
        break;

      //Embargo costs 2 copper
      case embargo: 
        if( cost == 2){
          printf("PASSED- Embargo cost %d copper. \n", cost);
        }else{
          printf("FAILED- Embargo cost %d copper incorrect. \n", cost);
        }
        break;


      //Outpost costs 5 copper
      case outpost:
        if( cost == 5){
          printf("PASSED- Outpost cost %d copper. \n", cost);
        }else{    
          printf("FAILED- Outpost cost %d copper incorrect. \n", cost);
        }
        break;

      //Salvager cost 4 copper
      case salvager:
        if( cost == 4){
          printf("PASSED- Salvager cost %d copper. \n", cost);
        }else{
          printf("FAILED- Salvager cost %d copper incorrect. \n", cost);
        }
        break;

      //Sea Hag costs 4 copper
      case sea_hag:
        if( cost == 4){
          printf("PASSED- Sea Hag cost %d copper. \n", cost);
        }else{
          printf("FAILED- Sea Hag cost %d copper incorrect. \n", cost);
        }
        break;
   
      //Treasure Map cost 2 copper
      case treasure_map:
        if( cost == 4){
          printf("PASSED- Treasure Map cost %d copper. \n", cost);
        }else{
          printf("FAILED- Treasure Map cost %d copper incorrect. \n", cost);
        }
        break;

    }

    
      


  }
  return 0;
}


































     





