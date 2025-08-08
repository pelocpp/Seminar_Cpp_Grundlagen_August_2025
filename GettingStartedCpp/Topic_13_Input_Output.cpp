// ===========================================================================
// Main.cpp // Streams
// ===========================================================================

#include <iostream>
#include <string>

using namespace std;  // I wouldn't do this

namespace Streams
{
    static void scriptSnippets00()
    {
        int n = 7;

        n = n << 1;   // Bitweise schieben der Bits um 1 nach links.

        std::cout.write("ABC", 3);

        // ==============

        std::cout << "Eine Zeile" << std::endl;
        std::cout << "Eine Zeile" << '\n';
        std::cout << "Done.";
    }

    static void scriptSnippetsOhneStd()
    {
        int n;
        cout << "Geben Sie eine Zahl ein: ";

        cin >> n;
        cout << "n: " << n << std::endl;
    }

    static void scriptSnippets()
    {
        int n;
        std::cout << "Geben Sie eine Zahl ein: ";

        std::cin >> n;
        std::cout << "n: " << n << std::endl;
    }

    static void cinCout()
    {
        int myInt;
        double myDouble;

        std::cout << "int:    ";
        std::cin >> myInt;

        std::cout << "double: ";
        std::cin >> myDouble;

        std::cout << "Int:    " << myInt << std::endl;
        std::cout << "Double: " << myDouble << std::endl;
    }
}

void main_Streams()
{
    using namespace Streams;

    //scriptSnippets00();
    //return;

    scriptSnippets();
  //  cinCout();
}

// ===========================================================================
// End-of-File
// ===========================================================================