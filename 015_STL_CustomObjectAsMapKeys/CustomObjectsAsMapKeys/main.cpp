#include <QCoreApplication>
#include <iostream>
#include <map>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(): name(""),age(0){

    }

    Person(const Person &other)
    {
        cout << "Copy constructor running!" << endl;
        name = other.name;
        age = other.age;
    }

    Person(string name, int age):
        name(name), age(age) {
    }

    void print() const {
         cout << name << ": " << age << flush;
    }

    bool operator<(const Person &other) const{
        if(name == other.name) {
            return age < other.age;
        } else {
            return name < other.name;
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    map<Person, int> people;

    people[Person("Mike", 40)] = 40;
    people[Person("Mike", 40)] = 123;
    people[Person("Sue", 30)] = 30;
    people[Person("Raj", 20)] = 20;

    for(map<Person, int>::iterator it = people.begin(); it != people.end();it++)
    {
        std::cout << it->second << ": ";
        it->first.print();
        cout << endl;
    }

    return a.exec();
}

// shallow copy
// char * Source = "Hello, world.";
// char * ShallowCopy = Source;
// char * DeepCopy = new char(strlen(Source)+1);
// strcpy(DeepCopy,Source);
// 'ShallowCopy' points to the same location in memory as 'Source' does.
// 'DeepCopy' points to a different location in memory, but the contents are the same.

