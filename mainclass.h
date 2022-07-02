#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <Source.h>

class MainClass : public QWidget
{
    Q_OBJECT
private:

#include <DeAddMenuVar>
#include <CaAddMenuVar>
#include <OfAddMenuVar>
#include <DeleteMenuVar>
#include <EditMenuVar>

    QDialog* Error = new QDialog();
    QBoxLayout* ErrorloH = new QBoxLayout(QBoxLayout::LeftToRight);
    QBoxLayout* ErrorloV = new QBoxLayout(QBoxLayout::TopToBottom);

    QProcess* console = new QProcess();
    QString program = "C:/Qt/Projects/Kursach/debug/Kursach.exe";

    QWidget* mw = new QWidget();
    QStackedWidget* msl = new QStackedWidget();
    QWidget* OfAddW = new QWidget();
    QWidget* CaAddW = new QWidget();
    QWidget* DeAddW = new QWidget();
    QWidget* EditW = new QWidget();
    QWidget* SEditW;
    QWidget* DeleteW = new QWidget();

    QComboBox* docCB;
    QComboBox* aedCB;
    QBoxLayout* cb;
    void Header();

    QBoxLayout* old = new QBoxLayout(QBoxLayout::TopToBottom);

    void CreateMenu();

    QBoxLayout* tlo;
    void TableMenu();

    QBoxLayout* seclo;
    void SecondLO();

    QBoxLayout* tml;
    QBoxLayout* ml;
    void MainLayout();

    QString choosedId = "";

    QTabWidget* TabWidget = new QTabWidget;
    QTableWidget* DeTable = new QTableWidget;
    QTableWidget* OfTable = new QTableWidget;
    QTableWidget* CaTable = new QTableWidget;

    QSqlDatabase DataBase;
    QSqlQuery* DBQuery;

    void ErrorAct();
public:
    MainClass();
public slots:
    void TableUpdate();
    void DeAddMenuSlot();
    void DeAddAct();
    void OfAddAct();
    void CaAddAct();
    void ChooseAct();
    void CancelAct();
    void EditAct();
    void DeleteAct();
};

#endif // MAINCLASS_H
