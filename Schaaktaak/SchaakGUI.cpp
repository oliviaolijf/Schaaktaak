//
// Created by toonc on 12/17/2021.
//

#include "SchaakGUI.h"
#include "guicode/message.h"
#include "guicode/fileIO.h"
#include <iostream>

// Constructor
SchaakGUI::SchaakGUI():ChessWindow(nullptr) {
    update();
    clickcount = 0;
}

SchaakStuk* p; // ja uhm ugly dat dit gwn hier staan but idc het werkt nu :)
int x1,y1;
zw kleur;
QString foutbootschap = "Dit is een ongeldige zet.";
QString foutekleurwit = "Het geselecteerde stuk is niet de juiste kleur, zwart is aan de beurt!";
QString foutkleurzwart = "Het geselecteerde stuk is niet de juiste kleur, wit is aan de beurt!";
QString schaak = "Schaak!";
void SchaakGUI::clicked(int r, int k) {
    clickcount++;
    auto zet = g.getRound();
    if(clickcount == 1) {
        x1 = r;
        y1 = k;
        p = g.getPiece(r, k);
        kleur = p->getKleur();
        if (zet % 2 == 0 && p->getKleur() == wit) {
            setTileSelect(r, k, true);
            auto greg = g.findKing(wit);
            if (greg != nullptr) cout << greg << endl;
        }
        else if (zet % 2 != 0 && p->getKleur() == wit) {
            message(foutekleurwit);
            clickcount = 0;
        }
        else if (zet%2 != 0 && p-> getKleur() == zwart) {setTileSelect(r, k, true);}
        else if (zet%2 == 0 && p->getKleur() == zwart){
            message(foutkleurzwart);
            clickcount = 0;}

    }
    else if (clickcount == 2){
        if (!g.move(p,r,k)){
            message(foutbootschap);
            setTileSelect(x1,y1,false);
            clickcount = 0;}
        else{
            g.move(p,r,k);
            setTileSelect(x1,y1,false);
            update();
            clickcount = 0;
            auto mlem = g.getRound();
            mlem++;
            g.setRound(mlem);
            }
        }

}


void SchaakGUI::newGame()
{}


void SchaakGUI::save() {
    QFile file;
    if (openFileToWrite(file)) {
        QDataStream out(&file);
        out << QString("Rb") << QString("Hb") << QString("Bb") << QString("Qb") << QString("Kb") << QString("Bb") << QString("Hb") << QString("Rb");
        for  (int i=0;i<8;i++) {
            out << QString("Pb");
        }
        for  (int r=3;r<7;r++) {
            for (int k=0;k<8;k++) {
                out << QString(".");
            }
        }
        for  (int i=0;i<8;i++) {
            out << QString("Pw");
        }
        out << QString("Rw") << QString("Hw") << QString("Bw") << QString("Qw") << QString("Kw") << QString("Bw") << QString("Hw") << QString("Rw");
    }
}

void SchaakGUI::open() {
    QFile file;
    if (openFileToRead(file)) {
        try {
            QDataStream in(&file);
            QString debugstring;
            for (int r=0;r<8;r++) {
                for (int k=0;k<8;k++) {
                    QString piece;
                    in >> piece;
                    debugstring += "\t" + piece;
                    if (in.status()!=QDataStream::Ok) {
                        throw QString("Invalid File Format");
                    }
                }
                debugstring += "\n";
            }
            message(debugstring);
        } catch (QString& Q) {
            message(Q);
        }
    }
    update();
}


void SchaakGUI::undo() {
    message("Je hebt undo gekozen");
}

void SchaakGUI::redo() {}


void SchaakGUI::visualizationChange() {
    QString visstring = QString(displayMoves()?"T":"F")+(displayKills()?"T":"F")+(displayThreats()?"T":"F");
    message(QString("Visualization changed : ")+visstring);
}


// Update de inhoud van de grafische weergave van het schaakbord (scene)
// en maak het consistent met de game state in variabele g.
void SchaakGUI::update() {
    clearBoard();
    int x = 0;
    while (x < 8) {
        for (int y = 0; y < 8; y++) {
            SchaakStuk *ss = g.getPiece(x, y);
            if (ss != nullptr) setItem(x, y, ss);
        }
        x++;}
}





