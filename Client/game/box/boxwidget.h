#ifndef BOXWIDGET_H
#define BOXWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <memory>
#include <QPainter>
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

    explicit BoxWidget(ImageBox iconNumber, std::shared_ptr<ImagePool<ImageBox>> pool, QWidget *parent = 0): QWidget(parent), p_imagePool(pool), typeNow(iconNumber){
        setMinimumHeight(38);
        setMinimumWidth(38);
        setMaximumHeight(38);
        setMaximumWidth(38);
        setImage(iconNumber);

        connect(this, SIGNAL(imageChanged()), SLOT(repaint()));
    }

private:
    std::shared_ptr<ImagePool<ImageBox>> p_imagePool;
    ImageBox typeNow;

signals:
    void imageChanged();

protected:
    void paintEvent( QPaintEvent *event ){
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawPixmap(rect(), (const QPixmap&)*(p_imagePool.get()->get(this->typeNow).get()));
    }

//public slots:
public:
    void setImage(ImageBox iconNumber){
        typeNow = iconNumber;
        emit imageChanged();
    }
};

#endif // BOXWIDGET_H
