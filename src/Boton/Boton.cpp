#include "Arduino.h"

#include "Boton.h"

Boton::~Boton()
{

}

Boton::Boton(TftPrinter *ptrTft, Color fondo, Color borde, Coordenada posicion, Coordenada tamano, Texto texto, Tactil *subject) //: subject_(subject)
{
    this->ptrTFT = ptrTft;
    this->fondo = Color(fondo.aColor());
    this->borde = Color(borde.aColor());

    this->tamano = Coordenada(tamano.X(), tamano.Y());
    this->posicion = Coordenada(posicion.X(), posicion.Y());

    this->texto = Texto(this->ptrTFT, texto.Txt(), texto.ColorLetra());
    this->texto.ColorFondo(this->fondo.aColor());
    
    this->forma = Rectangulo();

    subject->Attach(this);
    
}
/********************************************************************************/

void Boton::setColorFondo(uint32_t color)
{
    this->fondo.aColor(color);
}

void Boton::Dibujar()
{
    /*Serial.println("BtnOriginal::Dibujar()");
     Serial.println(this->posicion.X());
      Serial.println(this->posicion.Y());*/
    this->forma = initForma();
    this->forma.Dibujar(this->ptrTFT);

    ////////// CENTRAR TEXTO ///////////////
    Coordenada centraje = CentrarTexto();

    this->texto.Imprimir(Coordenada(this->posicion.X() + centraje.X(), this->posicion.Y() + centraje.Y()), 2);
}

Rectangulo Boton::initForma()
{
    Rectangulo forma = Rectangulo();
    forma.Posicion(this->posicion.X(), this->posicion.Y());
    forma.Tamano(this->tamano.X(), this->tamano.Y());
    forma.ColorBorde(this->borde.aColor());
    forma.ColorFondo(this->fondo.aColor());
    forma.Radio(2);

    return forma;
}


//METODO PATRON OBSERVER. EL TACTIL ME NOTIFICA
void Boton::Update(const String &message_from_subject, uint16_t coordX, uint16_t coordY) 
{ 
    this->message_from_subject_ = message_from_subject;

    if(this->pulsado(coordX, coordY))
    {
        this->estado = 1;
    }
    else
    {
        this->estado = 0;
    }
    
}

void Boton::Subscribirse(Tactil *subject)
{
    subject->Attach(this);
}

void Boton::Desubscribirse(Tactil *subject)
{
    subject->Detach(this);
}

uint8_t Boton::pulsado(uint16_t coordX, uint16_t coordY)
{

    if( (coordX > this->posicion.X()) && (coordX < (this->posicion.X() + this->tamano.X()) ) )
    {
        if( (coordY > this->posicion.Y()) && (coordY < (this->posicion.Y() + this->tamano.Y()) ) )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    
}

Coordenada Boton::CentrarTexto()
{
    int16_t absLibreI = this->tamano.X() - this->texto.Tamano().X();
    int32_t pxIzquierda = absLibreI/2;
    //int16_t pxIzquierda = 0;

    int16_t absLibreA = this->tamano.Y() - this->texto.Tamano().Y();
    int32_t pxArriba = absLibreA/2;

    return Coordenada(pxIzquierda, pxArriba);
}