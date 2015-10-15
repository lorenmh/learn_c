#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
  private:
    int index;
    int suit;
    int value;
  public:
    Card();
    Card(int);
    int getIndex();
    int getSuit();
    int getValue();
    void setIndex(int);
    std::string getSuitString();
    std::string getValueString();
    std::string toString();
};

#endif
