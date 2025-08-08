#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>


void test_stl_vector_01()
{
   std::vector<int> numbers;
    //std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    for (int i = 0; i != numbers.size(); ++i) {

        std::cout << "i: " << i << ", Value: " << numbers[i] << std::endl;
    }
}

void test_stl_vector_01_A()
{
    std::vector<int> numbers;
    //std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // for_each // das kann auch C++  // C++ 11
    // Welches Schlüsselwort: for

    for (int value :  numbers) {

        std::cout << "Value: " << value << std::endl;
    }

    for (auto value : numbers) {

        std::cout << "Value: " << value << std::endl;
    }
}

void test_stl_vector_02()
{
    std::vector<int> numbers;

    numbers.reserve(80); // Allokiert - 80 Plätze vorab !

    for (int i = 0; i != 100; ++i) {

        numbers.push_back(2 * i);
        std::cout 
            << "i: " << i << ", Value: " << numbers[i] << ", Size: " 
            << numbers.size() << ", Capacity: " << numbers.capacity() <<  std::endl;
    }

    numbers.shrink_to_fit();
    std::cout << "Size: "
        << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;
}

void test_stl_vector_03()
{
    std::vector<int> numbers;
   //std::list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    std::vector<int>::iterator pos = numbers.begin();

    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    int value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
   // ++pos;
    pos++;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    value = *pos;
    std::cout << value << std::endl;

}

void test_stl_vector_04()
{
    // Verallgemeinerung
    using MyElementType = int;

    // using MyContainerType = std::vector<MyElementType>;
    // using MyContainerType = std::list<MyElementType>;
    using MyContainerType = std::deque<MyElementType>;

    using MyPositionType = MyContainerType::iterator;

    MyContainerType numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    MyPositionType pos = numbers.begin();

    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    int value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
   // ++pos;
    pos++;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    value = *pos;
    std::cout << value << std::endl;

    // gehe zum nächsten Element
    ++pos;
    if (pos == numbers.end()) {
        std::cout << "Done." << std::endl;
        return;
    }

    // Wert an dieser Position
    value = *pos;
    std::cout << value << std::endl;

}

void test_stl_vector_05()
{
    // Verallgemeinerung
    using MyElementType = int;

    using MyContainerType = std::vector<MyElementType>;
    // using MyContainerType = std::list<MyElementType>;
    // using MyContainerType = std::deque<MyElementType>;

    using MyPositionType = MyContainerType::iterator;

    MyContainerType numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // Den Container durchlaufen

    MyPositionType pos = numbers.begin();

    // Gute Lösung
    while (pos != numbers.end()) {

        // Wert an dieser Position auegeben
        int value = *pos;
        std::cout << value << std::endl;

        ++pos;
    }

    std::cout << "Done." << std::endl;
}

void print(int& value) {   // Egal: ob mit & oder nicht  // Nur lesen

    int m = value;

    std::cout << value << std::endl;
}

void test_stl_vector_06()
{
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // classic
    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    // modern / kompakt
    std::for_each(
        numbers.begin(),
        numbers.end(),
        [] (int value) { std::cout << value << std::endl; }
    );

    std::cout << "Done." << std::endl;
}


// man kann auf die Originale der Werte im Container zugreifen: Referenz
void init (int& value) {

    value = 1;
   // std::cout << value << std::endl;
}

void test_stl_vector_07()
{
    std::vector<int> numbers;

    numbers.resize(10);   // nicht mir reserve zu verwechseln

    // möchte alle Elemente auf den Wert 1 vorbelegen
    // classic
    std::for_each(
        numbers.begin(),
        numbers.end(),
        init  // 1
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int value) { std::cout << value << std::endl; }
    );

    // modern
    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int& value) { value = 2; }
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int value) { std::cout << value << std::endl; }
    );

    std::cout << "Done." << std::endl;
}

void test_stl_vector_08()
{
    std::vector<int> numbers;

    numbers.resize(10);   // nicht mir reserve zu verwechseln

    // möchte alle Elemente auf den Wert 1 vorbelegen
    std::fill(
        numbers.begin(),
        numbers.end(),
        1
    );

    std::cout << "Done." << std::endl;
}

int belegeVor()
{
    static int value = 0;   // globale Variable (( nur innerhalb der Funktion 'belegeVor' sichtbar ))
    value += 2;
    return value;
}

