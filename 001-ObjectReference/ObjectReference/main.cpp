#include <QCoreApplication>
#include <QDebug>
#include "time.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //ordinary object
    Time t1(1,2,3);
    t1.print();     //01:02:03

    //object pointer
    Time *ptrT1 = &t1;
    (*ptrT1).print(); // 01:02:03
    ptrT1->print();   // 01:02:03
    //anObjectPtr-> member is the same as (*anObjectPtr).member

    //object reference
    Time& refT1 = t1; //refT1 is an alias to t1
    refT1.print();    // 01:02:03

    //Dynamic allocation
    Time *ptrT2 = new Time(4,5,6); // allocate dynamically
    ptrT2->print(); // 04:05:06
    delete ptrT2;   //deallocate


    //object array
    Time tArray[2]; //tArray1 is an array of Time with 2 elements
                    //Use default constructor for all elements

    Time* ptrArray3 = new Time[2]; //ptrArray3 is a pointer to time
                                   // Dynamically allocate an array of Time with 2 elements via new
    ptrArray3[0].print(); //00:00:00
    ptrArray3[1].print(); //00:00:00
    delete ptrArray3;     //Deallocate dynamic array via delete[]

    //C++11 syntax, compile with -std=c++0x
    Time* ptrArray4 = new Time[2] {Time{11,12,13},Time{14}}; //invoke constructor
    ptrArray4->print();      // 11:12:13
    (ptrArray4 +1)->print(); // 14:00:00
    delete ptrArray4;


    return a.exec();
}
