#include "Player.h"


Player::Player(Deck &deck){
    for(current_cards = 0; current_cards < MAX_CARDS; current_cards++){
        cards.push_back(deck.front_card());
    }
}

vector<Card> Player::throw_card(string str_cards){
    for(int i = 0; i < str_cards.length(); i += 2){
        
    }

}

void Player::print_cards(){
    for(auto card : cards){
        switch (card.rang)
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
            std::cout << card.rang;
            break;
        }
        std::cout << card.suit << ' '; 
    }
    cout << endl;
}

