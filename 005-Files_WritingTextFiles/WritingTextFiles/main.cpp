// this examples from udemy c++ courses
#include <QCoreApplication>
#include <fstream>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    fstream outFile;
    string outputFileName = "text.txt";

    outFile.open(outputFileName,ios::out);

    if(outFile.is_open()) {
        outFile << "Hello There" << endl;
        outFile << 123 << endl;
        outFile.close();
    } else {
        qDebug() << "Could not create file" << QString::fromStdString(outputFileName) << endl;
    }

    return a.exec();
}
