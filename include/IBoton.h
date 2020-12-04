#ifndef interfazBoton_h
#define interfazBoton_h

#include "Arduino.h"
#include "IObserver.h"

#include "Color.h"
#include "Texto.h"
#include "Coordenada.h"

class IBoton : public IObserver{
    public:
        virtual void Dibujar() = 0;
    
    protected:
    Color fondo, borde;
    Texto texto;
    Coordenada posicion, tamano;
};




#endif