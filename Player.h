#include "Deck.h"
using namespace std;
class Player{
public:
    static vector<int> valid_rangs;
    const unsigned MAX_CARDS = 6;
    short current_cards;
    int last_bitted_card;
    bool get_card;
    Player(Deck &deck);
    void take_cards(vector<Card> &cards_to_attack, vector<Card> &cards_in_defense);
    void beat_card(vector<Card> &cards_to_attack);
    void throw_card(vector<Card> &cards_to_attack);
    void print_cards();
private:
    vector<Card> cards;
};