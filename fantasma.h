#ifndef FANTASMA_H
#define FANTASMA_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

const float VERTLIM = 600;
const float HORZLIM = 800;
const float DT = 0.1;

class Fantasma : public QObject, public QGraphicsItem {
    Q_OBJECT
    public:
        explicit Fantasma(QObject *parent = nullptr);
        float getPosX();
        float getPosY();
        float getVelX();
        float getVelY();
        float getRadio();
        void setPosition(float, float);
        void setVelocity(float, float);
        void move();
        void checkCollision();
        QRectF boundingRect() const;
        void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

    private:
        QTimer* timer;
        QPixmap* stripe;
        qreal rowPixmap, colPixmap, width, height;
        float posX;
        float posY;
        float radio = 30;
        float velX = 40;
        float velY = 40;
};

#endif // FANTASMA_H
