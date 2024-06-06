#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QVector>
#include "personaje.h"
#include "fantasma.h"
#include "monedas.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*);

private slots:
    void actualizarEscena();

private:
    QTimer* timer = nullptr;
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Personaje* personaje;
    Fantasma* fantasma;
    QVector<Monedas*> monedas;
    int contColisiones = 0;
};
#endif // MAINWINDOW_H
