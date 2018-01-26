// this examples from udemy c++ courses
#include <QCoreApplication>
#include <QDebug>
using namespace std;

class CanGoWrong
{
public:
    CanGoWrong(){
        char *pMemory = new char[99999999999999999];
        delete [] pMemory;
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // try-catch mechanism provide us to idenftifying the error
    // and continue to software. If we have some exception in the
    // program and if we don't use try catch, the program will
    // terminate
    try {
        CanGoWrong wrong;
    }
    catch(bad_alloc& e)
    {
        qDebug() << "Caught Exception" << e.what() << endl;
    }

    qDebug() << "Still Running" << endl;

    return a.exec();
}
