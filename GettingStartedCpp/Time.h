class Time
{
private:
    // member data / instance variables
    int m_hours;
    int m_minutes;
    int m_seconds;

public:
    // Konstruktor(en)
    Time();
    Time(int hours, int minutes, int seconds);
    Time(int hours, int minutes);     // Sekunden auf Null

    // Time(int hours);   // denkbar !!!: Minuten und Sekunden auf Null

    // Conversion Constructor
    Time(int seconds);    // auch denkbar !!!: 10.000 Sekunden ==> Stunden, Minuten und Sekunden

public:
    // getter / setter
    int  getHours();                  // lesender Zugriff
    void setHours(int hours);         // schreibender Zugriff
    int  getMinutes();                // lesender Zugriff
    void setMinutes(int minutes);     // schreibender Zugriff
    int  getSeconds();                // lesender Zugriff
    void setSeconds(int seconds);     // schreibender Zugriff

public:
    // public interface / methods
    // No implementation
    // But: Schnittstellen der Methoden festlegen!
    void reset();
    void increment();
    void print();
};
