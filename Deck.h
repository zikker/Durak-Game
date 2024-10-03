#pragma once
#include "Card.h"
#include <vector>
#include <algorithm>

class Deck{
public:
    static const int NUM_OF_CARDS;
    std::vector<Card> deck;
    Deck();
    void shuffle();
    ~Deck();
};