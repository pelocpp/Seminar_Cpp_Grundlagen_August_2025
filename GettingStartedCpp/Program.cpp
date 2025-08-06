#include <iostream>

extern void test_pointer_references();
extern void dynamic();
extern void test_zeichenketten();
extern void testParamPassing();
extern void test_rule_of_three();
extern void main_Exceptions();
extern void main_vererbung();
extern void main_templates();
extern void test_stl_vector();

extern long nextAccountNumber;    // extern-Deklaration einer glob. Variablen

static void test_static()
{
    static int value = 10;        // KEINE lokale Variable

    value++;
}

int main()
{
    test_stl_vector();

    return 0;
}

