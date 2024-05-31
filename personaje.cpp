#include "personaje.h"

Personaje::Personaje(QObject *parent) : QObject{parent} {
    rowPixmap = 0;
    colPixmap = 0;
    posX = 0;
    posY = 0;
    width = 46.25;
    height = 60;
    stripe = new QPixmap(":/Imagenes/pacman.png");
    timer = new QTimer;
    timer->start(200);

    connect(timer, &QTimer::timeout, this, &Personaje::actualizarPersonaje);
}

void Personaje::actualizarPersonaje() {
    update(0, 0, width, height);
}

QRectF Personaje::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Personaje::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap scaled = stripe->scaled(QSize(184, 240));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
}

void Personaje::moveLeft() {
    rowPixmap = 120;
    colPixmap += width;

    if(colPixmap >= 184) {
        colPixmap = 0;
    }

    posX -= 20;
    setPos(posX, posY);
}

void Personaje::moveRight() {
    rowPixmap = 60;
    colPixmap += width;

    if(colPixmap >= 184) {
        colPixmap = 0;
    }

    posX += 20;
    setPos(posX, posY);
}

void Personaje::moveUp() {
    rowPixmap = 180;
    colPixmap += width;

    if(colPixmap >= 184) {
        colPixmap = 0;
    }

    posY -= 20;
    setPos(posX, posY);
}

void Personaje::moveDown() {
    rowPixmap = 0;
    colPixmap += width;

    if(colPixmap >= 184) {
        colPixmap = 0;
    }

    posY += 20;
    setPos(posX, posY);
}
