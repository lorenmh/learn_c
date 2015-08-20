#ifndef CARD_H
#define CARD_H
#include <string>

class Card {
  private:
    int suit;
    int value;
  public:
    Card();
    Card(int, int);
    int getSuit();
    int getValue();
    void setSuit(int);
    void setValue(int);
    std::string getSuitString();
    std::string getValueString();
    std::string toString();
};

#endif
