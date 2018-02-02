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

    vector<double> numbers;

    cout << "Size: " << numbers.size() << endl;

    int capacity = numbers.capacity();
    cout << "Capacity: " << capacity << endl;

    for(int i=0; i<10000; i++)
    {
        if(numbers.capacity() != capacity)
        {
            capacity = numbers.capacity();
            cout << "Capacity: " << capacity << endl;
        }
        numbers.push_back(i);
    }

    numbers.resize(100);
    cout << numbers[2] << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity : " << numbers.capacity() << endl;

    return a.exec();
}

// when we initialise the vector with the size as 20(vector<double> numbers(20)) then, the output is like that,
// capacicty increas exponantially
// Size: 20
// Capacity: 20
// Capacity: 40
// Capacity: 80
// Capacity: 160
// Capacity: 320
// Capacity: 640
// Capacity: 1280
// Capacity: 2560
// Capacity: 5120
// Capacity: 10240

// when we initialise the vector with the size as 0(vector<double> numbers) then, the output is like that,
// capacity increas exponantially
// Size: 0
// Capacity: 20
// Capacity: 40
// Capacity: 80
// Capacity: 160
// Capacity: 320
// Capacity: 640
// Capacity: 1280
// Capacity: 2560
// Capacity: 5120
// Capacity: 10240


// capacity is different than size. capacity is the size of internal rate.
// if we clean the vector the capacity do not change.
// when we resize the vector, it does not clean the memory and the capacity does not change.
// we change the capacity with reserve method.
// output:
// Size: 0
// Capacity: 0
// Capacity: 1
// Capacity: 2
// Capacity: 4
// Capacity: 8
// Capacity: 16
// Capacity: 32
// Capacity: 64
// Capacity: 128
// Capacity: 256
// Capacity: 512
// Capacity: 1024
// Capacity: 2048
// Capacity: 4096
// Capacity: 8192
// Capacity: 16384
// 2
// Size: 100
// Capacity : 16384




