#include <iostream>

extern void test_pointer_references();
extern void dynamic();
extern void test_zeichenketten();

extern long nextAccountNumber;    // extern-Deklaration einer glob. Variablen

static void test_static()
{
    static int value = 10;        // KEINE lokale Variable

    value++;
}

int main()
{
    test_zeichenketten();

    return 0;
}

