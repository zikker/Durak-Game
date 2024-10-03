#include <string>

class Card{
public:
    unsigned short rang;
    std::string suit;
    std::string rangs[9] = {"6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    std::string suits[4] = {"diamonds", "hearts", "clubs", "spades"};
    Card();
    Card(unsigned short, std::string);
    ~Card();

};