

#include "Arduino.h"

#include "Layout.h"

void touch_calibrate();

TFT_eSPI tft = TFT_eSPI();
Tactil tactil =  Tactil(&tft);
TftPrinter gui = TftPrinter(&tft);


Texto label = Texto(&gui, "", Color(TFT_RED));
 

Boton btnOK = Boton(&gui, Color(TFT_GREEN), Color(TFT_GREEN), Coordenada(120, 5), Coordenada(120, 30), Texto("INTRODUCIR", Color(TFT_DARKCYAN)), &tactil);
Boton btnCancel = Boton(&gui, Color(TFT_RED), Color(TFT_RED), Coordenada(0, 5), Coordenada(120, 30), Texto("CANCELAR", Color(TFT_WHITE)), &tactil);

Layout Imagen = Layout();




void setup(void) {

  //Serial.begin(115200);

  gui.initTFT();

  gui.LimpiarPantalla(Imagen.ColorFondo());

  Imagen.Update(1);
}

void loop() {

  tactil.estaPulsada();
  tactil.Notify();

  if(btnOK.estado == 1)
    {
        //Serial.println("btn.OK=1");
        //label.ColorFondo(BACKGROUND);
        label.Txt("Boton OK pulsado");
        label.ColorFondo(BACKGROUND);
        label.Imprimir(Coordenada(10,60), 1);
    }
    else if(btnCancel.estado == 1)
    {
        //Serial.println("btn.Cancel=1");
        //label.ColorFondo(BACKGROUND);
        label.Txt("Boton Cancel pulsado");
        label.ColorFondo(BACKGROUND);
        label.Imprimir(Coordenada(10,60), 1);
    }
    else if(btnCancel.estado == 0 && btnOK.estado == 0)
    {
        //Serial.println("btn.estado=0");
        label.Txt("Boton sin pulsar");
        label.ColorFondo(BACKGROUND);
        label.Imprimir(Coordenada(10,60), 1);
    }
    else 
    {
      
    }

delay(1000);
}


void touch_calibrate()
{
  uint16_t calData[5];
  //uint8_t calDataOK = 0;

  // Calibrate
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.println("Touch corners as indicated");

  tft.setTextFont(1);
  tft.println();

  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  Serial.println(); Serial.println();
  Serial.println("// Use this calibration code in setup():");
  Serial.print("  uint16_t calData[5] = ");
  Serial.print("{ ");

  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }

  Serial.println(" };");
  Serial.print("  tft.setTouch(calData);");
  Serial.println(); Serial.println();

  tft.fillScreen(TFT_BLACK);
  
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration complete!");
  tft.println("Calibration code sent to Serial port.");

  delay(4000);
}









