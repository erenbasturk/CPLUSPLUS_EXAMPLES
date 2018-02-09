#include <QCoreApplication>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    map<string, int> ages;

    ages["Mike"]=40;
    ages["Raj"]=20;
    ages["Vicky"]=30;

    ages["Mike"] = 70;

    ages.insert(make_pair("Peter", 100));

    cout << ages["Raj"] << endl;

    if(ages.find("Vicky") != ages.end()) {
        cout << "Found Vicky" << endl;
    } else {
        cout << "Key not found" << endl;
    }

    for(map<string, int>::iterator it= ages.begin(); it != ages.end(); it++ )
    {
        pair<string, int> age = *it;

        cout << age.first << ": " << age.second << endl;
    }

    for(map<string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    return a.exec();
}


// Map allows us to store key fine pearls. It is like a lookup table.
// The idea is that you can stop at some information which you can
// retrieve with a key.
