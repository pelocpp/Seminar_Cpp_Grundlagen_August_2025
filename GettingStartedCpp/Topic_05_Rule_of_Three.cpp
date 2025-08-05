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

    // d'tor
    ~BigData();

    int getSize();
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

BigData::~BigData()
{
    delete[] m_data;  // WICHTIG
}

int BigData::getSize()
{
    return m_size;
}

// Anwendung
void test_rule_of_three_01()
{
    BigData data(10);

    BigData empty;

    // Frage: Destruktor wird erst aufgerufen, wenn es zum delete - Aufruf kommt.
    BigData* dynData = new BigData(10);

    delete dynData;
}

void test_rule_of_three_02()
{
    BigData data(10);

    BigData other;

    other = data;

    std::cout << "data:  " << data.getSize() << std::endl;

    std::cout << "other: " << other.getSize() << std::endl;
}

void test_rule_of_three()
{
    // test_rule_of_three_01();
    test_rule_of_three_02();
}