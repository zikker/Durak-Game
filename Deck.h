#pragma once
#include "Card.h"
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

class Deck{
public:
    static const int NUM_OF_CARDS;
    std::vector<Card> deck;
    Deck();
    void shuffle();
    void print_deck();
    ~Deck();
};