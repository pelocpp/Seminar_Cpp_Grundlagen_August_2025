// ===========================================================================
// Main.cpp  // Exceptions
// ===========================================================================

#include <iostream>
#include <stdexcept>
#include <string>

namespace Exceptions {

    static void dangerousFunction()
    {
        // KANN EIN PROBLEM EINTRETEN
        std::string str("Zeichenkette");   // knappe 20 Zeichen lang
        std::cout << str << std::endl;

        int pos = 123;
        char ch = str.at(pos);  // Hmmm, wie geht es jetzt weiter

        std::cout << "Bin hier" << std::endl;
    }

    static void scriptSnippets()
    {
        try
        {
            dangerousFunction();
        }
        catch (const std::out_of_range&)
        {
            // do something because of out_of_range exception
            std::cout << "std::out_of_range" << std::endl;
        }
        catch (const std::overflow_error&)
        {
            // do something because of overflow_error exception
            std::cout << "std::overflow_error" << std::endl;
        }
        catch (const std::invalid_argument&)
        {
            // do something because of invalid_argument exception
            std::cout << "std::invalid_argument" << std::endl;
        }
        catch (const std::exception&)
        {
            // an unexpected exception occurred
            std::cout << "std::exception" << std::endl;
        }
    }
}

static void exceptions01()
{
    try
    {
        std::string str("Zeichenkette");
        std::cout << str << std::endl;

        int pos = 5;
        char ch = str.at(pos);

        size_t len = str.length();
        std::cout << "Length: " << len << std::endl;

        str.insert(123, " !!!");
        std::cout << str << std::endl;
    }
    //catch (const std::exception& ex)
    //{
    //    // an unexpected exception occurred
    //    std::cout << "std::exception: " << ex.what() << std::endl;
    //}
    //catch (const std::out_of_range& ex)   // inherited from std::exception
    //{
    //    // do something because of out_of_range exception
    //    std::cout << "std::out_of_range: " << ex.what() << std::endl;
    //}
    catch (const std::invalid_argument& ex)
    {
        // do something because of invalid_argument exception
        std::cout << "std::invalid_argument: " << ex.what() << std::endl;
    }
    catch (const std::length_error& ex)
    {
        // do something because of invalid_argument exception
        std::cout << "std::length_error: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) // Allgemeine Behandlung : Immer am ENDE  // "Lumpensammler"
    {
        // an unexpected exception occurred
        std::cout << "std::exception: " << ex.what() << std::endl;
    }
    catch (...) // Allgemeine Behandlung : Immer am ENDE  // "Lumpensammler"
    {
        // an unexpected exception occurred
        std::cout << "... " << std::endl;
    }

    std::cout << "Done." << std::endl;
}

void main_Exceptions()
{
    using namespace Exceptions;

    // scriptSnippets();

    exceptions01();
}


// ===========================================================================
// End-of-File
// ===========================================================================