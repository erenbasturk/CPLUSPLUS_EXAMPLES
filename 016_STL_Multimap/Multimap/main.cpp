#include <QCoreApplication>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    multimap<int, string> lookup;

    lookup.insert(make_pair(30, "Mike"));
    lookup.insert(make_pair(10, "Vicky"));
    lookup.insert(make_pair(30, "Raj"));
    lookup.insert(make_pair(20, "Bob"));

    for(multimap<int, string>::iterator it=lookup.begin(); it != lookup.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;

    for(multimap<int, string>::iterator it = lookup.find(20); it!=lookup.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

    for(multimap<int, string>::iterator it=its.first; it !=its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return a.exec();
}

// QMAP and QMultiMap difference
// if you use QMap for storing single key multiple values,
// some other person who is going through your class members
// might get the impression that you are willing to save single
// key value pairs (from the data type) Similarly, if you use QMultiMap,
// anyone reading the definition can get the idea that the data will have
// multiple value for same key.
