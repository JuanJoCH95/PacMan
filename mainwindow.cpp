#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    personaje = new Personaje;

    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width() + 5, scene->height() + 5);
    this->resize(ui->graphicsView->width() + 100, ui->graphicsView->height() + 100);

    auto background = QImage(":/Imagenes/fondo.jpg");
    auto scaledBack = background.scaled(800, 600);
    ui->graphicsView->setBackgroundBrush(scaledBack);

    scene->addItem(personaje);
    personaje->setPos(0,0);
}

MainWindow::~MainWindow() {
    delete personaje;
    delete scene;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if(personaje != nullptr) {
        if(event->key() == Qt::Key_A) {
            personaje->moveLeft();
        }
        else if(event->key() == Qt::Key_D) {
            personaje->moveRight();
        }
        else if(event->key() == Qt::Key_W) {
            personaje->moveUp();
        }
        else if(event->key() == Qt::Key_S) {
            personaje->moveDown();
        }
    }
}
