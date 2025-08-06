#include <iostream>

// =====================================================================

// Eine Schnittstelle // Interface

// Single-Responsibility
// eine Schnittstelle sollte eine Betrachtung beschreiben
struct IRectangle
{
    virtual void draw() = 0;
    virtual int  circumference() = 0;  
    virtual int  area() = 0;
    virtual void eraseBackground() = 0;
};

class IPersistence
{
public:
    virtual void save() = 0;
};

// =====================================================================

// Abstrakte Basisklasse
// Keine Objekte von Rectangle
class Rectangle : public IRectangle, public IPersistence
{
private:
// protected:
    int m_x;        // linke, obere Ecke
    int m_y;
    int m_width;    // breite
    int m_height;   // hoehe

public:
    // c'tor(s)
    Rectangle() : Rectangle(0, 0, 0, 0) {}     // Kein Standard-Konstruktor

    Rectangle(int x, int y, int width, int height)
    : m_x(x), m_y(y), m_width(width), m_height(height)  //  // Zugriff von innen: Immer erlaubt
    {}

    // getter
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }

    // setter
    void setWidth(int width) { if (width <= 0) return;  m_width = width; }
    void setHeight(int height) { if (height <= 0) return;  m_height = height; }

    // public interface
    void draw() override {

        eraseBackground();  // jepp, das geht // virtuelle Aufruf

        std::cout
            << "Rectangle::draw [x=" << m_x
            << ", y=" << m_y << "]" << std::endl;
    }

    int circumference() override final
    {
        return 2 * (m_width + m_height);
    }

    int area() override final
    {
        return m_width * m_height;
    }

    void save() override
    {
        // To be Done
    }
};

// ist-ein Beziehung
class ColorderRectangle : public Rectangle
{
private:
    int m_color;

public:
    ColorderRectangle() 
        : Rectangle (0 , 0, 1, 1), m_color (99)
    {}

    ColorderRectangle(int x, int y, int width, int height)
        : Rectangle (x, y, width, height),   m_color(99)
    {
    }

    ColorderRectangle(int color) 
        : m_color(color)
    {
        // weil Farbe am Rand, muss ich die Breite und Höhe um 1 Pixel kleiner machen.

        // Pro / Contra Betrachtung
        
        // Direkter Zugriff geht, wenn die Member in der Basisklasse protected definiert sind.
        // m_width = m_width - 1;
        // m_height = m_height - 1;   // Zugriff über eine Kindklasse: "Depends" : private / public

        // Indirekter Zugriff über die öffentliche Schnittstelle der Basisklasse
        int width = getWidth() - 1;
        setWidth(width);

        int height = getHeight() - 1;
        setWidth(height);
    }

    // public interface
    // überschreiben // to override (sich über etwas hinweg setzen) // to overwrite
    void draw() override
    {
      //  Rectangle::draw();

        // additiv noch etwas zusätzliches machem
        std::cout
            << "ColoredRectangle::draw [m_color=" << m_color << "]" << std::endl;
    }

    void eraseBackground() 
    {
        std::cout << "  ColoredRectangle::eraseBackground" << std::endl;
    }
};

class BlackWhiteRectangle : public Rectangle
{
private:
    int m_black_white_factor;

public:
    BlackWhiteRectangle()
        : Rectangle(0, 0, 1, 1), m_black_white_factor(1)
    {
    }

    BlackWhiteRectangle(int x, int y, int width, int height)
        : Rectangle(x, y, width, height), m_black_white_factor(1)
    {
    }

    // public interface
    // überschreiben // to override (sich über etwas hinweg setzen) // to overwrite
    void draw() override
    {
       // Rectangle::draw();

        // additiv noch etwas zusätzliches machem
        std::cout << "BlackWhiteRectangle::draw" << std::endl;
    }

    void eraseBackground()
    {
        std::cout << "  BlackWhiteRectangle::eraseBackground" << std::endl;
    }
};

void main_vererbung_01()
{
    // Rectangle r (1, 1, 10, 20);

    // r.m_x = 123;  // Zugriff von außen: VERBOTEN

    ColorderRectangle cr1 (1, 1, 10, 20);

    ColorderRectangle cr2;

    ColorderRectangle cr3 (88);

    cr1.draw();
}

void main_vererbung_02()
{
    IRectangle* pRect = nullptr;  // Das ist ein Schnittstellenzeiger

    ColorderRectangle cr(1, 1, 10, 20);  // cr liegt am Stack

    pRect = &cr;    // Geht das ???

    pRect->draw();  // 2 Optionen: draw Basis-/ Kind-Klasse ?!? 
}

void main_vererbung_03()
{
    IRectangle* pRect = nullptr;

    ColorderRectangle* cr = new ColorderRectangle(1, 1, 10, 20);

    pRect = cr;

    pRect->draw();  // 2 Optionen: draw Basis-/ Kind-Klasse ?!? 

    delete cr;
}


void main_vererbung_04()
{
    ColorderRectangle* cr1 = new ColorderRectangle(1, 1, 10, 20);
    ColorderRectangle* cr2 = new ColorderRectangle(2, 2, 10, 20);
    ColorderRectangle* cr3 = new ColorderRectangle(3, 3, 10, 20);

    BlackWhiteRectangle* bw1 = new BlackWhiteRectangle(2, 2, 10, 20);
    BlackWhiteRectangle* bw2 = new BlackWhiteRectangle(3, 3, 10, 20);

    IRectangle* figures[5] = { cr1, bw1, cr2, bw2, cr3 };

    std::string* s = new std::string("");
    size_t size = s->size();   // Standard // gewohnt // norm. Methodenaufruf

    for (int i = 0; i != 5; ++i) {
        figures[i]->draw(); // von welcher Klasse: OFFEN // Runtime// virtueller Methodenaufruf
    }

    // Echten Leben: Container Qt // unterschiedliche Widgets // Redraw

    // ToDo: deletes
}

void main_vererbung_05()
{
    ColorderRectangle* cr1 = new ColorderRectangle(1, 1, 10, 20);
    ColorderRectangle* cr2 = new ColorderRectangle(2, 2, 10, 20);
    ColorderRectangle* cr3 = new ColorderRectangle(3, 3, 10, 20);

    BlackWhiteRectangle* bw1 = new BlackWhiteRectangle(2, 2, 10, 20);
    BlackWhiteRectangle* bw2 = new BlackWhiteRectangle(3, 3, 10, 20);

    IRectangle* figures[5] = { cr1, bw1, cr2, bw2, cr3 };

    std::string* s = new std::string("");
    size_t size = s->size();   // Standard // gewohnt // norm. Methodenaufruf

    for (int i = 0; i != 5; ++i) {
        figures[i]->draw(); // von welcher Klasse: OFFEN // Runtime// virtueller Methodenaufruf
    }

    // Echten Leben: Container Qt // unterschiedliche Widgets // Redraw

    // ToDo: deletes
}


void main_vererbung()
{
    main_vererbung_01();
    main_vererbung_02();
    main_vererbung_03();
    main_vererbung_04();
    main_vererbung_05();
}