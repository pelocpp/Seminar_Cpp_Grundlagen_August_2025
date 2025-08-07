#include <cstdlib>
#include <print>

void zufall_00()
{
    std::println("zufall:");

    int n1 = std::rand();

    // 0 .. 48 plus 1
    n1 = (n1 % 49) + 1;
    std::println("Zahl: {}", n1);

    int n2 = std::rand();
    n2 = (n2 % 49) + 1;
    std::println("Zahl: {}", n2);

    int n3 = std::rand();
    n3 = (n3 % 49) + 1;
    std::println("Zahl: {}", n3);
}


void zufall_01()
{
    std::println("zufall:");

    std::srand(2);   // NUR EINMAL AUFRUFEN // seed // Samen // Wachstum

    int n1 = std::rand();
    std::println("Zahl: {}", n1);

    int n2 = std::rand();
    std::println("Zahl: {}", n2);

    int n3 = std::rand();
    std::println("Zahl: {}", n3);
}

void zufall_02()
{
    std::println("zufall:");

    time_t start_wert = std::time(0);

    std::srand(start_wert);   // NUR EINMAL AUFRUFEN // seed // Samen // Wachstum

    int n1 = std::rand();
    std::println("Zahl: {}", n1);

    int n2 = std::rand();
    std::println("Zahl: {}", n2);

    int n3 = std::rand();
    std::println("Zahl: {}", n3);
}


void zufall()
{
    zufall_00();
}