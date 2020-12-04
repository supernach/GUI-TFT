#ifndef TftPrinter_h
#define TftPrinter_h

#include "TFT_eSPI.h"

class TftPrinter
{
private:
    /* data */
    void fillRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radio, int32_t color);
    void drawRoundRect(int32_t x, int32_t y, int32_t w, int32_t h, int32_t radio, int32_t color);
    void setFreeFont(const GFXfont *f);
    int16_t fontHeight(int16_t fuente);
    void setTextColor(uint16_t color);
    void drawString(const char *texto, int32_t x, int32_t y, uint8_t fuente);
    int16_t textWidth(const char *texto);
    void fillScreen(uint32_t color);

public:
    TftPrinter(TFT_eSPI *tft);
    ~TftPrinter();

    TFT_eSPI *ptrTFT;

    void initTFT();

    void Rectangulo(int32_t x, int32_t y, int32_t w, int32_t h, int32_t colorBorde, int32_t radio = 2, int32_t colorFondo = 0);
    void initLetra(const GFXfont *tipoLetra);
    int16_t AlturaLetra(int16_t fuente);
    int16_t AnchuraTexto(const char *texto);
    void colorLetra(uint16_t color);
    void Escribir(const char *texto, int32_t x, int32_t y, uint8_t fuente);
    void LimpiarPantalla(uint32_t color);
	



};


#endif