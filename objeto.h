#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsItem>
#include <QPainter>
class Objeto  : public QGraphicsItem
{

    int radio;
    int posx, posy;
    int aceleraciony;
    QString ruta;

public:
    Objeto();
    Objeto(int x, int y, int r, int acely, QString ruta);
    int getR();
    void setR(int r);
    int getPosx();
    void setPosx(int px);
    int getPosy();
    void setPosy(int py);
    void subir();
    void bajar();
    void derecha();
    void izquierda();
    void ActualizarPosicion();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    int getAceleraciony() const;
    void setAceleraciony(int value);
};

#endif // OBJETO_H
