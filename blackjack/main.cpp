#include <iostream>
#include "card.h"
#include "deck.h"

int main( int argc, char *argv[] ) {
  Deck deck;

  for (int i = 0; i < 52; i++) {
    std::cout << deck.nextCard().toString() << '\n';
  }
}
