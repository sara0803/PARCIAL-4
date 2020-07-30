#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QFile>
#include <string.h>
#include <objeto.h>
#include "planeta.h"
#include "graficar.h"
#include <iostream>
#include <fstream>
#include <QDebug>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actualizar();


    void GUARDARDATOS(double x, double y, double vx, double vy, double m, double r, int plan);


    void on_pushButton_2_clicked();

    void on_INICIAR_clicked();

    int posicionaleatoria();

    int aceleracionaleatoria();

    void ActualizarO();

     void rebote();


private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    QGraphicsScene *scene;
    int h_limit;
    int v_limit;
    QList<Graficar*>LISTA;
    QList<Objeto*>cuerpos;
    double masa;
    double posx;
    double posy;
    double radio;
    double vx;
    double vy;
    int planetas=0;
    Graficar *P;
    Objeto *caida;

};

#endif // MAINWINDOW_H
