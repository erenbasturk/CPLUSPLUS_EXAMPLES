#include <QCoreApplication>
#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(): name(""),age(0) {

    }

    Person(const Person &other)
    {
        cerr << "Copy Constructor running!" << endl;
        name = other.name;
        age = other.age;
    }

    // this allow us to initialise the variable of the class
    Person(string name,int age):
        name(name),age(age){

    }

    void print() {
        cout << name << ": " << age << endl;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    map<int, Person> people;

    people[50] = Person("Mike", 40);
    people[32] = Person("Raj", 20);
    people[1]  = Person("Vicky", 30);

    people.insert(make_pair(55,Person("Bob",45)));
    people.insert(make_pair(54,Person("Sue",45)));

    for(map<int, Person>::iterator it=people.begin(); it != people.end(); it++)
    {
        cout << it->first << ": " << flush;
        it->second.print();
    }

    return a.exec();
}
