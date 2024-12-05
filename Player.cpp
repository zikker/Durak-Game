#include "Player.h"

vector<int> Player::valid_rangs = vector<int>();
int Player::counter_of_players = 0;
const unsigned Player::MAX_CARDS = 6;
Player::Player(Deck &deck){
    for(current_cards = 0; current_cards < MAX_CARDS; current_cards++){
        cards.push_back(deck.front_card());
    }
    is_take_cards = false;
    last_bitted_card = -1;
    is_winner = false;
    counter_of_players++;
    number_of_player = counter_of_players;
}

bool Player::throw_card(vector<Card> &cards_to_attack){
    print_cards();
    std::cout << "Enter card to attack (format: 6d). To stop enter 'pass'" << endl;
    string str_cards;
    cin >> str_cards;
    bool is_threw_card = false; 
    while (str_cards != string("pass") and cards_to_attack.size() != 6){
        try
        {        
            Card card(str_cards);
            auto finded_card = find(cards.begin(), cards.end(), card);
            if(finded_card == end(cards)){
                throw std::logic_error("Invalid card");
            }
            else{
                if(find(valid_rangs.begin(), valid_rangs.end(), card.rang) != end(valid_rangs) or cards_to_attack.size() == 0){
                    cards.erase(finded_card);
                    current_cards--;
                    print_cards();
                }
                else{
                    throw std::logic_error("Invalid card");
                }
                
            }
                is_threw_card = true;
                valid_rangs.push_back(card.rang);
                cards_to_attack.push_back(card);
        }
        catch(const std::logic_error& e)
        {
            std::cout << e.what() << '\n';
        }
        cin >> str_cards;
    }
    std::cout << "Your move is end" << endl;
    return is_threw_card;
}

void Player::beat_card(vector<Card> &cards_to_attack){
    string temp_str;
    int i = 0;
    for(i = last_bitted_card + 1; i < cards_to_attack.size(); i++){
        if(temp_str == "take" and !is_take_cards){
            is_take_cards = true;
            return;
        }
        else if(is_take_cards){
            return;
        }
        cout << "your cards: ";
        print_cards();
        Card card_to_beat = cards_to_attack[i];
        cout << "Card you need to beat: ";
        card_to_beat.print_card();
        cout << "Enter your card. (to take card enter 'take')" << endl;
        cin >> temp_str;
        try
        {
            Card your_card(temp_str);
            auto finded_card = find(cards.begin(), cards.end(), your_card);
            if(finded_card == end(cards)){
                throw std::logic_error("Invalid card");
            }
            else{
                if(!(your_card > card_to_beat)){
                    throw std::logic_error("Invalid card");
                }
                else{
                    cards_in_defense.push_back(your_card);
                    Player::valid_rangs.push_back(your_card.rang);
                    cards.erase(finded_card);
                    current_cards--;
                    last_bitted_card++;
                    print_cards();
                    continue;
                }
            }
        }
        catch(const std::logic_error& e)
        {
            std::cout << e.what() << '\n';
            i--;
        }
    }
    is_take_cards = false;
}

void Player::take_cards(vector<Card> &cards_to_attack){
    for(auto card : cards_to_attack){
        cards.push_back(card);
        current_cards++;
    }
    for(auto card1 : cards_in_defense){
        cards.push_back(card1);
        current_cards++;
    }
    last_bitted_card = -1;
    cards_to_attack.clear();
    cards_in_defense.clear();
    valid_rangs.clear();
    print_cards();
    is_take_cards = true;

}

bool Player::refill(Deck &deck){
    bool refilled = false;
    for(int i = 0; i < int(MAX_CARDS) - current_cards; i++){
        if(deck.NUM_OF_CARDS > 0){
            cards.push_back(deck.front_card());
            refilled = true;
        }
        else{
            refilled = false;
        }
    }
    current_cards = cards.size();
    last_bitted_card = -1;
    cards_in_defense.clear();
    valid_rangs.clear();
    is_take_cards = false;
    return refilled;
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

void Player::print_valid_rangs(){
    for(auto card : Player::valid_rangs){
        switch (card)
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
            std::cout << card;
            break;
        }
        cout << ' ';
    }
    cout << endl;
}

bool Player::operator==(const Player &other){
    return (number_of_player == other.number_of_player);
}
