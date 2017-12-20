#ifndef ACTIONWIDGET_H
#define ACTIONWIDGET_H

#include <QWidget>
#include <QVector>
#include <memory>
#include "game/box/boxwidget.h"
#include "shared/imagePool/imagepool.h"
#include "game/box/imagebox.h"

class ActionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ActionWidget(QWidget *parent = 0);



signals:

public slots:

private:
    QVector<std::shared_ptr<BoxWidget>> v_boxWidget;
    std::shared_ptr<ImagePool<ImageBox>> boxPool;
};

#endif // ACTIONWIDGET_H
