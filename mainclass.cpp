#include "mainclass.h"

void MainClass::Header()
{
    ErrorloV->addWidget(new QLabel("Ошибка"));
    ErrorloH->addLayout(ErrorloV);
    Error->setLayout(ErrorloH);

    docCB = new QComboBox();
    aedCB = new QComboBox();
    docCB->addItem("Подразделения");
    docCB->addItem("Офицеры");
    docCB->addItem("Курсанты");

    aedCB->addItem("Добавить");
    aedCB->addItem("Изменить");
    aedCB->addItem("Удалить");

    cb = new QBoxLayout(QBoxLayout::LeftToRight);
    cb->addWidget(docCB);
    cb->addWidget(aedCB);
    cb->addStretch(1);
}

void MainClass::CreateMenu()
{
    oidlo->addWidget(oidl);
    oidlo->addWidget(oidle);
    oidlo->setSpacing(0);

    osnlo->addWidget(osnl);
    osnlo->addWidget(osnle);
    osnlo->setSpacing(0);

    ofnlo->addWidget(ofnl);
    ofnlo->addWidget(ofnle);
    ofnlo->setSpacing(0);

    otnlo->addWidget(otnl);
    otnlo->addWidget(otnle);
    otnlo->setSpacing(0);

    oidivlo->addWidget(oidivl);
    oidivlo->addWidget(oidivle);
    oidivlo->setSpacing(0);

    old->addLayout(oidlo);
    old->addStretch(1);
    old->addLayout(osnlo);
    old->addStretch(1);
    old->addLayout(ofnlo);
    old->addStretch(1);
    old->addLayout(otnlo);
    old->addStretch(1);
    old->addLayout(oidivlo);
    old->addStretch(1);
    old->addWidget(OfAddPB);
    OfAddW->setLayout(old);
    msl->addWidget(OfAddW);


    old = new QBoxLayout(QBoxLayout::TopToBottom);
    cidlo->addWidget(cidl);
    cidlo->addWidget(cidle);
    cidlo->setSpacing(0);

    csnlo->addWidget(csnl);
    csnlo->addWidget(csnle);
    csnlo->setSpacing(0);

    cfnlo->addWidget(cfnl);
    cfnlo->addWidget(cfnle);
    cfnlo->setSpacing(0);

    ctnlo->addWidget(ctnl);
    ctnlo->addWidget(ctnle);
    ctnlo->setSpacing(0);

    cidivlo->addWidget(cidivl);
    cidivlo->addWidget(cidivle);
    cidivlo->setSpacing(0);

    old->addLayout(cidlo);
    old->addStretch(1);
    old->addLayout(csnlo);
    old->addStretch(1);
    old->addLayout(cfnlo);
    old->addStretch(1);
    old->addLayout(ctnlo);
    old->addStretch(1);
    old->addLayout(cidivlo);
    old->addStretch(1);
    old->addWidget(CaAddPB);
    CaAddW->setLayout(old);
    msl->addWidget(CaAddW);


    old = new QBoxLayout(QBoxLayout::TopToBottom);
    didlo->addWidget(didl);
    didlo->addWidget(didle);
    didlo->setSpacing(0);
    old->addLayout(didlo);
    old->addStretch(1);
    old->addWidget(DeAddPB);
    DeAddW->setLayout(old);
    msl->addWidget(DeAddW);


    old = new QBoxLayout(QBoxLayout::TopToBottom);
    eidelo->addWidget(eidel);
    eidelo->addWidget(eidele);
    eidelo->setSpacing(0);
    old->addLayout(eidelo);
    old->addStretch(1);
    old->addWidget(echoosePB);
    EditW->setLayout(old);
    msl->addWidget(EditW);

    old = new QBoxLayout(QBoxLayout::TopToBottom);
    didelo = new QBoxLayout(QBoxLayout::TopToBottom);
    didelo->addWidget(didel);
    didelo->addWidget(didele);
    didelo->setSpacing(0);
    old->addLayout(didelo);
    old->addStretch(1);
    old->addWidget(deletePB);
    DeleteW->setLayout(old);
    msl->addWidget(DeleteW);

}

