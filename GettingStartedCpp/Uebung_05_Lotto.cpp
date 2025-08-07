// ===========================================================================
// Lottery.cpp
// ===========================================================================

#include "Uebung_05_Lotto.h"

// c'tors
Lottery::Lottery() : m_random_engine(123), m_dist(1, 49) {
    m_numbers.reserve(6);
}

Lottery::Lottery(int seed) : m_random_engine(seed), m_dist(1, 49) {
    m_numbers.reserve(6);
}

// getter
size_t Lottery::getDrawnNumbers() const { return m_numbers.size(); }

// public interface
int Lottery::nextRandomNumber() const
{
    int number = m_dist(m_random_engine);
    return number;
}

bool Lottery::numberAlreadyDrawn(int number) const
{
    std::vector<int>::const_iterator pos = std::find(
        m_numbers.cbegin(),
        m_numbers.cend(),
        number
    );

    return pos != m_numbers.end();
};

void Lottery::setNextNumber(int number)
{
    m_numbers.push_back(number);
}

int Lottery::drawNextNumber() const
{
    int number;
    // Könnte Endlos-Schleife sein // Produktiv-Einsatz 
    do {
        number = nextRandomNumber();
    } while (numberAlreadyDrawn(number));

    return number;
}

void Lottery::play()
{
    for (int i = 0; i < 6; ++i) {

        int number = drawNextNumber();
        setNextNumber(number);
        verifyNumbers();
    }
}

void Lottery::verifyNumbers() const
{
    for (int i = 0; i < m_numbers.size(); ++i) {

        int wert = m_numbers[i];

        for (int k = 0; k < m_numbers.size(); ++k) {

            if (k == i)
                continue;

            if (wert == m_numbers[k]) {

                throw std::exception("Illegal numbers found");
            }
        }
    }
}

void Lottery::printNumber(int number) {
    std::cout << number << ", ";
}

void Lottery::print()
{
    std::cout << "\n";
    std::cout << "Ziehung der Lottozahlen:\n";
    std::cout << "========================\n";

    std::for_each(
        m_numbers.begin(),
        std::prev(m_numbers.end()),
        printNumber
    );

    int last = m_numbers.back();
    std::cout << last;

    std::cout << "\n";
}

//============================================================================

// Hauptprogramm

static void testLottery01()
{
    Lottery lottery(123);
    lottery.play();
    lottery.print();
}

static void printDrawNumber(int number) {
    std::cout << "> " << number << std::endl;
}

static void testLottery02()
{
    std::cout << std::endl;
    std::cout << "Ziehung der Lottozahlen:" << std::endl;;
    std::cout << "========================" << std::endl;;

    // using std::for_each
    Lottery lottery(123);
    std::for_each(
        lottery.begin(),
        lottery.end(),
        printDrawNumber
    );
}

static void testLottery03()
{
    std::cout << std::endl;
    std::cout << "Ziehung der Lottozahlen:" << std::endl;;
    std::cout << "========================" << std::endl;;

    // using range-based for loop
    Lottery lottery(123);
    for (int number : lottery) {
        std::cout << "> " << number << std::endl;
    }
}

void exerciseLotto()
{
    testLottery01();
    testLottery02();
    testLottery03();
}


// ===========================================================================
// End-of-File
// ===========================================================================