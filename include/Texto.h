#ifndef Texto_h
#define Texto_h

#include "Arduino.h"

#include "TftPrinter.h"

#include "Color.h"
#include "Coordenada.h"
#include "Free_Fonts.h"

class Texto {

    public:
        Texto(TftPrinter* ptrTFT, char* txt, Color letra, uint8_t tamano = 1);
        Texto(char* txt, Color letra, uint8_t tamano = 1);
        Texto();
        ~Texto();

        void Imprimir(Coordenada posicion, uint8_t modo = 0);

        void Txt(char* txt);
        char* Txt() const;

        void ColorLetra(uint32_t color);
        Color ColorLetra() const;

        void ColorFondo(uint32_t color);
        // Color getFondo();

        void Tamano(uint8_t tamano);
        Coordenada Tamano() const;

    private:
        TftPrinter *ptrTFT;
        char* mTxt;
        Color mLetra, mFondo;
        uint8_t mTamano;
        int16_t ultimaCadenaX = 0; 
        int16_t ultimaCadenaY = 0;
};

#endif