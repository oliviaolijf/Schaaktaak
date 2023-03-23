//  Student:
//  Rolnummer:
//  Opmerkingen: (bvb aanpassingen van de opgave)
//

#include "SchaakStuk.h"
#include "game.h"
#include <iostream>


vector<pair<int, int>> Pion::geldige_zetten(Game &g) {
    auto speelbord = g.getBord();
    auto currentpos = g.getCoordinaat(this);
    int x = currentpos.first, y = currentpos.second;
    vector<pair<int,int>> validmoves;
    if (x == 1 && Pion::getKleur() == zwart){
        pair<int,int> c1 = {currentpos.first+1, currentpos.second};
        if (speelbord[c1] == nullptr) validmoves.push_back(c1);
        pair<int,int> c2 = {currentpos.first+2, currentpos.second};
        if (speelbord[c2]== nullptr)validmoves.push_back(c2);}


    else if (Pion::getKleur() == zwart){
        pair<int,int> c1 = {currentpos.first+1, currentpos.second};
        if (speelbord[c1] == nullptr) validmoves.push_back(c1);}


    else if (x == 6 && Pion::getKleur() == wit){
        pair<int,int> c1 = {currentpos.first-1, currentpos.second};
        if (speelbord[c1]== nullptr)validmoves.push_back(c1);
        pair<int,int> c2 = {currentpos.first-2,currentpos.second};
        if (speelbord[c2]== nullptr)validmoves.push_back(c2);}

    else if (Pion::getKleur() == wit){
        pair<int,int> c1 = {currentpos.first-1, currentpos.second};
        if (speelbord[c1] == nullptr) validmoves.push_back(c1);}
    return validmoves;
} // correct gemaakt

vector<pair<int, int>> Toren::geldige_zetten(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord = g.getBord();
    int y = curpos.second, x = curpos.first;
    vector<pair<int,int>> validmoves;
    for (int a = 0; a < 8; a++){
        if (a != x){
        pair<int,int> c = {a,y};
        if (speelbord[c] == nullptr)
            validmoves.push_back(c);
        else{break;}
        }}

    for (int b = 0; b < 8; b++){
        if (b!=y){
        pair<int,int> c = {x, b};
        if (speelbord[c] == nullptr) validmoves.push_back(c);
        else {return validmoves;}}}
    return validmoves;
} // correct gemaakt

vector<pair<int, int>> Loper::geldige_zetten(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord = g.getBord();
    int x = curpos.first, y = curpos.second;
    vector<pair<int, int>> validmoves;
    for (int k = 1; k <= 7; k++){
        int a = x-k, b = y-k;
        if (a >= 0 && b >= 0 && speelbord[{a,b}] == nullptr) {
            validmoves.push_back({a,b});}
        else {break;}}

    for (int k = 1; k <= 7; k++){
        int c = x+k, d = y-k;
        if (c <= 7 && d >= 0 && speelbord[{c,d}] == nullptr) {
            validmoves.push_back({c,d});}
        else {break;}}

    for (int k = 1; k <= 7; k++){
        int e = x-k, f = y+k;
        if (e >= 0 && f <= 7 && speelbord[{e,f}] == nullptr) {
            validmoves.push_back({e,f});}
        else {break;}}

    for (int k = 1; k <= 7; k++){
        int g = x+k, h = y+k;
        if (g <= 7 && h <= 7 && speelbord[{g,h}]== nullptr) {
            validmoves.push_back({g,h});}
        else{break;}}
    return validmoves;
} // correct gemaakt

