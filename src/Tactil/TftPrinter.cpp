#include "Arduino.h"

#include "TftPrinter.h"

TftPrinter::TftPrinter(TFT_eSPI *tft)
{
    this->ptrTFT = tft;
}

TftPrinter::~TftPrinter()
{

}

void TftPrinter::initTFT()
{
    this->ptrTFT->begin();
    this->ptrTFT->setRotation(2);

    //VALORES CALIBRACION
    uint16_t calData[8][5] = 
    {
        { 256, 3541, 420, 3495, 4 }, //Rotation=0
        { 452, 3451, 275, 3510, 7 }, //Rotation=1
        { 310, 3500, 402, 3503, 2 }, //Rotation=2
        { 405, 3458, 285, 3242, 1 }, //Rotation=3
        { 332, 3466, 397, 3509, 0 }, //Rotation=4
        { 408, 3491, 329, 3487, 3 }, //Rotation=5
        { 309, 3477, 397, 3502, 6 }, //Rotation=6
        { 391, 3491, 285, 3364, 5 }  //Rotation=7
    };

    this->ptrTFT->setTouch(calData[this->ptrTFT->getRotation()]);
}

/********* METODOS PUBLICOS ************/

void TftPrinter::Rectangulo(int32_t x, int32_t y, int32_t w, int32_t h, int32_t colorBorde, int32_t radio, int32_t colorFondo)
{
    if(colorFondo != 0)
    {
        this->fillRoundRect(x, y, w, h, radio, colorFondo);
    }

    this->drawRoundRect(x, y, w, h, radio, colorBorde);
}

void TftPrinter::initLetra(const GFXfont *f)
{
    this->setFreeFont(f);
}

int16_t TftPrinter::AlturaLetra(int16_t fuente)
{
    return this->fontHeight(fuente);
}

int16_t TftPrinter::AnchuraTexto(const char *texto)
{
    return this->textWidth(texto);
}

void TftPrinter::colorLetra(uint16_t color)
{
    this->setTextColor(color);
}

void TftPrinter::Escribir(const char *texto, int32_t x, int32_t y, uint8_t fuente)
{
    this->drawString(texto, x, y, fuente);
}

void TftPrinter::LimpiarPantalla(uint32_t color)
{
    this->fillScreen(color);
}



/******** METODOS PRIVADOS **************/

void TftPrinter::fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radio, int32_t colorFondo)
{
    this->ptrTFT->fillRoundRect(x, y, w, h, radio, colorFondo);
}

void TftPrinter::drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radio, int32_t colorBorde)
{
    this->ptrTFT->drawRoundRect(x, y, w, h, radio, colorBorde);
}

void TftPrinter::setFreeFont(const GFXfont *f)
{
    this->ptrTFT->setFreeFont(f);
}

int16_t TftPrinter::fontHeight(int16_t fuente)
{
    return this->ptrTFT->fontHeight(fuente);
}

int16_t TftPrinter::textWidth(const char *texto)
{
    return this->ptrTFT->textWidth(texto);
}

void TftPrinter::setTextColor(uint16_t color)
{
    this->ptrTFT->setTextColor(color);
}

void TftPrinter::drawString(const char *texto, int32_t x, int32_t y, uint8_t fuente)
{
    this->ptrTFT->drawString(texto,x, y, fuente);
}

void TftPrinter::fillScreen(uint32_t color)
{
    this->ptrTFT->fillScreen(color);
}