#include <print>

class Something
{
public:
    int doSomething(int value)
    {
        std::println("doSomething: {}", value);
        return 2 * value;
    }

    int operator() (int value)
    {
        std::println("doSomething: {}", value);
        return 2 * value;
    }
};


void aufrufbaresObjekt()
{
    Something obj;

    obj.doSomething(123);

    int result = obj(123);
}