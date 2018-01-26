#include "time.h"
#include <stdexcept>
#include <qdebug.h>
//
// In the constructor, we invoke the setHour(), setMinute() and setSecond(), which perform input validation,
// instead of direct assignment. We also modified setTime() in a similar manner.
Time::Time(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}
//
int Time::getHour() const {
    return hour;
}
//
void Time::setHour(int h){
    if(h >= 0 && h <= 23)
    {
        hour = h;
    }else {
        throw std::invalid_argument("Invalid hour! Hour shall be 0-23");
    }
}
//
int Time::getMinute() const{
    return minute;
}
//
void Time::setMinute(int m){
    if(m >=0 && m <=59)
    {
        minute = m;
    }else
    {
        throw std::invalid_argument("Invalid minute! Minute shall be 0-59");
    }
}
//
int Time::getSecond() const {
    return second;
}
//
void Time::setSecond(int s)
{
    if(s >=0 && s <= 59)
    {
        second = s;
    }else
    {
        throw std::invalid_argument("Invalid second! Second shall be 0-59");
    }
}
//
void Time::setTime(int h, int m, int s){
    //call setters to validate input
    setHour(h);
    setMinute(m);
    setSecond(s);
}
//
void Time::print() const
{
    qDebug() << "Hour:" << hour << " Minute:" << minute << " Second:" << second;
}
