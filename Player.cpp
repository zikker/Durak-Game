#include "Player.h"


Player::Player(Deck deck){
    for(current_cards = 0; current_cards < MAX_CARDS; current_cards++){
        cards.push_back(deck.front_card());
    }
}

