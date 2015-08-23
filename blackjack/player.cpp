#include <iostream>
#include "deck.h"
#include "card.h"
#include "player.h"

#define DEFAULT_HAND_SIZE 8

Player::Player(void) {
  // vector.reserve to make sure that the vector isn't resizing too much
  hand.reserve( DEFAULT_HAND_SIZE );
}

void Player::clearHand(void) {
  // set hand to a new card vector (initialized with '()')
  hand = std::vector<Card *>();
  // reserve the size again
  hand.reserve( DEFAULT_HAND_SIZE );
}


void Player::giveCard(Card *card) {
  // push the new card into the vector
  hand.push_back( card );
}

void Player::printHand(void) {
  int len = hand.size();

  // if len == 0, do not print the hand
  if (len) {
    for (int i = 0; i < len; i++) {
      std::cout << (* hand[ i ]).toString() ;
      // add commas between the cards
      if ( i != (len - 1) ) {
        std::cout << ", " ;
      }
    }
    std::cout << '\n' ;
  }
}
