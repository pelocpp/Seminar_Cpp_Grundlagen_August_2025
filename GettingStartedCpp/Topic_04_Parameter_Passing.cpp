#include <iostream>

static void malZwei(int n)
{
    n = 2 * n;
}

// Call-by-Address // Ginge auch in C
static void malZweiVariante2(int* ip)
{
    int result = *ip;  // Indirekter Zugriff // lesend

    result = 2 * result;

    *ip = result;          // Indirekter Zugriff // schreibend
}

// Call-by-Referemz // Geht nur in C++
static void malZweiVariante3(int& ip)
{
    ip = 2 * ip;   // Achtung: Referenz // Es wird auf das Original zugegriffen // hinter den Kulissen
                   // Schreibweise: Ist mit Referenzen einfacher
                   // Go-for Referenz
}

void testParamPassing()
{
    int a = 123;

    std::cout << "a: " << a << std::endl;

    malZwei(a);

    std::cout << "a: " << a << std::endl;

    malZweiVariante2(&a);

    std::cout << "a: " << a << std::endl;

    malZweiVariante3(a);

    std::cout << "a: " << a << std::endl;
}