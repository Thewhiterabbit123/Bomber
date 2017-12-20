#include "actionwidget.h"
#include "QGridLayout"

ActionWidget::ActionWidget(QWidget *parent) : QWidget(parent)
{
    boxPool = std::make_shared<ImagePool<ImageBox>>(new ImagePool<ImageBox>);
    boxPool->load(ImageBox::Box, ":/images/box.png", 38, 38);
    boxPool->load(ImageBox::Ground, ":/images/pass.png", 38, 38);
    boxPool->load(ImageBox::Wall, ":/images/notPass.png", 38, 38);
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 20; j++){
            v_boxWidget.push_back(std::make_shared<BoxWidget>(new BoxWidget(ImageBox::Ground, boxPool, this)));
        }
    }
    QGridLayout* field = new QGridLayout();
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 20; j++){
            field->addWidget(v_boxWidget[i*20+j].get());
        }
    }

    setLayout(field);

}

