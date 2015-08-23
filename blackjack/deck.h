#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck {
  private:
    Card cards[52];
    int index;
  public:
    Deck();
    void shuffle();
    Card *nextCard();
};

#endif