vector<pair<int, int>> Koningin::geldige_zetten(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord = g.getBord();
    int y = curpos.second, x = curpos.first;
    vector<pair<int,int>> validmoves;
    //rechte bewegingen aka toren code gekopieerd
    for (int a = 0; a < 8; a++){
        if (a!=x){
        pair<int,int> c = {a,y};
            if (speelbord[c] == nullptr) validmoves.push_back(c);
            else break;}
    }

    for (int b = 0; b<8 ; b++){
        if (b != y){
        pair<int,int> c = {x, b};
        if (speelbord[c] == nullptr) validmoves.push_back(c);
        else break;}
    }

    // schuine bewegingen aka loper code gekopieerd
    for (int k = 1; k <= 7; k++){
        int a = x-k, b = y-k;
        if (a >= 0 && b >= 0 && speelbord[{a,b}] == nullptr) {
            validmoves.push_back({a,b});}
        else {break;}}

    for (int k = 1; k <= 7; k++){
        int c = x+k, d = y-k;
        if (c <= 7 && d >= 0 && speelbord[{c,d}] == nullptr) {
            validmoves.push_back({c,d});}
        else {break;}}

    for (int k = 1; k <= 7; k++){
        int e = x-k, f = y+k;
        if (e >= 0 && f <= 7 && speelbord[{e,f}]) {
            validmoves.push_back({e,f});}
        else {break;}}

    for (int k = 1; k <= 7; k++){
        int g = x+k, h = y+k;
        if (g <= 7 && h <= 7 && speelbord[{g,h}]== nullptr) {
            validmoves.push_back({g,h});}
        else{break;}}

    return validmoves;
} // correct gemaakt

vector<pair<int, int>> Paard::geldige_zetten(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord =  g.getBord();
    int x = curpos.first, y=curpos.second;
    vector<pair<int,int>> validmoves;
    vector<pair<int,int>> moves;
    moves.push_back({x-2,y-1});
    moves.push_back({x-1, y-2});
    moves.push_back({x+1,y-2});
    moves.push_back({x+2, y-1});
    moves.push_back({x+2, y+1});
    moves.push_back({x+1, y+2});
    moves.push_back({x-1, y+2});
    moves.push_back({x-2, y+1});
    for (auto i: moves){
        if (i.first <= 7 && i.first >= 0 && i.second <= 7 && i.second >= 0 && speelbord[i] == nullptr){
            validmoves.push_back(i);}
    }
    return validmoves;
} // correct gemaakt

vector<pair<int, int>> Koning::geldige_zetten(Game &g) {
    auto curpos = g.getCoordinaat(this);
    int x  =curpos.first, y= curpos.second;
    auto bord = g.getBord();
    vector<pair<int,int>> moves;
    vector<pair<int,int>> validmoves;
    moves.push_back({x+1,y});
    moves.push_back({x-1, y});
    moves.push_back({x,y-1});
    moves.push_back({x, y+1});
    moves.push_back({x+1, y+1});
    moves.push_back({x-1, y+1});
    moves.push_back({x+1, y-1});
    moves.push_back({x-1, y-1});
    int c  = 0;
    for (auto i: moves){
        if (i.first <= 7 && i.first >= 0 && i.second <= 7 && i.second >= 0 && bord[i] == nullptr){
            validmoves.push_back(i);}
    }
    return validmoves;
} // correct gemaakt


vector<pair<int, int>> Pion::slagen(Game &g) {
    auto kleur = Pion::getKleur();
    auto speelbord = g.getBord();
    auto curpos = g.getCoordinaat(this);
    int x = curpos.first, y= curpos.second;
    vector<pair<int,int>> slagen;
    if (kleur == zwart){
        pair<int,int> c1 = {x+1, y-1};
        if (speelbord[c1] != nullptr) slagen.push_back(c1);
        pair<int,int> c2 = {x+1, y+1};
        if (speelbord[c2] != nullptr) slagen.push_back(c2);
    }
    else if (kleur == wit){
        pair<int,int> c1 = {x-1, y+1};
        if (speelbord[c1] != nullptr) slagen.push_back(c1);
        pair<int,int> c2 = {x-1,y-1};
        if (speelbord[c2] != nullptr) slagen.push_back(c2);
    }
    return slagen;
}

vector<pair<int, int>> Toren::slagen(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord = g.getBord();
    int y = curpos.second, x = curpos.first;
    vector<pair<int,int>> slagen;

    for (int a = 0; a < 8; a++) {
        if (a != x) {
            pair<int, int> c = {a, y};
            if (speelbord[c] != nullptr) {
                slagen.push_back(c);
                break;
            }
        }
    }
    for (int b = 0; b < 8; b++){
        if (b!=y){
            pair<int,int> c = {x, b};
            if (speelbord[c] != nullptr) {
                slagen.push_back(c);
                return slagen;}
        }
    }
    return slagen;
}

