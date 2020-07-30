#include "objeto.h"

int Objeto::getAceleraciony() const
{
    return aceleraciony;
}

void Objeto::setAceleraciony(int value)
{
    aceleraciony = value;

}

Objeto::Objeto()
{

}

Objeto::Objeto(int x, int y, int r, int acely, QString rt)
{
    posx=x;
    posy=y;
    radio=r;
    ruta=rt;
    aceleraciony=acely;
    setPos(posx,posy);
}

int Objeto::getR()
{
    return radio;
}

void Objeto::setR(int r)
{
    radio=r;
}


int Objeto::getPosx()
{
    return posx;
}

void Objeto::setPosx(int  px)
{
    posx=px;
}

int Objeto::getPosy()
{
    return posy;
}

void Objeto::setPosy(int py)
{
    posy = py;

}
void Objeto::subir()
{
     setPos(x(),y()-5);
}

void Objeto::bajar()
{
    setPos(x(),y()+5);
}

void Objeto::derecha()
{
    setPos(x()+5,y());
}

void Objeto::izquierda()
{
    setPos(x(),y());
}

void Objeto::ActualizarPosicion()
{
   // posx=posx*aceleraciony;


     setPos(x(),y()+30);




}

void Objeto::cambiodireccion()
{
    setPos(x(),y()-30);
}

QRectF Objeto::boundingRect() const
{
     return QRectF(-radio,-radio,2*radio,2*radio);

}

void Objeto::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  /*  QPixmap pixmap;

    pixmap.load(ruta);

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());*/
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}
