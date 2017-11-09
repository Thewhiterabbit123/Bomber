#include "bombergame.h"

BomberGame::BomberGame(QWidget* parent): QGraphicsView(parent)
{
    allScreens = new QStackedLayout();
    menu = new MenuWidget();
    game = new GameWidget();
    //pageComboBox = new QComboBox();
    allScreens -> addWidget(menu);
    //pageComboBox->addItem(tr("menu"));
    allScreens -> addWidget(game);
    //pageComboBox->addItem(tr("game"));
    setLayout(allScreens);

    //connect(pageComboBox, SIGNAL(activated(int)), allScreens, SLOT(setCurrentIndex(int));

    connect(menu, SIGNAL(setScreen(int)), allScreens, SLOT(setCurrentIndex(int)));
    connect(game, SIGNAL(setScreen(int)), allScreens, SLOT(setCurrentIndex(int)));
    /*
    QStackedLayout* qslo;
    QWidget* mainMenu, * game;
    QVBoxLayout* pbly;
    QPushButton* gth, * myc;
    QComboBox* pageComboBox = new QComboBox();
    qslo = new QStackedLayout();
    mainMenu = new QWidget();
    game = new QWidget();
    pbly = new QVBoxLayout();
    gth = new QPushButton("GO TO HELL");
    myc = new QPushButton("Make you cry!");
    pbly->addWidget(gth);
    pbly->addWidget(myc);
    mainMenu->setLayout(pbly);
    qslo->setObjectName(tr("currentLayout"));
    qslo->addWidget(mainMenu);
    qslo->addWidget(game);
    pageComboBox->addItem(tr("Page 1"));
    pageComboBox->addItem(tr("Page 2"));
    connect(pageComboBox, SIGNAL(activated(int)), qslo, SLOT(setCurrentIndex(int)));
    //emit pageComboBox->activated(0);
    //qslo->setCurrentIndex(0);
    setLayout(qslo);
    emit pageComboBox->activated(1);
    //qslo->setCurrentIndex(0);
    */

}
