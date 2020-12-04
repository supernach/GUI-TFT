#ifndef Rectangulo_h
#define Rectangulo_h

#include "Arduino.h"
#include "stdio.h"

#include "TftPrinter.h"

#include "Color.h"
#include "Coordenada.h"


class Rectangulo {
    public:
        Rectangulo();
        ~Rectangulo();

        void Dibujar(TftPrinter *tft);

        void Posicion(uint32_t x, uint32_t y);
        Coordenada Posicion() const;

        void Tamano(uint32_t x, uint32_t y);
        Coordenada Tamano() const;

        void ColorFondo(uint32_t color);

        void ColorBorde(uint32_t color);

        void Radio(uint32_t radio);

    private:
        uint32_t mRadio;
        Coordenada mPosicion;
        Coordenada mTamano;
        Color mBorde;
        Color mFondo;
};





#endif