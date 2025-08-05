#include <iostream>

#include "Time.h"


void dynamic_01() {

    // Speicher für EINE int-Variable reservieren

    int* ip = new int(123);

    int m = *ip;  // Indirekten Zugriff - Operator

    std::cout << *ip << std::endl;
    std::cout << ip << std::endl;
    std::cout << m << std::endl;

    delete ip;

    std::cout << "Stopper" << std::endl;
}

void worker(int* data) {

    std::cout << "Worker: " << *data << std::endl;

    *data = 456;

    std::cout << "Worker: " << *data << std::endl;

    // delete data;   // no ownership
}

void dynamic_02() {

    int* ip = new int(123); // scalar new

    std::cout << *ip << std::endl;

    worker(ip);

    // Frage: Wer gibt den Zeiger wieder frei ?????
    // a) In dynamic_02: Ginge
    // b) Könnte auch der Worker sein
    // c) Beide geben den Zeiger frei: NIEMALS // Crash // Double Delete // Double Free
    // d) Vorzugslage: Es sollte für einen Zeiger immer einen Besitzer (Owner) geben: Hier: dynamic_02

    delete ip;   // scalar delete
}

void dynamic_03() {

    int numbersAmStack[10] = {};

    // Speicher anlegen - ist nicht initialisiert
    int* ip = new int[10]; // 10 int-Werte werden allokiert (dicht liegend im Speicher)
                           // 'array new'

    // Speicher vorbelegen
    for (int i = 0; i != 10; ++i) {
        ip[i] = i;
    }

    // Speicher ausgeben
    for (int i = 0; i != 10; ++i) {
        std::cout << ip[i] << std::endl;
    }

    // Speicher wieder freigeben

    delete[] ip;                   // 'array delete'
}

void dynamic_04() {

    Time* tp = new Time(10, 35, 30);  // Allokation ==> Konstruktor

    delete tp;              // Freigabe ==> Destruktor
}

void dynamic_05() {

    Time* tp = new Time[10]; // Feld von Time-Objekten

    // ...

    delete[] tp;

   // delete tp;  // Ub // "Undefined Behaviour"
}

void dynamic_06() {

    int* ip = new int[10];

    // a) Das Feld traversieren / durchlaufen :
    // KLASSISCH mit Zeiger und Zeigerarithmetik

    for (int i = 0; i < 10; ++i) {

        *(ip + i) = i;
    }

    // b) Um diese Schreibweise zu vereinfachen:
    // Verwendet [] 
    for (int i = 0; i < 10; ++i) {

        ip[i] = i;
    }

    delete[] ip;
}

void dynamic_07() {

    Time* tp = new Time[10];

    // a) Das Feld traversieren / durchlaufen :
    // KLASSISCH mit Zeiger und Zeigerarithmetik

    for (int i = 0; i < 10; ++i) {

        (*(tp + i)).setHours(i);
    }

    delete[] tp;
}

void dynamic() {

    dynamic_07();
}

