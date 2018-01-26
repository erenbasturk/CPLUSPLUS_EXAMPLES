// this examples from udemy c++ course
#include <QCoreApplication>
#include <QDebug>
#include <exception>
//
using namespace std;
// When we need an exceptions in subclass we can use
// the following method like, we can create an error
// detect variable then, handle it according to requirement

void goesWrong() {
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected) {
        throw bad_alloc();
    }

    if(error2Detected) {
        throw exception();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try{
        goesWrong();
    } catch (bad_alloc &e){
        qDebug() << "Catching bad_alloc:" << e.what() << endl;
    } catch (exception &e)
    {
        qDebug() << "Cathing exception:" << e.what() << endl;
    }

    return a.exec();
}
