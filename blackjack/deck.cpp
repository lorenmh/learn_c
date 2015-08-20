#include "deck.h"
#include "card.h"

Deck::Deck() {
  index = 0;

  for (int i = 0; i < 52; i++) {
    cards[ i ].setSuit( i % 4 );
    cards[ i ].setValue( i % 13 );
  }
}

Card Deck::nextCard() {
  return cards[ index++ ];
}
