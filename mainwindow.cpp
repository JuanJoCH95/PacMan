#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    personaje = new Personaje;
    fantasma = new Fantasma;
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);
    monedas.push_back(new Monedas);

    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width() + 5, scene->height() + 5);
    this->resize(ui->graphicsView->width() + 100, ui->graphicsView->height() + 100);

    auto background = QImage(":/Imagenes/fondo.jpg");
    auto scaledBack = background.scaled(800, 600);
    ui->graphicsView->setBackgroundBrush(scaledBack);

    music->setMedia(QUrl("qrc:/Sound/Sonido8bts.wav"));
    music->play();

    scene->addItem(personaje);
    personaje->setPos(0,0);

    scene->addItem(fantasma);
    fantasma->setPosition(250,250);
    timer->start(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));

    int ancho = 50, alto = 383, m = 0;
    for(auto e : monedas) {
        scene->addItem(e);
        e->setPos(ancho,alto);
        ancho += 75;

        if(m == 2 || m == 3 || m == 4) {
            alto = 214;
        } else if(m == 6 || m == 7 || m == 8) {
            alto = 500;
        } else {
            alto = 383;
        }
        m+=1;
    }
}

MainWindow::~MainWindow() {
    delete timer;
    delete personaje;
    delete fantasma;
    delete scene;
    delete ui;
    delete music;
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

void MainWindow::actualizarEscena() {
    fantasma->move();
    fantasma->checkCollision();

    QList<QGraphicsItem*> colisionesFantasma = scene->collidingItems(fantasma);
    if(!colisionesFantasma.isEmpty()) {
        for(auto c : colisionesFantasma) {
            Personaje *pacman = dynamic_cast<Personaje*>(c);
            if(pacman) {
                delete fantasma;
                timer->stop();
                music->stop();
                QMessageBox::information(this, "", "GAME OVER!");
                QApplication::quit();
            }
        }
    }

    QList<QGraphicsItem*> colisionesPoint = scene->collidingItems(personaje);
    if(!colisionesPoint.isEmpty()) {
        for(auto c : colisionesPoint) {
            Monedas *moneda = dynamic_cast<Monedas*>(c);
            if(moneda) {
                scene->removeItem(moneda);
                contColisiones++;
            }
        }
    }

    if(contColisiones == 10) {
        delete fantasma;
        timer->stop();
        music->stop();
        QMessageBox::information(this, "", "YOU WIN!");
        QApplication::quit();
    }
}
