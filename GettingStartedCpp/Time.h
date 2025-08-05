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

    // Destruktor
    ~Time();

    // Büchse der Pandora
    // Time(int minutes, short seconds);  // Stunden auf Null

    // Time(int hours);   // denkbar !!!: Minuten und Sekunden auf Null

    // Conversion Constructor
    Time(int seconds);    // auch denkbar !!!: 10.000 Sekunden ==> Stunden, Minuten und Sekunden

public:
    // getter / setter
    int  getHours() const;            // lesender Zugriff
    void setHours(int hours);         // schreibender Zugriff
    int  getMinutes() const;          // lesender Zugriff
    void setMinutes(int minutes);     // schreibender Zugriff
    int  getSeconds() const;          // lesender Zugriff
    void setSeconds(int seconds);     // schreibender Zugriff

public:
    // public interface / methods
    // No implementation
    // But: Schnittstellen der Methoden festlegen!
    void reset();
    void increment();
    void print();

    bool compare(const Time& other) const;

public:
    // operators
    bool operator== (const Time& other) const;

    bool operator== (int seconds) const;  // 3:20:30 mit 1000 Sekunden
};
