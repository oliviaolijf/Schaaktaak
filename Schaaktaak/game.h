//  Student: Olivia Wuyts
//  Rolnummer: 20225396
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#ifndef SCHAKEN_GAME_H
#define SCHAKEN_GAME_H

#include "SchaakStuk.h"
#include <map>
using namespace std;

class Game {

public:
    Game();
    ~Game();

    bool move(SchaakStuk* s,int r, int k); // Verplaats stuk s naar rij r en kolom k

    bool schaak(zw kleur);
    bool schaakmat(zw kleur);
    bool pat(zw kleur);
    void setStartBord();

    SchaakStuk* getPiece(int r, int k);
    void setPiece(int r, int k, SchaakStuk* s);
    pair<int,int> getCoordinaat(SchaakStuk*);
    map<pair<int,int>,SchaakStuk*> getBord() {return speelbord;}
    void setRound(int k) {round = k;}
    int getRound() {return round;}
    SchaakStuk* findKing(zw kleur);


private:
    // Hier zet jij jouw datastructuur neer om het bord te bewaren ...
    map <pair<int,int>, SchaakStuk*> speelbord;
    int round;
};


#endif //SCHAKEN_GAME_H
