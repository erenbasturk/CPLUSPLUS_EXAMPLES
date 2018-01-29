#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <fstream>
using namespace std;
//
#pragma pack(push,1)
struct Person {
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person someone = {"Frodo",200,0.8};

    string fileName = "test.bin";

    //// Write Binary File ////

    ofstream outputFile;

    outputFile.open(fileName,ios::binary);

    if(outputFile.is_open()){
        outputFile.write(reinterpret_cast<char *>(&someone),sizeof(Person));
    }else {
        qDebug() << "Could not create file " << QString::fromStdString(fileName);
    }

    //// Read Binary File ////

    Person someoneElse = {};

    ifstream inputFile;

    inputFile.open(fileName, ios::binary);

    if(inputFile.is_open()) {
        inputFile.read(reinterpret_cast<char*>(&someoneElse),sizeof(Person));
        inputFile.close();
    } else {
        qDebug() << "Could not read file " + QString::fromStdString(fileName);
    }

    qDebug() << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;

    return a.exec();
}
