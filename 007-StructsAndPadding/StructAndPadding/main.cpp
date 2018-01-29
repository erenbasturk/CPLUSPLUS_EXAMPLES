// examples from udemy c++ course
#include <QCoreApplication>
#include <QDebug>
//
using namespace std;
//
#pragma pack(push,1)
struct Person{
  char name[50];
  int age;
  double weight;
};
#pragma pack(pop)

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "size of person" << sizeof(Person);

    return a.exec();
}

// we can turn on packaging with pragma pack(pop) and
// we can turn off packaging with #pragma pack(push,1)
// if we turn-off packagging datasize will not complete
// to 8's power.
