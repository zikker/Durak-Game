#include "Player.h"

class Game{
    Deck deck;
    std::vector<Player> players;
    bool end_game();
    void move();
public:
    vector<Card> cards_to_attack;
    Card trump;
    int k_players;
    int pointer_to_player;
    Game(int k_players);
    


};