void test_stl_vector_09()
{
    std::vector<int> numbers;

    numbers.resize(5);   // nicht mir reserve zu verwechseln

    // Vorbelegen: mit verschiedenen Werten
    // classic
    std::generate(
        numbers.begin(),
        numbers.end(),
        belegeVor
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int value) { std::cout << value << std::endl; }
    );

    // modern C++
    std::generate(
        numbers.begin(),
        numbers.end(),
        []() { 
            static int value = 50;   // globale Variable (( nur innerhalb des lambdas sichtbar ))
            value += 2;
            return value;
        }
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int value) { std::cout << value << std::endl; }
    );

    // modern C++ - no static
    std::generate(
        numbers.begin(),
        numbers.end(),
        [value = 100] () mutable -> int {   // Lambda mit Instanzvariable
            value += 2;
            return value;
        }
    );

    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int value) { std::cout << value << std::endl; }
    );

    std::cout << "Done." << std::endl;
}

void test_stl_vector_10()
{
    std::vector<int> numbers;

    numbers.resize(10); 

    // vorbelegen mit 2, 4, 6, ...
    std::generate(
        numbers.begin(),
        numbers.end(),
        belegeVor
    );

    // ausgeben
    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    // suchen
    std::vector<int>::iterator found = std::find(
        numbers.begin(),
        numbers.end(),
        11
    );

    if (found == numbers.end()) {
        std::cout << "Not found!" << std::endl;
    }
    else {
        std::cout << "Found: " << *found << std::endl;
    }

    std::cout << "Done." << std::endl;
}

bool isGreaterThanTen(int value) {

    return value > 10;
}

void test_stl_vector_11()
{
    std::vector<int> numbers;

    numbers.resize(10);

    // vorbelegen mit 2, 4, 6, ...
    std::generate(
        numbers.begin(),
        numbers.end(),
        [value = 0]() mutable -> int {   // Lambda mit Instanzvariable
            value += 2;
            return value;
        }
    );

    // ausgeben
    std::for_each(
        numbers.begin(),
        numbers.end(),
        [](int value) { std::cout << value << std::endl; }
    );

    // suchen: gibt es Werte groesser 10
    // classic
    std::vector<int>::iterator found = std::find_if(
        numbers.begin(),
        numbers.end(),
        isGreaterThanTen
    );

    if (found == numbers.end()) {
        std::cout << "Not found!" << std::endl;
    }
    else {
        std::cout << "Found: " << *found << std::endl;
    }

    // suchen: gibt es Werte groesser 10
    // Modern C++
    found = std::find_if(
        numbers.begin(),
        numbers.end(),
        [] (int value)  -> bool { return value > 10; }
    );

    if (found == numbers.end()) {
        std::cout << "Not found!" << std::endl;
    }
    else {
        std::cout << "Found: " << *found << std::endl;
    }

    std::cout << "Done." << std::endl;
}



bool filter(int elem) {
    return (elem % 2) == 0;
}

void test_stl_vector_12()
{
    std::vector<int> numbers;
    numbers.resize(10);

    // vorbelegen mit 1, 2, 3, 4, 5, ...
    std::iota(
        numbers.begin(),
        numbers.end(),
        1
    );

    // ausgeben
    std::for_each(
        numbers.begin(),
        numbers.end(),
        print
    );

    // Filtern:
    // Habe eine ersten Vektor
    // Will alle geraden Zahlen rausfiltern ...

    //// Erste Variante des Aufrufs: 
    //std::vector<int> target;
    //target.resize(numbers.size());

    //// Ziel-Container muss alle Ergebnisse aufnehmen können - mit operator=
    //// (muss also mindestens so groß sein wie der Ursprungscontainer)
    //std::copy_if(
    //    numbers.begin(),
    //    numbers.end(),
    //    target.begin(),
    //    filter
    //);

    // Zweite Variante des Aufrufs: 
    // Ziel-Container ist zu Beginn leer
    std::vector<int> target;

    // Ziel-Container muss alle Ergebnisse aufnehmen können:
    // Diese können mit 'push_back' an das Ende von 'target' angehängt werden
    // Dazu benötigt man aber einen Adapter
    std::copy_if(
        numbers.begin(),
        numbers.end(),
        // target.begin(),
        std::back_inserter (target),
        //filter
        [] (int elem) -> bool { return (elem % 2) == 0; }
    );

    std::cout << "Result:" << std::endl;

    // ausgeben
    std::for_each(
        target.begin(),
        target.end(),
        print
    );

    std::cout << "Done." << std::endl;
}


void test_stl_vector()
{
    test_stl_vector_12();
}