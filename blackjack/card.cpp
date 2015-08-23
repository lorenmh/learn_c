#include <iostream>
#include <string>
#include "card.h"

const std::string suits[] = { "S", "H", "D", "C" };

const std::string values[] = {
  "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

Card::Card() {
}

Card::Card(int initialSuit, int initialValue) {
  suit = initialSuit;
  value = initialValue;
}

int Card::getSuit() {
  return suit;
}

int Card::getValue() {
  return value;
}

void Card::setSuit(int newSuit) {
  suit = newSuit;
}

void Card::setValue(int newValue) {
  value = newValue;
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
