
extern void test_pointer_references();

static void test_static()
{
    static int value = 10;   // KEINE lokale Variable

    value++;
}

int main()
{
    test_pointer_references();

    test_static();
    test_static();
    test_static();
}

