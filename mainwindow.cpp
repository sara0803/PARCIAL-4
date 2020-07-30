#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString info;                       //String para leer los datos del archivo


    h_limit=2000;                   //Asigna los valores leidos el archivo
    v_limit=1000;

    timer=new QTimer(this);
    scene=new QGraphicsScene(this);
    timer2=new QTimer(this);

    scene->setSceneRect(-h_limit/2,-v_limit/2,h_limit,v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);

    ui->centralwidget->adjustSize();







    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(ActualizarO()));
    timer->start(dt);

    timer2->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT((ActualizarO())));
   // timer2->start(dt);




         LISTA.append(new Graficar(0,0,0,0,50000,200));
        LISTA.append(new Graficar(-5000,0,0,-2,70,70));
        LISTA.append(new Graficar(5000,0,0,-2,70,70));    //Planetas agregados directamente
        LISTA.append(new Graficar(0,-5000,2,0,70,70));
        LISTA.append(new Graficar(0,5000,-2,0,70,70));

    for(int i=0;i<LISTA.size();i++)
    {
        LISTA.at(i)->Actualizar();
        scene->addItem(LISTA.at(i));
    }


}

MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;
}

void MainWindow::actualizar()
{

    for (int i=0; i<LISTA.size();i++)
    {
        for(int j=0; j<LISTA.size();j++)
        {
            if(i!=j)
            {
                LISTA.at(i) -> getEsf() -> Acacelx(*(LISTA.at(j)->getEsf()));


                LISTA.at(i) -> getEsf() -> Acacely(*(LISTA.at(j)->getEsf()));
            }
        }
    }
    for(int i=0;i<LISTA.size();i++)
    {
        LISTA.at(i)->Actualizar();


    }
    //actualiza cada dato
}








//función que guarda todo en un archivo
void MainWindow::GUARDARDATOS(double posx, double posy,   double vx, double vy, double masa, double radio, int planetas)
{


    QString numS, posxS, posyS,mass,rad,vvx,vvy, w,planets;


    posxS=QString::number(posx);
    posyS=QString::number(posy);
    mass=QString::number(masa);
    rad=QString::number(radio);
    vvx=QString::number(vx);
    vvy=QString::number(vy);
    planets=QString::number(planetas);
    w=" PLANETA NUMERO: "+planets+"     "+posxS+"    "+posyS+"    "+mass+"    "+rad+"    "+vvx+"    "+vvy+ '\n' ;

    QFile PLANETAS("PLANETAS.txt");


    if(PLANETAS.open(QIODevice::Append | QIODevice::Text)){
            QTextStream datosArchivo(&PLANETAS);


            datosArchivo << w<< endl;

        }
        PLANETAS.close();
}


//evento al pulsar el botón de agregar planeta
void MainWindow::on_pushButton_2_clicked()
{
    timer->start(dt);
    QString numS, posxS, posyS,mass,rad,vvx,vvy, text;
    planetas=planetas+1;
    /*posx= ui->spinBox->value();
    posy= ui->spinBox_2->value();
    vx= ui->spinBox_3->value();
    vy= ui->spinBox_4->value();
    masa= ui->spinBox_5->value();
    radio= ui->spinBox_6->value();*/

    LISTA.push_back(new Graficar(posx,posy,vx,vy, masa,radio));
    scene->addItem(LISTA.back());
    GUARDARDATOS( posx, posy,  vx,  vy,  masa,  radio, planetas);
    for(int i=0;i<LISTA.size();i++)
    {
            LISTA.at(i)->Actualizar();
            scene->addItem(LISTA.at(i));
    }
}

void MainWindow::on_INICIAR_clicked()
{
    timer2->start(1);
    int posicionx=posicionaleatoria();
    int aceleracion=aceleracionaleatoria();
    /*caida=new Objeto(posicionx,-200,5,aceleracion, ":/IMAGENES/BOLA DE FUEGO.png");
    scene->addItem(caida);
    caida=new Objeto(posicionx,-200,5,aceleracion, ":/IMAGENES/BOLA DE FUEGO.png");
    scene->addItem(caida);
    caida=new Objeto(posicionx,-200,5,aceleracion, ":/IMAGENES/BOLA DE FUEGO.png");
    scene->addItem(caida);*/

    cuerpos.append(new Objeto(posicionx,-200,5,aceleracion, ":/IMAGENES/BOLA DE FUEGO.png"));
    cuerpos.append(new Objeto(posicionx,-200,5,aceleracion, ":/IMAGENES/BOLA DE FUEGO.png"));
    cuerpos.append(new Objeto(posicionx,-200,5,aceleracion, ":/IMAGENES/BOLA DE FUEGO.png"));    //Planetas agregados directamente




}

int MainWindow::posicionaleatoria()
{
    int num, c;
        srand(time(NULL));

        for(c = -300; c <= 300; c++)
        {
            num = -300 + rand() % (301 - (-300));

        }

        return num;
}

int MainWindow::aceleracionaleatoria()
{
    int num, c;
        srand(time(NULL));

        for(c = 1; c <= 10; c++)
        {
            num = 1 + rand() % (11 - 1);

        }

        return num;
}

void MainWindow::ActualizarO()
{


    for(int i=0;i<cuerpos.size();i++)
    {

        scene->addItem(cuerpos.at(i));
        cuerpos.at(i)->ActualizarPosicion();



    }

}


