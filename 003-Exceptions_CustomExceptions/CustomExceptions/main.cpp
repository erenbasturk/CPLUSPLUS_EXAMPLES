// this examples from udemy c++ courses
//
#include <QCoreApplication>
#include <QDebug>
//
using namespace std;

class MyException: public exception {
public:
    virtual const char* what() const throw()
    {
        return "someting bad happenned!";
    }
};

class Test {
public:
    void goesWrong()
    {
        throw MyException();
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    try{
        test.goesWrong();
    }catch(MyException &e)
    {
        qDebug() << e.what() << endl;
    }

    return a.exec();
}