vector<pair<int,int>> Loper::slagen(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord = g.getBord();
    int x = curpos.first, y = curpos.second;
    vector<pair<int, int>> slagen;

    for (int k = 1; k <= 7; k++){
        int a = x-k, b = y-k;
        if (a >= 0 && b >= 0 && speelbord[{a,b}] != nullptr){
            slagen.push_back({a,b});
            break;
        }
    }
    for (int k = 1; k <= 7; k++){
        int c = x+k, d = y-k;
        if (c <= 7 && d >= 0 && speelbord[{c,d}] != nullptr) {
            slagen.push_back({c,d});
            break;}
    }
    for (int k = 1; k <= 7; k++){
        int e = x-k, f = y+k;
        if (e >= 0 && f <= 7 && speelbord[{e,f}] != nullptr) {
            slagen.push_back({e,f});
            break;}
    }
    for (int k = 1; k <= 7; k++){
        int g = x+k, h = y+k;
        if (g <= 7 && h <= 7 && speelbord[{g,h}] != nullptr) {
            slagen.push_back({g,h});
            break;}
    }
    return slagen;
}

vector<pair<int, int>> Koningin::slagen(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord = g.getBord();
    int y = curpos.second, x = curpos.first;
    vector<pair<int,int>> slagen;

// rechte slagen aka toren code opnieuw
    for (int a = 0; a < 8; a++) {
        if (a != x) {
            pair<int, int> c = {a, y};
            if (speelbord[c] != nullptr) {
                slagen.push_back(c);
                break;
            }
        }
    }
    for (int b = 0; b < 8; b++){
        if (b!=y){
            pair<int,int> c = {x, b};
            if (speelbord[c] != nullptr) {
                slagen.push_back(c);
                return slagen;}
        }
    }
    // schuine slagen aka loper code
    for (int k = 1; k <= 7; k++){
    int a = x-k, b = y-k;
    if (a >= 0 && b >= 0 && speelbord[{a,b}] != nullptr){
    slagen.push_back({a,b});
    break;}
    }

    for (int k = 1; k <= 7; k++){
    int c = x+k, d = y-k;
    if (c <= 7 && d >= 0 && speelbord[{c,d}] != nullptr) {
    slagen.push_back({c,d});
    break;}
    }
    for (int k = 1; k <= 7; k++){
    int e = x-k, f = y+k;
    if (e >= 0 && f <= 7 && speelbord[{e,f}] != nullptr) {
    slagen.push_back({e,f});
    break;}
    }
    for (int k = 1; k <= 7; k++){
    int g = x+k, h = y+k;
    if (g <= 7 && h <= 7 && speelbord[{g,h}] != nullptr) {
    slagen.push_back({g,h});
    break;}
    }
return slagen;}

vector<pair<int, int>> Paard::slagen(Game &g) {
    auto curpos = g.getCoordinaat(this);
    auto speelbord =  g.getBord();
    int x = curpos.first, y=curpos.second;
    vector<pair<int,int>> slagen;
    vector<pair<int,int>> moves;
    moves.push_back({x-2,y-1});
    moves.push_back({x-1, y-2});
    moves.push_back({x+1,y-2});
    moves.push_back({x+2, y-1});
    moves.push_back({x+2, y+1});
    moves.push_back({x+1, y+2});
    moves.push_back({x-1, y+2});
    moves.push_back({x-2, y+1});
    for (auto i: moves){
        if (i.first <= 7 && i.first >= 0 && i.second <= 7 && i.second >= 0 && speelbord[i] != nullptr){
            slagen.push_back(i);}
    }
    return slagen;
}

vector<pair<int, int>> Koning::slagen(Game &g) {
    auto curpos = g.getCoordinaat(this);
    int x  =curpos.first, y= curpos.second;
    auto bord = g.getBord();
    vector<pair<int,int>> moves;
    vector<pair<int,int>> slagen;
    moves.push_back({x+1,y});
    moves.push_back({x-1, y});
    moves.push_back({x,y-1});
    moves.push_back({x, y+1});
    moves.push_back({x+1, y+1});
    moves.push_back({x-1, y+1});
    moves.push_back({x+1, y-1});
    moves.push_back({x-1, y-1});

    for (auto i: moves){
        if (i.first <= 7 && i.first >= 0 && i.second <= 7 && i.second >= 0 && bord[i] != nullptr){
            slagen.push_back(i);}
    }
    return slagen;
}