void MainClass::TableMenu()
{
    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    DataBase.setDatabaseName("C:/Qt/Projects/Kursach/MainDB.db");
    DataBase.open();
    DBQuery = new QSqlQuery;

    tlo = new QBoxLayout(QBoxLayout::TopToBottom);
    tlo->addWidget(TabWidget);
    TableUpdate();
    TabWidget->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

void MainClass::SecondLO()
{
    seclo = new QBoxLayout(QBoxLayout::LeftToRight);
    TableMenu();

    seclo->addWidget(msl);
    seclo->addLayout(tlo, 1);
    seclo->setContentsMargins(5, 10, 5, 10);
}

void MainClass::MainLayout()
{
    SecondLO();
    ml = new QBoxLayout(QBoxLayout::TopToBottom);
    ml->addLayout(cb);
    ml->addLayout(seclo, 1);
}

void MainClass::ErrorAct()
{
    Error->show();
}

void MainClass::TableUpdate()
{
    int i=0;
    DBQuery->exec("SELECT * FROM division");
    DeTable = new QTableWidget;
    DeTable->setColumnCount(3);
    //DeTable->size() = DeTable->minimumSize();
    DeTable->verticalHeader()->hide();
    DeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    DeTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ИН"));
    DeTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Личный состав"));
    DeTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Начальник курса"));
    DeTable->setShowGrid(true);
    DeTable->setSelectionMode(QAbstractItemView::SingleSelection);
    DeTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    while(DBQuery->next()){
        DeTable->insertRow(i);
        for(int j=0; j<3; j++){
            DeTable->setItem(i, j, new QTableWidgetItem(DBQuery->value(j).toString()));
        }
        i++;
    }
    i=0;
    DBQuery->exec("SELECT * FROM oficer");
    OfTable = new QTableWidget;
    OfTable->setColumnCount(5);
    OfTable->verticalHeader()->hide();
    OfTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    OfTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ИН"));
    OfTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Фамилия"));
    OfTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Имя"));
    OfTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Отчество"));
    OfTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Подразделение"));
    OfTable->setShowGrid(true);
    OfTable->setSelectionMode(QAbstractItemView::SingleSelection);
    OfTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    while(DBQuery->next()){
        OfTable->insertRow(i);
        for(int j=0; j<5; j++){
            OfTable->setItem(i, j, new QTableWidgetItem(DBQuery->value(j).toString()));
        }
        i++;
    }
    i=0;
    DBQuery->exec("SELECT * FROM cadet");
    CaTable = new QTableWidget;
    CaTable->setColumnCount(6);
    CaTable->verticalHeader()->hide();
    CaTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CaTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ИН"));
    CaTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Фамилия"));
    CaTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Имя"));
    CaTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Отчество"));
    CaTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Подразделение"));
    CaTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Начальник"));
    CaTable->setShowGrid(true);
    CaTable->setSelectionMode(QAbstractItemView::SingleSelection);
    CaTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    while(DBQuery->next()){
        CaTable->insertRow(i);
        for(int j=0; j<6; j++){
            CaTable->setItem(i, j, new QTableWidgetItem(DBQuery->value(j).toString()));
        }
        i++;
    }
    TabWidget->removeTab(2);
    TabWidget->removeTab(1);
    TabWidget->removeTab(0);
    TabWidget->addTab(DeTable, "Подразделения");
    TabWidget->addTab(OfTable, "Офицеры");
    TabWidget->addTab(CaTable, "Курсанты");
}

MainClass::MainClass()
{
    Header();
    QObject::connect(docCB, SIGNAL(currentIndexChanged(int)), this, SLOT(DeAddMenuSlot()));
    QObject::connect(aedCB, SIGNAL(currentIndexChanged(int)), this, SLOT(DeAddMenuSlot()));
    CreateMenu();
    MainLayout();
    QObject::connect(DeAddPB, SIGNAL(clicked(bool)), this, SLOT(DeAddAct()));
    QObject::connect(OfAddPB, SIGNAL(clicked(bool)), this, SLOT(OfAddAct()));
    QObject::connect(CaAddPB, SIGNAL(clicked(bool)), this, SLOT(CaAddAct()));
    QObject::connect(echoosePB, SIGNAL(clicked(bool)), this, SLOT(ChooseAct()));
    QObject::connect(ecancelPB, SIGNAL(clicked(bool)), this, SLOT(CancelAct()));
    QObject::connect(editPB, SIGNAL(clicked(bool)), this, SLOT(EditAct()));
    QObject::connect(deletePB, SIGNAL(clicked(bool)), this, SLOT(DeleteAct()));
    QObject::connect(console, SIGNAL(finished(int)), this, SLOT(TableUpdate()));
    msl->setCurrentIndex(msl->indexOf(DeAddW));
    mw->setLayout(ml);
    mw->setMinimumWidth(800);
    mw->show();
}

void MainClass::DeAddMenuSlot()
{
    int block=0;
    int action =0;
    block = docCB->currentIndex();
    action = aedCB->currentIndex();
    if(action == 0){
        if(block == 0){
            msl->setCurrentIndex(msl->indexOf(DeAddW));
        } else if(block == 1){
            msl->setCurrentIndex(msl->indexOf(OfAddW));
        } else if(block == 2){
            msl->setCurrentIndex(msl->indexOf(CaAddW));
        }
    } else if(action == 1){
        msl->setCurrentIndex(msl->indexOf(EditW));
    } else if(action == 2){
        msl->setCurrentIndex(msl->indexOf(DeleteW));
    }
}

void MainClass::DeAddAct()
{
    QString id = didle->text();
    if(id!="") console->start(program, QStringList() << "division" << "add" << id);
}

void MainClass::OfAddAct()
{
    QString id = oidle->text();
    QString sn = osnle->text();
    QString fn = ofnle->text();
    QString tn = otnle->text();
    QString iddiv = oidivle->text();
    if(iddiv != "" && id != "" && sn != "" && fn != "" && tn != ""){
        QStringList List;
        List << "oficer" << "add" << id << sn << fn << tn << iddiv;
        console->start(program, List);
    } else if (id != "" && sn != "" && fn != "" && tn != ""){
        QStringList List;
        List << "oficer" << "add" << id << sn << fn << tn;
        console->start(program, List);
    } else {
        ErrorAct();
    }
    TableUpdate();
}

void MainClass::CaAddAct()
{
    QString id = cidle->text();
    QString sn = csnle->text();
    QString fn = cfnle->text();
    QString tn = ctnle->text();
    QString iddiv = cidivle->text();
    QStringList List;
    List << "cadet" << "add" << id << sn << fn << tn << iddiv;
    if(iddiv != "" && id != "" && sn != "" && fn != "" && tn != "") console->start(program, List);
    else ErrorAct();
    TableUpdate();
}

void MainClass::ChooseAct()
{
    choosedId = eidele->text();
    if(choosedId!=""){
        if(docCB->currentIndex() == 0){
            SEditW = new QWidget();
            old = new QBoxLayout(QBoxLayout::TopToBottom);
            edidlo = new QBoxLayout(QBoxLayout::TopToBottom);
            edidlo->addWidget(edidl);
            edidlo->addWidget(edidle);
            edidlo->setSpacing(0);

            edidolo = new QBoxLayout(QBoxLayout::TopToBottom);
            edidolo->addWidget(edidol);
            edidolo->addWidget(edidole);
            edidolo->setSpacing(0);

            epblo = new QBoxLayout(QBoxLayout::TopToBottom);
            epblo->addWidget(editPB);
            epblo->addWidget(ecancelPB);
            epblo->addStretch(1);

            old->addLayout(edidlo);
            old->addStretch(1);
            old->addLayout(edidolo);
            old->addStretch(1);
            old->addLayout(epblo);

            SEditW->setLayout(old);
            msl->addWidget(SEditW);
        } else if(docCB->currentIndex() == 1 || docCB->currentIndex() == 2){
            SEditW = new QWidget();
            old = new QBoxLayout(QBoxLayout::TopToBottom);
            edidlo = new QBoxLayout(QBoxLayout::TopToBottom);
            edidlo->addWidget(edidl);
            edidlo->addWidget(edidle);
            edidlo->setSpacing(0);

            esnlo = new QBoxLayout(QBoxLayout::TopToBottom);
            esnlo->addWidget(esnl);
            esnlo->addWidget(esnle);
            esnlo->setSpacing(0);

            efnlo = new QBoxLayout(QBoxLayout::TopToBottom);
            efnlo->addWidget(efnl);
            efnlo->addWidget(efnle);
            efnlo->setSpacing(0);

            etnlo = new QBoxLayout(QBoxLayout::TopToBottom);
            etnlo->addWidget(etnl);
            etnlo->addWidget(etnle);
            etnlo->setSpacing(0);

            eidivlo = new QBoxLayout(QBoxLayout::TopToBottom);
            eidivlo->addWidget(eidivl);
            eidivlo->addWidget(eidivle);
            eidivlo->setSpacing(0);

            epblo = new QBoxLayout(QBoxLayout::TopToBottom);
            epblo->addWidget(editPB);
            epblo->addWidget(ecancelPB);
            epblo->addStretch(1);

            old->addLayout(edidlo);
            old->addStretch(1);
            old->addLayout(esnlo);
            old->addStretch(1);
            old->addLayout(efnlo);
            old->addStretch(1);
            old->addLayout(etnlo);
            old->addStretch(1);
            old->addLayout(eidivlo);
            old->addStretch(1);
            old->addLayout(epblo);
            SEditW->setLayout(old);
            msl->addWidget(SEditW);
        }
        msl->setCurrentIndex(msl->indexOf(SEditW));
    }
}

void MainClass::CancelAct()
{
    msl->setCurrentWidget(EditW);
    msl->removeWidget(SEditW);
}

void MainClass::EditAct()
{
    QString tmp;
    if(docCB->currentIndex() == 0){
        tmp = edidle->text();
        if(tmp != ""){
            QStringList List;
            List << "division" << "edit" << choosedId << "id" << tmp;
            console->start(program, List);
            choosedId = tmp;
        }
        tmp = edidole->text();
        if(tmp != ""){
            QStringList List;
            List << "division" << "edit" << choosedId << "idOf" << tmp;
            console->start(program, List);
        }
    } else if(docCB->currentIndex() == 1){
        tmp = edidle->text();
        if(tmp != ""){
            QStringList List;
            List << "oficer" << "edit" << choosedId << "id" << tmp;
            console->start(program, List);
            choosedId = tmp;
        }
        tmp = esnle->text();
        if(tmp != ""){
            QStringList List;
            List << "oficer" << "edit" << choosedId << "secondName" << tmp;
            console->start(program, List);
        }
        tmp = efnle->text();
        if(tmp != ""){
            QStringList List;
            List << "oficer" << "edit" << choosedId << "firstName" << tmp;
            console->start(program, List);
        }
        tmp = etnle->text();
        if(tmp != ""){
            QStringList List;
            List << "oficer" << "edit" << choosedId << "thirdName" << tmp;
            console->start(program, List);
        }
        tmp = eidivle->text();
        if(tmp != ""){
            QStringList List;
            List << "oficer" << "edit" << choosedId << "idDiv" << tmp;
            console->start(program, List);
        }
    } else if(docCB->currentIndex() == 2){
        tmp = edidle->text();
        if(tmp != ""){
            QStringList List;
            List << "cadet" << "edit" << choosedId << "id" << tmp;
            console->start(program, List);
            choosedId = tmp;
        }
        tmp = esnle->text();
        if(tmp != ""){
            QStringList List;
            List << "cadet" << "edit" << choosedId << "secondName" << tmp;
            console->start(program, List);
        }
        tmp = efnle->text();
        if(tmp != ""){
            QStringList List;
            List << "cadet" << "edit" << choosedId << "firstName" << tmp;
            console->start(program, List);
        }
        tmp = etnle->text();
        if(tmp != ""){
            QStringList List;
            List << "cadet" << "edit" << choosedId << "thirdName" << tmp;
            console->start(program, List);
        }
        tmp = eidivle->text();
        if(tmp != ""){
            QStringList List;
            List << "cadet" << "edit" << choosedId << "idDiv" << tmp;
            console->start(program, List);
        }
    }
    TableUpdate();
    CancelAct();
}

void MainClass::DeleteAct()
{
    int block = docCB->currentIndex();
    QString id = didele->text();
    if(block == 0){
        QStringList List;
        List << "division" << "delete" << id;
        console->start(program, List);
    } else if(block == 1){
        QStringList List;
        List << "oficer" << "delete" << id;
        console->start(program, List);
    } else if(block == 2){
        QStringList List;
        List << "cadet" << "delete" << id;
        console->start(program, List);
    }
    TableUpdate();
}
