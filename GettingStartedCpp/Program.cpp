#include "Time.h"

int main()
{
    Time now(9999, 32, 30);   // erstes Objekt: now
    
    //now.m_hours = 10;    // Vermeiden, obwohl sie prinzipiell richtig ist.
    //now.m_hours = 9999;  // Vermeiden
    //now.setHours(10);

    //now.m_minutes = 32;
    //now.m_seconds = 30;
    now.setMinutes(32);
    now.setSeconds(30);

    now.print();    // das soll gehen
    now.reset();
    now.print();

    // int stunden = now.m_hours;  // geht nicht !!!!
    int stunden = now.getHours();  // geht

    now.setHours(11);              // geht
    now.setHours(9999);            // geht auch vom Aufruf her, 
                                   // aber hat KEINE Auswirkung auf das Objekt 'now'

    Time than(17, 0, 0);     // zweites Objekt: than

    //than.m_hours = 17;
    //than.m_minutes = 0;
    //than.m_seconds = 0;

    than.setHours(17);
    than.setMinutes(0);
    than.setSeconds(0);

    than.print();

    Time later;  // 0:0:0 denkbar; wie ???

    Time moreLater(16, 30);  // 0:0:0 denkbar; wie ???

    return 0;
}
