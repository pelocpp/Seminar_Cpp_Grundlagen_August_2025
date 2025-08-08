// =====================================================================================
// LValue / RValue
// =====================================================================================

#include <unordered_map>
#include <iostream>
#include <string>
#include <print>
#include <algorithm>


namespace LValueRValue {

    // lvalue reference
    static void sayHello(std::string& message) {
        std::println("sayHello [std::string&]:  {}", message);
    }

    // rvalue reference
    static void sayHello(std::string&& message) {
        std::println("sayHello [std::string&&]: {}", message);
    }

    static void test01() {

        std::string a = "Hello";

        std::string b = " World";

        // void sayHello(std::string& message)

        // a+b ist ein Objekt:
        // i) temporär // irgendwo am Stack
        // ii) hat keinen Namen

        std::string& rs = a;

        std::string&& rs1 = a + b;

        a.append("123");

        sayHello(a);

        sayHello(a + b);  // a+b: Konkatenation: "Hello World"
    }

    // -------------------------------------------------------------------

    static void helper(std::string&& message)
    {
        sayHello(std::move(message));  // A) sayHello(std::string&&)
                                       // B) sayHello(std::string&)
    }

    static void test02()
    {
        //std::string s("ABC");
        //helper(s);  // No

        helper(std::string("Where are we going ...")); // tmp.  std::string Objekt
    }

    // -------------------------------------------------------------------

    static void test03() {

        //std::string s = "Hello";

        //sayHello(s);
        //// versus
        //sayHello(std::move(s));  // casts an lvalue to an rvalue
    }

    // -------------------------------------------------------------------

    static void test04() {

        int a = 2;
        int b = 3;

        int& ri = a;          // works: (lvalue) reference to a (named) variable

        // int& i = 123;      // invalid: (lvalue) reference to a constant

        int&& i = 123;        // works: (rvalue) reference to a constant

        const int& j = 123;   // works: const references binds to everything

        // int& k = a + b;    // invalid: (lvalue) reference to a temporary object

        int&& k = a + b;      // works: (rvalue) reference to a temporary object
    }

    static void test05()
    {
        std::string a = "Hello";

        std::string b = " World";

        a = std::move(b);  // verschieben statt kopieren 

        // Was bleibt übrig: eine leere Hülle

        std::println("a: >>>{}<<<", a);
        std::println("b: >>>{}<<<", b);  // Testzwecken ...
    }
}

void main_rvalue_lvalue()
{
    using namespace LValueRValue;
    test01();
    test02();
    test03();
    test04();
    test05();
}

// =====================================================================================
// End-of-File
// =====================================================================================
