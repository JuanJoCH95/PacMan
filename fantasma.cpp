#include "fantasma.h"

Fantasma::Fantasma(QObject *parent) : QObject{parent} {
    rowPixmap = 0;
    colPixmap = 0;
    posX = 0;
    posY = 0;
    width = 46.25;
    height = 60;
    stripe = new QPixmap(":/Imagenes/fantasma.png");
    timer = new QTimer;
    timer->start(200);

    connect(timer, &QTimer::timeout, this, &Fantasma::move);
}

void Fantasma::setPosition(float a, float b) {
    posX = a;
    posY = b;
    setPos(getPosX(), getPosY());
}

void Fantasma::setVelocity(float a, float b) {
    velX = a;
    velY = b;
}

void Fantasma::move() {
    posX += getVelX()*DT;
    posY += getVelY()*DT;
    setPos(getPosX(), getPosY());
}

void Fantasma::checkCollision() {
    if(getPosX() < getRadio() || getPosX() > HORZLIM - getRadio()) {
        setVelocity(-1*getVelX(), getVelY());
    }

    if(getPosY() < getRadio() || getPosY() > VERTLIM - getRadio()) {
        setVelocity(getVelX(), -1*getVelY());
    }
}

QRectF Fantasma::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Fantasma::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    QPixmap scaled = stripe->scaled(QSize(184, 240));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
}

float Fantasma::getPosX() {
    return posX;
}

float Fantasma::getPosY() {
    return posY;
}

float Fantasma::getVelX() {
    return velX;
}

float Fantasma::getVelY() {
    return velY;
}

float Fantasma::getRadio() {
    return radio;
}
