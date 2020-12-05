#ifndef Boton_h
#define Boton_h

#include "Arduino.h"

#include "IBoton.h"

#include "Rectangulo.h"
#include "Tactil.h"
#include "TftPrinter.h"


class Boton : public IBoton {

  public:
    Boton(TftPrinter *ptrTft, Color fondo, Color borde, Coordenada posicion, Coordenada tamano, Texto texto, Tactil *subject);
    ~Boton();

    void setColorFondo(uint32_t color);
    void Dibujar();

    void Update(const String &message_from_subject, uint16_t coordX, uint16_t coordY);

    int estado = 0;//prueba de patron observer
    void Subscribirse(Tactil *subject);
    void Desubscribirse(Tactil *subject);

  private:
    TftPrinter *ptrTFT;

    Rectangulo forma;
    Rectangulo initForma();

    Coordenada CentrarTexto();

    uint8_t pulsado(uint16_t coordX, uint16_t coordY);

    String message_from_subject_;
    
};




#endif
