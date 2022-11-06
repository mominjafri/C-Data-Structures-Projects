#include <iostream>
#include "time_span.h"
#include <cmath>
using namespace std;

TimeSpan :: TimeSpan (){  //constructors
    hours_ = 0;
    minutes_ = 0;
    seconds_ = 0;

}

TimeSpan :: TimeSpan (double hrs, double min, double sec){ 
    convert(hrs, min, sec);
  
}

TimeSpan :: TimeSpan(double min, double sec){
   convert(0, min, sec);
  
}

TimeSpan :: TimeSpan(double sec){
    convert(0,0, sec);
   
}

int TimeSpan :: hours() const { //getters-setters
    return hours_;
}

int TimeSpan :: minutes() const {
    return minutes_;
}

int TimeSpan :: seconds() const{
    return seconds_;
}

void TimeSpan :: set_time(int h, int m, int s){ //converts double to integer for output
    hours_ = h;
    minutes_ = m;
    seconds_ = s;
    convert(hours_, minutes_, seconds_);
}

void TimeSpan :: convert(double hrs, double min, double sec){
    int convertHours = hrs * 3600;
    int convertMinutes = min * 60;
    int convertSeconds = round(sec);
    int totalSeconds = convertSeconds + convertMinutes + convertHours;

    hrs = totalSeconds / 3600;
    totalSeconds = totalSeconds % 3600;
    min = totalSeconds / 60;
    sec = totalSeconds % 60;
    sec = round(sec);

    this->hours_ = hrs;
    this->minutes_ = min;
    this->seconds_ = sec;

}

TimeSpan TimeSpan :: operator +(const TimeSpan& obj)const{
    TimeSpan timespan;
    timespan.hours_ = hours_ + obj.hours_;
    timespan.minutes_ = minutes_ + obj.minutes_;
    timespan.seconds_ = seconds_ + obj.seconds_;

    if(timespan.seconds_ > 60){
        timespan.seconds_ -= 60;
        timespan.minutes_++;

    } if(timespan.minutes_ > 60) {
        timespan.minutes_ -= 60;
        timespan.hours_++;

    }
    return timespan;

}

TimeSpan TimeSpan :: operator -(const TimeSpan& obj)const{
    TimeSpan timespan;
    timespan.hours_ = hours_ - obj.hours_;
    timespan.minutes_ = minutes_ - obj.minutes_;
    timespan.seconds_ = seconds_ - obj.seconds_;

    if(timespan.seconds_ < -60){
        timespan.seconds_ += 60;
        timespan.minutes_--;

    } if(timespan.minutes_ < -60) {
        timespan.minutes_ += 60;
        timespan.hours_--;

    }
    return timespan;

}

TimeSpan TimeSpan::operator-(){
    hours_ = -hours_;
    minutes_ = -minutes_;
    seconds_ = -seconds_;
    return TimeSpan(hours_,minutes_,seconds_);
}


TimeSpan& TimeSpan :: operator +=(const TimeSpan& obj) {
    hours_ = hours_ + obj.hours_;
    minutes_ = minutes_ + obj.minutes_;
    seconds_ = seconds_ + obj.seconds_;

    if(seconds_ > 60){
        seconds_ -= 60;
        minutes_ ++;
    } if(minutes_ > 60) {
        minutes_ -= 60;
        hours_ ++;
    }
    
    return *this;
}

TimeSpan& TimeSpan :: operator -=(const TimeSpan& obj) {
    hours_ = hours_ - obj.hours_;
    minutes_ = minutes_ - obj.minutes_;
    seconds_ = seconds_ - obj.seconds_;

    if(seconds_  < -60){
        seconds_ += 60;
        minutes_ --;
    } if(minutes_ < -60) {
        minutes_ += 60;
        hours_  --;
    }

    convert(hours_, minutes_, seconds_);
    
    return *this;
    

   
}

//overloads

bool TimeSpan :: operator ==(const TimeSpan& obj) const{  //equals operator
    return (hours_ == obj.hours_ && minutes_ == obj.minutes_ && seconds_ == obj.seconds_); //returns true if time is equal to set object, same with other operators

}

bool TimeSpan :: operator !=(const TimeSpan& obj) const{ //not equal to operator
    return !(hours_ == obj.hours_ && minutes_ == obj.minutes_ && seconds_ == obj.seconds_);
}

bool TimeSpan :: operator >=(const TimeSpan& obj) const{ //greater than or equal to operator
    return (hours_ >= obj.hours_ && minutes_ >= obj.minutes_ && seconds_ >= obj.seconds_);
           
}

bool TimeSpan :: operator <=(const TimeSpan& obj) const{ //less than or equal to operator
    return (hours_ <= obj.hours_ && minutes_ <= obj.minutes_ && seconds_ <= obj.seconds_);
}

bool TimeSpan :: operator >(const TimeSpan& obj) const{ //greater than oeprator
    return (hours_ > obj.hours_ && minutes_ > obj.minutes_ && seconds_ > obj.seconds_);
           
}

bool TimeSpan :: operator <(const TimeSpan& obj) const{ //less than operator
    return (hours_ < obj.hours_ && minutes_ < obj.minutes_ && seconds_ < obj.seconds_);
}


ostream &operator <<(ostream &output, const TimeSpan& obj){ //output stream
    output << "Hours: " << obj.hours() << ", Minutes: " << obj.minutes() << ", Seconds: " << obj.seconds();
    return output;

}

istream &operator >>(istream &input, TimeSpan& obj){ //input stream
    double hrs;
    double min;
    double sec;
    input >> hrs >> min >> sec;
    obj.set_time(hrs, min, sec);
    return input;
}




