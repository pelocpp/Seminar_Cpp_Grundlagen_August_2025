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
extern void main_stl_performance();
extern void zufall();
extern void phone_book();
extern void main_Streams();
extern void aufrufbaresObjekt();
extern void main_auto();
extern void phone_book_with_auto();
extern void main_brace_initialization();
extern void main_lambdas();
extern void test_stl_vector();
extern void main_rvalue_lvalue();
extern void main_move_semantics();


extern long nextAccountNumber;    // extern-Deklaration einer glob. Variablen

static void test_static()
{
    static int value = 10;        // KEINE lokale Variable

    value++;
}

int main()
{
    main_rvalue_lvalue();

    return 0;
}
