#include "Deck.h"

const int Deck::NUM_OF_CARDS = 36;

Deck::Deck(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 9; j++){
            Card card(Card::rangs[j], Card::suits[i]);
            deck.push_back(card);
        }
    }
}

void Deck::shuffle(){
    std::random_shuffle(deck.begin(), deck.end());
}

Deck::~Deck(){
    deck.clear();
}