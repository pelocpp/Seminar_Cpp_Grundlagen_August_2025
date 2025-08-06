#include <iostream>
#include <vector>
#include <list>
#include <deque>


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

void test_stl_vector()
{
    test_stl_vector_05();
}