#include <QCoreApplication>
#include <QDebug>
//
#include <iostream>
#include <vector>
//
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");



    for(int i=0; i<strings.size(); i++)
    {
        qDebug() << QString::fromStdString(strings[i]) << endl;
    }

    for(vector<string>::iterator it = strings.begin();  it != strings.end(); it++)
    {
        qDebug() << "*it:" << QString::fromStdString(*it) << endl;
    }

    vector<string>::iterator it = strings.begin();
    it +=2;

    qDebug() << "it:" << QString::fromStdString(*it) << endl;


    return a.exec();
}

// STL (Standard Template Libary). ıt is name of the library.

// Iterator is a pointer which is point to some elements in  array
// (such as an an array or container) and can iterate using ++ operator

// vectors are sequence container representing arrarys that can change
// in size.
