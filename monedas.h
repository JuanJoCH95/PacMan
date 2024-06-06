#ifndef MONEDAS_H
#define MONEDAS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class Monedas : public QObject, public QGraphicsItem {
    public:
        explicit Monedas(QObject *parent = nullptr);
        QRectF boundingRect() const;
        void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

    private:
        qreal rowPixmap, colPixmap, width, height;
        QPixmap* stripe;
};

#endif // MONEDAS_H
