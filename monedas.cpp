#include "monedas.h"

Monedas::Monedas(QObject *parent) : QObject{parent} {
    width = 24;
    height = 24;
    stripe = new QPixmap(":/Imagenes/moneda.png");
}

QRectF Monedas::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Monedas::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap scaled = stripe->scaled(QSize(24, 24));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
}
