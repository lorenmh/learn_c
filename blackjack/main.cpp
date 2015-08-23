#include <iostream>
#include <vector>
#include "player.h"
#include "card.h"
#include "deck.h"

int main( int argc, char *argv[] ) {
  Deck deck;

  deck.shuffle();

  Player player;

  player.giveCard( deck.nextCard() );
  player.giveCard( deck.nextCard() );
  player.giveCard( deck.nextCard() );
  player.giveCard( deck.nextCard() );
  player.giveCard( deck.nextCard() );

  player.printHand();
  player.clearHand();

  player.giveCard( deck.nextCard() );
  player.giveCard( deck.nextCard() );

  player.printHand();

  // Card *currentCard;
  // for (int i = 0; i < 156; i++) {
  //   currentCard = deck.nextCard();

  //   if ( currentCard != nullptr ) {
  //     std::cout << (*currentCard).toString() << '\n';
  //   } else {
  //     std::cout << "Out of cards! Shuffling deck.\n";
  //     deck.shuffle();
  //   }
  // }

  

  return 0;
}
