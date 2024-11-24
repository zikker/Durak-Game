#include "Deck.h"
void Deck::shuffle(){
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(deck.begin(), deck.end(), rng);
    trump = deck.back();
}

Deck::Deck(){
    NUM_OF_CARDS = 36;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 9; j++){
            Card card(Card::rangs[j], Card::suits[i]);
            deck.push_back(card);
        }
    }
    shuffle();
}

Card Deck::front_card(){
    auto tmp_card = deck.front();
    deck.pop_front();
    NUM_OF_CARDS--;
    return tmp_card;
}

Card Deck::back_card(){
    return deck.back();
}

void Deck::print_deck(){
    for(int i = 0; i < NUM_OF_CARDS; i++){
        switch (deck[i].rang)
        {
        case 11:
            std::cout << "J";
            break;
        case 12:
            std::cout << "Q";
            break;
        case 13:
            std::cout << "K";
            break;
        case 14:
            std::cout << "A";   
            break;
        default:
            std::cout << deck[i].rang;
            break;
        }
        std::cout << deck[i].suit << '\t';
    }
}

Deck::~Deck(){
    deck.clear();
}