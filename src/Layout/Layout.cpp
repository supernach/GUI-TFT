#include "Arduino.h"


#include "Layout.h"

/*TFT_eSPI tft = TFT_eSPI();
Tactil tactil =  Tactil(&tft);
TftPrinter gui = TftPrinter(&tft);


Texto label = Texto(&gui, "", Color(TFT_RED));
 

BtnOriginal btnOK = BtnOriginal(&gui, Color(TFT_GREEN), Color(TFT_GREEN), Coordenada(120, 5), Coordenada(120, 30), Texto("INTRODUCIR", Color(TFT_DARKCYAN)), &tactil);
BtnOriginal btnCancel = BtnOriginal(&gui, Color(TFT_RED), Color(TFT_RED), Coordenada(0, 5), Coordenada(120, 30), Texto("CANCELAR", Color(TFT_WHITE)), &tactil);
*/


//*******************  PUBLIC ****************************************/
Layout::~Layout()
{
    
}

Layout::Layout()
{

    //Serial.println("Layout()");

    //label.ColorFondo(BACKGROUND);
    label.ColorFondo(BACKGROUND);

    this->mColorFondo = Color(BACKGROUND);

    this->actualizar = 1;


}

void Layout::ColorFondo(uint32_t colorFondo)
{
    this->mColorFondo.aColor(colorFondo);
}

uint32_t Layout::ColorFondo() const
{
    uint32_t auxColor = this->mColorFondo.aColor();
    return auxColor;
}

void Layout::Update(uint8_t orden)
{
    this->actualizar = orden;

    /*if(this->actualizar == 1)
    {*/
        //Serial.println("Layout().Update()");
        label.ColorFondo(BACKGROUND);
        label.Imprimir(Coordenada(10,60), 1);
        btnOK.Dibujar();
        btnCancel.Dibujar();

        this->actualizar = 0;
   // }
}

uint8_t Layout::getActualizar()
{
    return this->actualizar;
}

//SETTERS


//GETTERS



//METHODS

