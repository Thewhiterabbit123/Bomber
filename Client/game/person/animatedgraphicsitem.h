#ifndef ANIMATEDGRAPHICSITEM_H
#define ANIMATEDGRAPHICSITEM_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

#include "shared/animationPool/animationpool.h"
#include "game/person/animations_enum.h"

class AnimatedGraphicsItem : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
public:
  enum Mode { Once, Loop };
  AnimatedGraphicsItem(QObject *parent);
signals:
  void animationFinished();
protected:
  void animation(ActorActions animationId, Mode mode, bool randomStartFrame = false, int framerate = DefaultFramerate, int hide = false);
private slots:
  void on_timerTick();
private:
  QTimer m_timer;

  QVector<QPixmap*> *m_frames;
  int m_nFrames;
  int m_curFrameIndex;
  int hidable;
  Mode m_mode;

  const static int DefaultFramerate = 12;
};

#endif // ANIMATEDGRAPHICSITEM_H
