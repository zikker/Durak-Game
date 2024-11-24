#pragma once
#include "Card.h"
#include <iostream>
#include <deque>
#include <random>
#include <vector>
#include <random>
#include <algorithm>

class Deck{
public:
    int NUM_OF_CARDS;
    Card trump;
    Deck();
    Card front_card();
    void print_deck();
    Card back_card();
    ~Deck();
private:
    std::deque<Card> deck;
    void shuffle();
};