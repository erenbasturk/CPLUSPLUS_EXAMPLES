//this example from udemy c++ course
#include <QCoreApplication>
#include <fstream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string inFileName = "test.txt";

    ifstream inFile;

    if(inFile.is_open())
    {
        string line;

        while(inFile)
        {
            getline(inFile,line);
            qDebug() << QString::fromStdString(line) << endl;
        }

        inFile.close();
    }else
    {
        qDebug() << "Cannot open file " << QString::fromStdString(inFileName) << endl;
    }


    return a.exec();
}
