#ifndef CRICKET_H
#define CRICKET_H
#include <iostream>
using namespace std;    //cant declare string data members without including <iostream> and using namespace std

class Team{
public:
    float totalplayers,score; //declaring public data members because we dont have to use it in main,they are only used as "Composition" in our main Play class
    string name;
    float rrP1,rrP2,rrP3; //runrate of players
    Team();
    Team(string);
};

class Play{
private:
    int balls;
    bool user,comp;
    Team Comp,User,winningteam,loosingteam;
public:
    Play();
    void Toss();
    void UserInning();
    void CompInning();
    void secondinning();
    void summary();

};

#endif