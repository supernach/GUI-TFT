#include "Arduino.h"


#include "TftPrinter.h"
#include "Texto.h"
#include "Rectangulo.h"

Texto::~Texto()
{
    
}

Texto::Texto(TftPrinter *ptrTFT, char* txt, Color letra, uint8_t tamano)
{
   
    this->ptrTFT = ptrTFT;

    this->mTxt = txt;
    this->mLetra = Color(letra.aColor());
    
    this->ptrTFT->colorLetra(this->mLetra.aColor());

    this->mFondo = Color(TFT_BLACK);
    this->mTamano = tamano;

   
    this->ptrTFT->initLetra(FF1);
    
    this->ultimaCadenaY = this->ptrTFT->AlturaLetra(GFXFF);
    
    this->ultimaCadenaX = this->ptrTFT->AnchuraTexto(this->Txt());
}

Texto::Texto()
{
    this->Txt("");
    this->mLetra = Color(TFT_TRANSPARENT);
    this->mFondo = Color(TFT_BLACK);
    this->Tamano(1);
}


Texto::Texto(char* txt, Color letra, uint8_t tamano)
{
    this->mTxt = txt;
    this->mLetra = Color(letra.aColor());
    this->mFondo = Color(TFT_BLACK);
    this->Tamano(tamano);
}

void Texto::Txt(char* txt)
{
    this->mTxt = txt;
}
char* Texto::Txt() const
{
    return this->mTxt;
}

void Texto::ColorLetra(uint32_t color)
{
    this->mLetra.aColor(color);
}
Color Texto::ColorLetra() const
{
    return this->mLetra;
}

void Texto::ColorFondo(uint32_t color)
{
    this->mFondo.aColor(color);
}
/*Color Texto::getFondo()
{
    return this->fondo;
}*/

void Texto::Tamano(uint8_t tamano)
{
    this->mTamano = tamano;
}
Coordenada Texto::Tamano() const
{
    return Coordenada(this->ultimaCadenaX, this->ultimaCadenaY);
}


void Texto::Imprimir(Coordenada posicion, uint8_t modo)
{
    this->ptrTFT->colorLetra(this->mLetra.aColor());

    // Aqui volvemos a pintar el fondo del texto por si se actualiza
    if(modo == 1)
    {
        
      
        this->ptrTFT->Rectangulo(posicion.X(), posicion.Y(),this->ultimaCadenaX, this->ultimaCadenaY,this->mFondo.aColor(), 2, this->mFondo.aColor());
    }

    //Escribo el texto en pantalla
    this->ptrTFT->Escribir(this->mTxt, posicion.X(), posicion.Y(), GFXFF);

    /*Serial.println(this->ultimaCadenaX);
        Serial.println(this->ultimaCadenaY);
        Serial.println(" ");
        Serial.println(this->mFondo.aColor());
        Serial.println(" ");*/

    //Guardo el valor de la ultima cadena para usarla al volver a pintar el fondo
    this->ultimaCadenaY = this->ptrTFT->AlturaLetra(GFXFF); //GFXFF
    this->ultimaCadenaX = this->ptrTFT->AnchuraTexto(this->Txt());
}