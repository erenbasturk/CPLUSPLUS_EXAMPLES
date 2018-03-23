#include <QCoreApplication>
#include <iostream>
#include <set>
using namespace std;

class Test {
    int id;
    string name;

public:
    Test(): id(0), name(""){

    }

    Test(int id, string name): id(id), name(name)
    {

    }



    void print() const {
        cout << id << ": " << name << endl;
    }

    bool operator <(const Test &other) const{
        return name < other.name;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    set<int> numbers;

    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(30);
    numbers.insert(20);

    for(set<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        cout << *it << endl;
    }

    set<int>::iterator itFind = numbers.find(30);

    if(itFind != numbers.end())
    {
        cout << "Found: " << *itFind << endl;
    }

    if(numbers.count(30))
    {
        cout << "Number Found." << endl;
    }

    set<Test> tests;

    tests.insert(Test(10,"Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(20, "Sue"));

    for(set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
        it->print();
    }

    return a.exec();
}

// first program out to show elements ordering
// Sets are containers that store unique elements following a specific order. In the sets order the smallest is the first.
// 10
// 20
// 30
// 50
//
// we can use count() function to find the element exists in the container or not count() return us 1 or 0.
//



