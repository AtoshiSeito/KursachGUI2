#include <Source.h>
#include <QCoreApplication>
#include<mainclass.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QPushButton* dbb = new QPushButton("Подразделения");
    //QPushButton* obb = new QPushButton("Офицеры");
    //QPushButton* cbb = new QPushButton("Курсанты");
    MainClass obj;
    return a.exec();
}
