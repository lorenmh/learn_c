#include "deck.h"
#include "card.h"
#include "randomf.h"

const int NUM_SUITS = 4;
const int NUM_VALUES = 13;
constexpr int DECKSIZE = NUM_SUITS * NUM_VALUES;

Deck::Deck() {
  index = 0;

  for (int i = 0; i < DECKSIZE; i++) {
    cards[ i ].setSuit( i % NUM_SUITS );
    cards[ i ].setValue( i % NUM_VALUES );
  }
}

void Deck::shuffle() {
  index = 0;

  for (int i = 0; i < DECKSIZE; i++) {
    // swapIndex is a random int between i and len
    int swapIndex = ((int)(randomf() * (DECKSIZE - i))) + i;
    Card swap = cards[ i ];
    cards[ i ] = cards[ swapIndex ];
    cards[ swapIndex ] = swap;
  }
}

Card* Deck::nextCard() {
  if ( index >= DECKSIZE ) { return nullptr; }
  return &cards[ index++ ];
}
