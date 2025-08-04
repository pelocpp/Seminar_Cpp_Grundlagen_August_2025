#include "Time.h"


#include <iostream>

void test_pointer_references_01()
{
    // Datentyp Zeiger

    int n = 123;   // direkter Zugriff (lesend und schreibend)

    int anzahlBytes = sizeof(int);

    int* pi;    // Adress- / Pointer-Variable // Vereinbarung // Declaration

    pi = &n;    // Adresse-von // Address-of Operator

    // Wert von n auf 456 setzen, ohne den Bezeichner 'n' zu verwenden :)
    *pi = 456;   // Indirekter Zugriff: Operator * // Anweisung // Statement

    int m = *pi;  // Indirekter Zugriff / hier lesend
}

void test_pointer_references_02()
{
    // Datentyp Zeiger

    int n = 123;   // direkter Zugriff (lesend und schreibend)

    int* pi = nullptr;    // Adress- / Pointer-Variable // Vereinbarung // Declaration

    pi = &n;

    int m = *pi;

    std::cout << m << std::endl;

    // Was tut das ??????????????????????
    pi++;

    m = *pi;  // Geht das ???: 

    std::cout << m << std::endl;

    pi--;

    m = *pi;  // Geht das ???: 

    std::cout << m << std::endl;
}

void test_pointer_references_03()
{
    // Datentyp Referenz

    int n = 123;

    int& ri = n;     // Referenz für eine int-Variable

    // Wert von n auf 456 setzen, ohne den Bezeichner 'n' zu verwenden :)
    ri = 456;

    ri++;
}


void test_pointer_references_04()
{
    Time now(14, 46, 0);
    now.print();

    Time copyNow;

    copyNow = now;
    copyNow.print();

    now.setHours(17);
    now.print();
    copyNow.print();

    std::cout << "=============" << std::endl;

    Time& refNow = now; // Hier entsteht KEINE Kopie !!!!!
    refNow.print();

    now.setHours(20);
    now.print();           // 20
    copyNow.print();       // 14
    refNow.print();        // 20

    std::cout << "=============" << std::endl;

    std::cout << sizeof (copyNow) << std::endl;
    std::cout << sizeof(refNow) << std::endl;
    std::cout << sizeof(Time&) << std::endl;
    std::cout << sizeof(Time*) << std::endl;
}

void test_pointer_references()
{
    Time now (14, 46, 0);
    Time than(14, 46, 30);

    if (now.compare(than) == true) {
        std::cout << "gleich" << std::endl;
    }
    else {
        std::cout << "ungleich" << std::endl;
    }
}