#include "Time.h"

#include <iostream>

Time::Time()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

// passt
//Time::Time(int hours, int minutes, int seconds)
//{
//    m_hours = 0;
//    m_minutes = 0;
//    m_seconds = 0;
//
//    setHours(hours);
//    setMinutes(minutes);
//    setSeconds(seconds);
//}

// eleganter - mit Member Initializer List
Time::Time(int hours, int minutes, int seconds) 
    : m_hours (0), m_minutes(0), m_seconds(0)
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time::Time(int hours, int minutes) 
    : Time (hours, minutes, 0)
{
}


Time::Time(int seconds)    // auch denkbar !!!: 10.000 Sekunden ==> Stunden, Minuten und Sekunden
{
    m_hours = seconds / 3600;  // 60 * 60
    seconds = seconds % 3600;  // Modulo: Rest, der bei Division mit 3600 übrig bleibt
    m_minutes = seconds / 60;  
    m_seconds = seconds % 60;
}


void Time::reset()
{
    m_hours = 0;
    m_minutes = 0;
    m_seconds = 0;
}

void Time::print()
{
    std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
}

void Time::increment()
{
    // To be done
}

int Time::getHours()
{
    return m_hours;
}

void Time::setHours(int hours)
{
    // es ist der Wert des Parameters hours zu überprüfen !!!
    if (hours >= 0 && hours < 24)
    {
        m_hours = hours;
    }
    else
    {
        std::cout << "Falscher Parameter: " << hours << std::endl;

        // Exception Handling: throw ... wäre an dieser Stelle etwas "hart"
    }
}


int  Time::getMinutes()
{
    return m_minutes;
}

void Time::setMinutes(int minutes)
{
    // es ist der Wert des Parameters hours zu überprüfen !!!
    if (minutes >= 0 && minutes < 60)
    {
        m_minutes = minutes;
    }
    else
    {
        std::cout << "Falscher Parameter: " << minutes << std::endl;
    }
}

int  Time::getSeconds()
{
    return m_seconds;
}

void Time::setSeconds(int seconds)
{
    // es ist der Wert des Parameters hours zu überprüfen !!!
    if (seconds >= 0 && seconds < 60)
    {
        m_seconds = seconds;
    }
    else
    {
        std::cout << "Falscher Parameter: " << seconds << std::endl;
    }
}

