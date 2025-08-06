#include <iostream>

//class Calculator // int
//{
//public:
//    static int add(int n, int m) { return n + m; }
//    static int sub(int n, int m) { return n - m; }
//    static int mul(int n, int m) { return n * m; }
//    static int div(int n, int m) { return n / m; }
//};
//
//class DoubleCalculator // double
//{
//public:
//    static double add(double n, double m) { return n + m; }
//    static double sub(double n, double m) { return n - m; }
//    static double mul(double n, double m) { return n * m; }
//    static double div(double n, double m) { return n / m; }
//};


// Schablone: Abstrahiert Datentypen // Datentypen werden als Variable definiert


// Schablone ==> Klasse :  Instanziierung eines Templates

template <typename T>

class Calculator
{
public:
    static T add(T n, T m) { 
        return n + m;
    }

    static T sub(T n, T m) { return n - m; }
    static T mul(T n, T m) { return n * m; }
    static T div(T n, T m) { return n / m; }
};

void main_templates()
{ 
    // Calculator<int> intCalc;

    int result1 = Calculator<int>::add(5, 6);

    double result2 = Calculator<double>::add(5.5, 6.6);
}