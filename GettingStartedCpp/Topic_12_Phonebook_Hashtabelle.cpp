#include <unordered_map>
#include <iostream>
#include <string>
#include <print>
#include <algorithm>


// Schlüssel: Name
// Wert:      Nummer // size_t

// Header-File .h
class Phonebook
{
private:
    std::unordered_map<std::string, size_t> m_book;   // Hash-Tabelle

public:
    // getter
    size_t countEntries() const;

    bool addEntry(const std::string& name, size_t phone);
    bool searchEntry(const std::string& name) const;
    bool getPhonenumber(const std::string& name, size_t& phone) const;

    bool removeEntry(const std::string& name);
    void print() const;
};

// Output conform to std::cout // globale Funktion
std::ostream& operator<< (std::ostream& os, const Phonebook& pb);

// ===============================================================

bool Phonebook::addEntry(const std::string& name, size_t phone)
{
    // std::pair zum Einfügen des Elements erzeugen
    std::pair<const std::string, size_t> entry(name, phone);

    // ein zweites std::pair zum Auswerten, ob das Einfügen geklappt hat
    std::pair < std::unordered_map<std::string, size_t>::iterator, bool > result =

        m_book.insert(entry);

    if (result.second == true) {
        std::println("Hat geklappt");
        return true;
    }
    else {
        std::println("Hat NICHT geklappt");
        return false;
    }
}

bool Phonebook::searchEntry(const std::string& name) const
{
    std::unordered_map<std::string, size_t>::const_iterator pos = m_book.find(name);

    if (pos == m_book.end()) {

        std::println("Name {} NICHT vorhanden", name);
        return false;
    }
    else {

        std::println("Name {} gefunden", name);
        return true;
    }
}


bool Phonebook::getPhonenumber(const std::string& name, size_t& phone) const
{
    std::unordered_map<std::string, size_t>::const_iterator pos = m_book.find(name);

    if (pos == m_book.end()) {

        std::println("Name {} NICHT vorhanden", name);
        return false;
    }
    else {

        std::println("Name {} gefunden", name);

        size_t tmp = (*pos).second;

        // Wert tmp nach "außen" kopieren
        phone = tmp;

        // KUERZER -  ginge auch
       // phone = (*pos).second;

        return true;
    }
}

size_t Phonebook::countEntries() const {

    return m_book.size();
}

bool Phonebook::removeEntry(const std::string& name)
{
    size_t count = m_book.erase(name);

    if (count == 1) {
        std::println("Name {} wurde entfernt", name);
        return true;
    }
    else {
        std::println("Name {} NICHT gefunden", name);
        return false;
    }
}

void doPrint( const std::pair<const std::string, size_t>& entry)
{
    const std::string& name = entry.first;
    size_t phone = entry.second;

    std::println("  Name {} - Phone: {}", name, phone);
}

void Phonebook::print() const
{
    std::println("My Phonebook:");

    std::for_each(
        m_book.begin(),
        m_book.end(),
        doPrint
    );
}

std::ostream& operator<< (std::ostream& os, const Phonebook& pb)
{
    pb.print();

    return os;
}

// ================================================

void phone_book()
{
    Phonebook myBook;

    bool done;

    done = myBook.addEntry("Hans Mueller", 12345678);
    done = myBook.addEntry("Susi Meier", 345345345);
    done = myBook.addEntry("Anton Wagner", 23525235);

    myBook.print();

    bool found = myBook.searchEntry("Susi Meier");
    found = myBook.searchEntry("Gerhard Maier");

    size_t phoneMaier = 0;
    found = myBook.getPhonenumber("Susi Meier", phoneMaier);

    if (found) {
        std::println("Susi Meier hat die Nummer {}", phoneMaier);
    }

    done = myBook.removeEntry("Susi Meier");
    done = myBook.removeEntry("Susi Wagner");

    std::cout << myBook << '\n';
}
