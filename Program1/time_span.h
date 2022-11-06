#ifndef TIME_SPAN_H
#define TIME_SPAN_H
#include <string>
#include <iostream>
using namespace std;

class TimeSpan{
    private:
    int hours_;
    int minutes_;
    int seconds_;


    public:
    //Constructors
    TimeSpan(double, double, double);
    TimeSpan(double, double);
    TimeSpan(double);
    TimeSpan();

    //getters-setters
    int hours() const;
    int minutes() const;
    int seconds() const;
    void set_time(int hours, int minutes, int seconds);
    void convert(double, double, double);


    //overloads
    TimeSpan operator +(const TimeSpan& obj)const;
    TimeSpan operator -(const TimeSpan& obj)const;
    TimeSpan operator -();
    TimeSpan& operator +=(const TimeSpan& obj);
    TimeSpan& operator -=(const TimeSpan& obj);

    bool operator ==(const TimeSpan& obj) const;
    bool operator !=(const TimeSpan& obj) const;
    bool operator >=(const TimeSpan& obj) const;
    bool operator <=(const TimeSpan& obj) const;
    bool operator >(const TimeSpan& obj) const;
    bool operator <(const TimeSpan& obj) const;

    //output to console
    friend ostream &operator<<(ostream&, const TimeSpan&);
    friend istream &operator>>(istream&, TimeSpan&);

};
#endif