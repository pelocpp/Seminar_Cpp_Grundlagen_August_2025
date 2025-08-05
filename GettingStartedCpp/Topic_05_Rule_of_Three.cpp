#include "Time.h"

#include <iostream>

// ============================================

// Header-Datei 'BigData.h'
class BigData
{
private:
    int* m_data;    // Feld soll int-Werte verwalten 
    int  m_size;    // Anzahl der Elemente, die über m_data vorhanden sind.

public:
    // c'tors
    BigData();
    BigData(int size);
    BigData(const BigData& other);  // Copy-C'tor

    // d'tor
    ~BigData();

    // getter
    int getSize();

    // operators
    BigData& operator= (const BigData& right); // Assignment-Operator
};

// ============================================

// Implementierungs-Datei 'BigData.cpp'
BigData::BigData(int size)
{
    // Feld der Länge 'size' anlegen
    m_data = new int[size];

    // Länge in das Objekt aufnehmen
    m_size = size;

    // Feld mit 0 vorbelegen
    for (int i = 0; i != size; ++i) {
        m_data[i] = 0;
    }
}

BigData::BigData()
{
    m_data = nullptr;
    m_size = 0;
}

BigData::BigData(const BigData& other)  // Copy-C'tor
{
    // So nicht
    // m_data = right.m_data;

    // allocate new buffer
    m_data = new int[other.m_size];

    // copy buffer from right side to left side
    for (int i = 0; i < other.m_size; ++i) {
        m_data[i] = other.m_data[i];
    }

    // set size member
    m_size = other.m_size;
}


BigData::~BigData()
{
    delete[] m_data;  // WICHTIG
}

int BigData::getSize()
{
    return m_size;
}

// Wertzuweisung
// a = b;
BigData& BigData::operator= (const BigData& right)
{
    // prevent self-assignment
    if (this == &right) {
        return *this;
    }

    // release left operand
    delete[] m_data;

    // So nicht
    // m_data = right.m_data;

    // allocate new buffer
    m_data = new int[right.m_size];   // Problem: Kein Speicher verfügbar

    // copy buffer from right side to left side
    for (int i = 0; i < right.m_size; ++i) {
        m_data[i] = right.m_data[i];
    }

    // adjust size member
    m_size = right.m_size;

    return *this;
}

// ======================================
// Anwendung
static void test_rule_of_three_01()
{
    BigData data(10);

    BigData empty;

    // Frage: Destruktor wird erst aufgerufen, wenn es zum delete - Aufruf kommt.
    BigData* dynData = new BigData(10);

    delete dynData;
}

static void test_rule_of_three_02()
{

    BigData data(10);
    BigData other;
    BigData anotherOther;

    data = data;  // macht KEINEN Sinn

    other = data;

    // anotherOther = BigData // das linke (other) // ACHTUNG: Keine Kopie;
    // Das sollte auch gegen // Definition einer Mehrfachwertzuweisung in C/C++
    anotherOther = (other = data);

    std::cout << "data:  " << data.getSize() << std::endl;

    std::cout << "other: " << other.getSize() << std::endl;
}

static void test_rule_of_three_03()
{
    BigData data(10);
    
    BigData copy (data);
}

static void test_rule_of_three_04()
{
    Time t1 (16, 17, 0);
    Time t2;
    // ...     
    t2 = t1;

    Time t4(t1);
}



void test_rule_of_three()
{
    // test_rule_of_three_01();
    // test_rule_of_three_02();
    //test_rule_of_three_03();
    test_rule_of_three_04();
}