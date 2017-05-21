//============================================================================
// Name        : IART.cpp
// Author      : Catarina Ramos, Ines Gomes and Mario Fernandes
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <sstream>

#include "Database.h"
#include "University.h"
#include "Genetic.h"
#include "SimulatedAnnealing.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;


int main(int argc, char* argv[]) {



    //Qt setup
    QApplication a(argc, argv);
    MainWindow w;

    University * university = w.loadUniversity();

    Epoch *e = university->getEpochs()[0];
    Genetic g(e,false,50,80);
    g.run();
    GStatistics *s = g.getStatistics();
    cout << s->displayStatistics()<< endl;

    //w.show();

    /*return a.exec();*/
}
