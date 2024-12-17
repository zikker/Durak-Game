#include "Game.h"
Game::Game(int k_players){
    cards_to_attack = {};
    pointer_to_player = 0;
    this->k_players = k_players;
    for(int i = 0; i < k_players; i++){
        Player player(deck);
        players.push_back(player);
    }
    trump = deck.back_card();
    move();

}

bool Game::end_game(){
    return (players.size() == 1);
}

// 0 1 2 3
// 1 2 3 4
void Game::move(){
    
    int k_not_passed_players = 0;
    while(!end_game()){
        //attack
        cout << "trump card = ";
        trump.print_card();
        cout << endl;
        Player *activePlayer = &players[pointer_to_player];
        Player *defendingPlayer = &players[(pointer_to_player + 1) % k_players];
        cout << "Move of Player " << (*activePlayer).number_of_player << endl;
        (*activePlayer).throw_card(cards_to_attack);
        cout << endl;
        cout << "trump card = ";
        trump.print_card();
        cout << "Defend of Player " << (*defendingPlayer).number_of_player << endl;
        (*defendingPlayer).beat_card(cards_to_attack);
        cout << endl;
        
        //fixing cards
        do
        {  
            k_not_passed_players = 0;
            for (int i = (pointer_to_player + 2) % k_players; i != (pointer_to_player + 1) % k_players; i = (i + 1) % k_players){
                cout << "Player " << players[i].number_of_player << " fixing with cards" << endl;
                cout << "trump card = "; 
                trump.print_card();
                cout << "valid rangs: " << endl;
                players[i].print_valid_rangs();
                k_not_passed_players += players[i].throw_card(cards_to_attack);
                cout << endl;
            }
            if(k_not_passed_players > 0){
                cout << "Defend of Player " << (*defendingPlayer).number_of_player << endl;
                cout << "trump card = ";
                trump.print_card();
                (*defendingPlayer).beat_card(cards_to_attack);
                cout << endl;
            }
        } while (k_not_passed_players > 0 and (*defendingPlayer).current_cards > 0);

        if((*defendingPlayer).is_take_cards){
            (*defendingPlayer).take_cards(cards_to_attack);
        }

        //refill
        bool is_refilled;
        int start_index = (pointer_to_player + 2) % k_players;
        int end_index = (pointer_to_player + 1) % k_players;
        cout << "Refill all players" << endl;
        for(int i = start_index; ; i = (i + 1) % k_players){
            is_refilled = players[i].refill(deck);
            if(!is_refilled and players[i].current_cards == 0){
                players[i].is_winner = true;
                cout << "Player " << i + 1 << " wins" << endl;
                k_players--;
                players.erase(find(players.begin(), players.end(), players[i]));
                if(i < end_index){
                    end_index--;
                }
                i = (i - 1) % k_players;
            }
            if(i == end_index){
                break;
            }
        }
        cards_to_attack.clear();
        if((*defendingPlayer).is_take_cards){
            pointer_to_player = (pointer_to_player + 2) % k_players;
        }
        else{
            pointer_to_player = (pointer_to_player + 1) % k_players;
        }
        (*defendingPlayer).is_take_cards = false;

        cout << "next round " << endl << endl;
    }
    
    
    



}

 


