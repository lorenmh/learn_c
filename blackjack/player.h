#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "card.h"

class Player {
  private:
    std::vector<Card *> hand;
  public:
    Player(void);
    void clearHand(void);
    void giveCard(Card *);
    void printHand(void); 
};


#endif
