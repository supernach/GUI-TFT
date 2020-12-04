#include "Arduino.h"
#include "Rectangulo.h"

Rectangulo::~Rectangulo()
{
    
}

Rectangulo::Rectangulo()
{
    this->ColorBorde(TFT_VIOLET);
    this->ColorFondo(TFT_GREEN);
    this->Posicion(1,1);
    this->Tamano(30,30);
    this->Radio(2);
}

void Rectangulo::Posicion(uint32_t x, uint32_t y)
{
    this->mPosicion.X(x);
    this->mPosicion.Y(y);
}
void Rectangulo::Tamano(uint32_t x, uint32_t y)
{
    this->mTamano.X(x);
    this->mTamano.Y(y);
}
void Rectangulo::ColorFondo(uint32_t color)
{
    this->mFondo.aColor(color);
}
void Rectangulo::ColorBorde(uint32_t color)
{
    this->mBorde.aColor(color);
}
void Rectangulo::Radio(uint32_t radio)
{
    this->mRadio = radio;
}

Coordenada Rectangulo::Posicion() const
{
    return this->mPosicion;
}
Coordenada Rectangulo::Tamano() const
{
    return this->mTamano;
}

void Rectangulo::Dibujar(TftPrinter *tft)
{
    tft->Rectangulo(this->mPosicion.X(), this->mPosicion.Y(), this->mTamano.X(), this->mTamano.Y(), this->mBorde.aColor(), this->mRadio, this->mFondo.aColor());
}