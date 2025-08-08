// ===========================================================================
// Main.cpp  // Namespaces
// ===========================================================================

// want to prevent some annoying warnings: "warning C4101 : 'tb1' : unreferenced local variable"
#pragma warning(push)
#pragma warning(disable : 4101)

// using namespace std; 

// this is the top level namespace
const double Pi = 3.14159265358979323846;

namespace MyFirstProject
{
    namespace Widgets
    {
        class Textbox
        {
        };
    }
}

using namespace MyFirstProject;  // Das gilt jetzt für den gesamten Rest dieser Datei

void app() {

    // A) Vollqualifizierung
    //::MyFirstProject::Widgets::Textbox  tb1;
    //MyFirstProject::Widgets::Textbox  tb2;

    // B) Teil-Qualifizierung
    //using namespace MyFirstProject;
    //Widgets::Textbox  tb1;

    // C) Teil-Qualifizierung
    // using namespace MyFirstProject;
    // Widgets::Textbox  tb1;

    // Tipp:  // IMHO
    // Auf Methodenebene würde ich einen Namensraum öffnen:
    //using namespace MyFirstProject;
    //Widgets::Textbox  tb1;

    // oder
    using namespace MyFirstProject::Widgets;
    Textbox  tb1;
}


namespace AnotherProject
{
    class Textbox
    {
    };
}


void app2()
{
    // Textbox tb;

    // A) Muss Entscheidung treffen

   // MyFirstProject::Widgets::Textbox tb;
   //// oder
   // AnotherProject::Textbox tb2;

    using namespace MyFirstProject::Widgets;

    Textbox tb;

 //   using namespace AnotherProject;

    AnotherProject::Textbox tb2;
}












static void namespace_01()
{
    using namespace MyFirstProject::Widgets;
    // or
    // using namespace AnotherProject;

    Textbox tb1;                             // namespace MyFirstProject::Widgets

    MyFirstProject::Widgets::Textbox tb2;    // namespace MyFirstProject::Widgets

    AnotherProject::Textbox tb3;             // namespace AnotherProject
}

static void namespace_02()
{
    // accessing classes with full namespace specification
    using namespace MyFirstProject::Widgets;
    Textbox tb1;

    using namespace AnotherProject;
    // Textbox tb2;                          // doesn't compile: why
}

static void namespace_03()
{
    // better way
    MyFirstProject::Widgets::Textbox tb;

    // or - possible - but 'smells'
    using namespace MyFirstProject::Widgets;

    Textbox tb2;
}

void main_Namespaces()
{
    namespace_01();
    namespace_02();
    namespace_03();
}

#pragma warning(pop)

// ===========================================================================
// End-of-File
// ===========================================================================