//  Student:
//  Rolnummer:
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "game.h"
#include <iostream>

Game::Game() {
    setStartBord();
    setRound(0);
    }

Game::~Game() {}

// Zet het bord klaar; voeg de stukken op de jusite plaats toe
void Game::setStartBord() {
    round = 0;
    // Zwarte stukken klaarzetten
    SchaakStuk* p0z = new Pion(zwart);
    SchaakStuk* p1z = new Pion(zwart);
    SchaakStuk* p2z = new Pion(zwart);
    SchaakStuk* p3z = new Pion(zwart);
    SchaakStuk* p4z = new Pion(zwart);
    SchaakStuk* p5z = new Pion(zwart);
    SchaakStuk* p6z = new Pion(zwart);
    SchaakStuk* p7z = new Pion(zwart);

    SchaakStuk* t1z = new Toren(zwart);
    SchaakStuk* t2z = new Toren(zwart);
    SchaakStuk* pa1z = new Paard(zwart);
    SchaakStuk* pa2z = new Paard(zwart);
    SchaakStuk* l1z = new Loper(zwart);
    SchaakStuk* l2z = new Loper(zwart);
    SchaakStuk* kz = new Koning(zwart);
    SchaakStuk* qz = new Koningin(zwart);

    setPiece(0,0, t1z);
    setPiece(0,1, pa1z);
    setPiece(0,2,l1z);
    setPiece(0,3,kz);
    setPiece(0,4,qz);
    setPiece(0,5,l2z);
    setPiece(0,6,pa2z);
    setPiece(0,7,t2z);

    setPiece(1,0,p0z);
    setPiece(1,1,p1z);
    setPiece(1,2,p2z);
    setPiece(1,3,p3z);
    setPiece(1,4,p4z);
    setPiece(1,5,p5z);
    setPiece(1,6,p6z);
    setPiece(1,7,p7z);

    // Witte stukken klaarzetten
    SchaakStuk* p0w = new Pion(wit);
    SchaakStuk* p1w = new Pion(wit);
    SchaakStuk* p2w = new Pion(wit);
    SchaakStuk* p3w = new Pion(wit);
    SchaakStuk* p4w = new Pion(wit);
    SchaakStuk* p5w = new Pion(wit);
    SchaakStuk* p6w = new Pion(wit);
    SchaakStuk* p7w = new Pion(wit);

    SchaakStuk* t1w = new Toren(wit);
    SchaakStuk* t2w = new Toren(wit);
    SchaakStuk* pa1w = new Paard(wit);
    SchaakStuk* pa2w = new Paard(wit);
    SchaakStuk* l1w = new Loper(wit);
    SchaakStuk* l2w = new Loper(wit);
    SchaakStuk* kw = new Koning(wit);
    SchaakStuk* qw = new Koningin(wit);

    setPiece(7,0, t1w);
    setPiece(7,1, pa1w);
    setPiece(7,2,l1w);
    setPiece(7,3,kw);
    setPiece(7,4,qw);
    setPiece(7,5,l2w);
    setPiece(7,6,pa2w);
    setPiece(7,7,t2w);

    setPiece(6,0,p0w);
    setPiece(6,1,p1w);
    setPiece(6,2,p2w);
    setPiece(6,3,p3w);
    setPiece(6,4,p4w);
    setPiece(6,5,p5w);
    setPiece(6,6,p6w);
    setPiece(6,7,p7w);

}

// Verplaats stuk s naar positie (r,k)
// Als deze move niet mogelijk is, wordt false teruggegeven
// en verandert er niets aan het schaakbord.
// Anders wordt de move uitgevoerd en wordt true teruggegeven
bool Game::move(SchaakStuk* s, int r, int k) {
    auto validmoves = s->geldige_zetten(*this);
    auto slagen = s->slagen(*this);
    pair<int,int> c = {r,k};
    auto idk = getCoordinaat(s);
    for (auto i:validmoves){
        if (i == c) {
            speelbord[idk] = nullptr;
            setPiece(r,k,s);
            return true;
        }
    }
    for (auto j: slagen){
        if (j == c){
            SchaakStuk*temp = nullptr;
            speelbord[idk] = nullptr;
            setPiece(r,k,temp);
            setPiece(r,k,s);
            return true;
        }
    }
    return false;
}

// Geeft true als kleur schaak staat
bool Game::schaak(zw kleur) {

    return false;
}

// Geeft true als kleur schaakmat staat
bool Game::schaakmat(zw kleur) {
    return false;
}

// Geeft true als kleur pat staat
// (pat = geen geldige zet mogelijk, maar kleur staat niet schaak;
// dit resulteert in een gelijkspel)
bool Game::pat(zw kleur) {
    return false;
}

// Geeft een pointer naar het schaakstuk dat op rij r, kolom k staat
// Als er geen schaakstuk staat op deze positie, geef nullptr terug
SchaakStuk* Game::getPiece(int r, int k) {
    if (speelbord[{r,k}] != nullptr) return speelbord[{r,k}];
    return nullptr;
}

// Zet het schaakstuk waar s naar verwijst neer op rij r, kolom k.
// Als er al een schaakstuk staat, wordt het overschreven.
// Bewaar in jouw datastructuur de *pointer* naar het schaakstuk,
// niet het schaakstuk zelf.
void Game::setPiece(int r, int k, SchaakStuk* s){
   speelbord[{r,k}] = s;
}

pair<int,int> Game::getCoordinaat(SchaakStuk *s) {
    for (auto const& [key,value] : speelbord){
        if  (value == s){
            return key;}

    }
}

SchaakStuk *Game::findKing(zw kleur) {
    for (auto &i: speelbord){
        if (i.second->isKing() && i.second->getKleur() == kleur){
            auto koning = i.second; return koning;
        }
    }
    return nullptr;
}
