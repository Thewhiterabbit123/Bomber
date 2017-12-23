/********************************************************************************
** Form generated from reading UI file 'menuwidgetui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGETUI_H
#define UI_MENUWIDGETUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *quitButton;
    QWidget *backgroundWidget;
    QWidget *gameNameWidget;
    QPushButton *goToGameButton;
    QLineEdit *nickNameLineEdit;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menu->sizePolicy().hasHeightForWidth());
        menu->setSizePolicy(sizePolicy);
        menu->setMinimumSize(QSize(800, 600));
        menu->setMaximumSize(QSize(800, 600));
        menu->setAutoFillBackground(false);
        menu->setStyleSheet(QStringLiteral("background-image:url(:/images/background.png);"));
        quitButton = new QPushButton(menu);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setGeometry(QRect(-20, -30, 181, 121));
        quitButton->setMouseTracking(false);
        quitButton->setContextMenuPolicy(Qt::NoContextMenu);
        quitButton->setLayoutDirection(Qt::RightToLeft);
        quitButton->setAutoFillBackground(false);
        quitButton->setStyleSheet(QStringLiteral("background-image: url(:/images/exit.png); border: none; background-repeat: no-repeat"));
        quitButton->setInputMethodHints(Qt::ImhNone);
        backgroundWidget = new QWidget(menu);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));
        backgroundWidget->setGeometry(QRect(0, 0, 801, 611));
        gameNameWidget = new QWidget(backgroundWidget);
        gameNameWidget->setObjectName(QStringLiteral("gameNameWidget"));
        gameNameWidget->setGeometry(QRect(210, 30, 381, 111));
        gameNameWidget->setStyleSheet(QStringLiteral("background-image: url(:/images/gameName.png); border: none;"));
        goToGameButton = new QPushButton(backgroundWidget);
        goToGameButton->setObjectName(QStringLiteral("goToGameButton"));
        goToGameButton->setGeometry(QRect(192, 230, 431, 141));
        goToGameButton->setAutoFillBackground(false);
        goToGameButton->setStyleSheet(QStringLiteral("background-image: url(:/images/nameEnter.png); border: none; background-repeat: no-repeat"));
        nickNameLineEdit = new QLineEdit(backgroundWidget);
        nickNameLineEdit->setObjectName(QStringLiteral("nickNameLineEdit"));
        nickNameLineEdit->setGeometry(QRect(242, 280, 301, 51));
        QFont font;
        font.setPointSize(26);
        font.setItalic(false);
        nickNameLineEdit->setFont(font);
        nickNameLineEdit->setAutoFillBackground(false);
        nickNameLineEdit->setStyleSheet(QStringLiteral("border: none; background: rgba(255, 255, 255, 0);"));
        backgroundWidget->raise();
        quitButton->raise();

        retranslateUi(menu);
        QObject::connect(quitButton, SIGNAL(clicked()), menu, SLOT(close()));

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Bomber", 0));
        quitButton->setText(QString());
        goToGameButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGETUI_H
