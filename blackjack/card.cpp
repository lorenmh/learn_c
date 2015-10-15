#include <iostream>
#include <string>
#include "card.h"

const int NUM_SUITS = 4;
const int NUM_VALUES = 13;

const std::string suits[] = { "S", "H", "D", "C" };

const std::string values[] = {
  "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

Card::Card() {
}

Card::Card(int index) {
  index = index;
  suit = ( index % NUM_SUITS );
  value = ( index % NUM_VALUES );
}

int Card::getIndex() {
  return index;
}

int Card::getSuit() {
  return suit;
}

int Card::getValue() {
  return value;
}

void Card::setIndex(int newIndex) {
  index = newIndex;
}

std::string Card::getSuitString() {
  return suits[ suit ];
}

std::string Card::getValueString() {
  return values[ value ];
}

std::string Card::toString() {
  return '[' + getValueString() + ' ' + getSuitString() + ']';
}
