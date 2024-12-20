#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Card{
public:
    static std::string trump_suit;
    unsigned short rang;
    std::string suit;
    static unsigned short rangs[9];
    static std::string suits[4];
    Card();
    Card(unsigned short, std::string);
    Card(std::string);
    bool operator>(const Card &card);
    //bool operator<(const Card &card);
    bool operator==(const Card &card);
    void print_card();
    ~Card();


};