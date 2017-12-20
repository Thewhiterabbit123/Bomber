#ifndef BOXWIDGET_H
#define BOXWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <memory>
#include "shared/imagePool/imagepool.h"
#include "game/box/imagebox.h"

class BoxWidget : public QWidget
{
    Q_OBJECT
public:
    BoxWidget(){}

    BoxWidget(BoxWidget* copying){
        this->p_imagePool = copying->p_imagePool;
    }

    explicit BoxWidget(ImageBox iconNumber, std::shared_ptr<ImagePool<ImageBox>> pool, QWidget *parent = 0): QWidget(parent), p_imagePool(pool){
        setImage(iconNumber);
    }

private:
    std::shared_ptr<ImagePool<ImageBox>> p_imagePool;
signals:

public slots:
    void setImage(ImageBox iconNumber){
        QPalette boxPalette;
        boxPalette.setBrush((this)->backgroundRole(), QBrush(*(p_imagePool->get(iconNumber))));
        (this)->setPalette(boxPalette);
    }
};

#endif // BOXWIDGET_H
