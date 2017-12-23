/********************************************************************************
** Form generated from reading UI file 'gamewidgetui.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGETUI_H
#define UI_GAMEWIDGETUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QWidget *background;
    QPushButton *goToMenuButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *bombCountWidget;
    QLineEdit *lineEdit;
    QWidget *hpCountWidget;
    QLineEdit *lineEdit_2;
    QWidget *field;
    QWidget *widgetPlayer;

    void setupUi(QWidget *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QStringLiteral("game"));
        game->resize(800, 600);
        game->setAutoFillBackground(false);
        game->setStyleSheet(QStringLiteral("background-image: url(:/images/background.png); width: 800px; height: 600px;"));
        background = new QWidget(game);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 800, 600));
        goToMenuButton = new QPushButton(background);
        goToMenuButton->setObjectName(QStringLiteral("goToMenuButton"));
        goToMenuButton->setGeometry(QRect(-20, -30, 181, 121));
        goToMenuButton->setAutoFillBackground(false);
        goToMenuButton->setStyleSheet(QStringLiteral("background-image: url(:/images/exit.png); border:none"));
        horizontalLayoutWidget = new QWidget(background);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(470, -20, 341, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bombCountWidget = new QWidget(horizontalLayoutWidget);
        bombCountWidget->setObjectName(QStringLiteral("bombCountWidget"));
        bombCountWidget->setStyleSheet(QStringLiteral("background-image: url(:/images/bombCount.png)"));
        lineEdit = new QLineEdit(bombCountWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(74, 33, 51, 31));
        QFont font;
        font.setPointSize(20);
        lineEdit->setFont(font);
        lineEdit->setAutoFillBackground(false);
        lineEdit->setStyleSheet(QStringLiteral("background: rgba(255, 255, 255, 0);"));
        lineEdit->setMaxLength(2);
        lineEdit->setFrame(false);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setReadOnly(true);
        lineEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(bombCountWidget);

        hpCountWidget = new QWidget(horizontalLayoutWidget);
        hpCountWidget->setObjectName(QStringLiteral("hpCountWidget"));
        hpCountWidget->setStyleSheet(QStringLiteral("background-image: url(:/images/lives.png)"));
        lineEdit_2 = new QLineEdit(hpCountWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(76, 34, 51, 31));
        lineEdit_2->setFont(font);
        lineEdit_2->setAutoFillBackground(false);
        lineEdit_2->setStyleSheet(QStringLiteral("background: rgba(255, 255, 255, 0);"));
        lineEdit_2->setMaxLength(2);
        lineEdit_2->setFrame(false);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        lineEdit_2->setClearButtonEnabled(false);

        horizontalLayout->addWidget(hpCountWidget);

        field = new QWidget(background);
        field->setObjectName(QStringLiteral("field"));
        field->setGeometry(QRect(20, 90, 750, 484));
        widgetPlayer = new QWidget(background);
        widgetPlayer->setObjectName(QStringLiteral("widgetPlayer"));
        widgetPlayer->setGeometry(QRect(30, 100, 740, 474));
        widgetPlayer->setAutoFillBackground(false);
        widgetPlayer->setStyleSheet(QStringLiteral("background: rgba(255, 255, 255, 0); margin: 0; padding: 0;"));

        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QWidget *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Bomber", 0));
        goToMenuButton->setText(QString());
        lineEdit->setText(QApplication::translate("game", "10", 0));
        lineEdit_2->setText(QApplication::translate("game", "10", 0));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGETUI_H
