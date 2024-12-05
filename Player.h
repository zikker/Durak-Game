#include "Deck.h"
using namespace std;
class Player{
public:
    static vector<int> valid_rangs;
    vector<Card> cards_in_defense;
    static int counter_of_players;
    const static unsigned MAX_CARDS;
    short current_cards;
    int last_bitted_card;
    bool is_take_cards;
    bool is_winner;
    int number_of_player;
    Player(Deck &deck);
    void take_cards(vector<Card> &cards_to_attack);
    void beat_card(vector<Card> &cards_to_attack);
    bool throw_card(vector<Card> &cards_to_attack);
    void print_cards();
    void print_valid_rangs();
    bool refill(Deck &deck);
    bool operator==(const Player &other);
private:
    vector<Card> cards;
};