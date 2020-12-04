#ifndef Coordenada_h
#define Coordenada_h

#include "Arduino.h"


class Coordenada {
    public:
        Coordenada();
        Coordenada(uint32_t x, uint32_t y);
        ~Coordenada();

        void X(uint32_t x);
        uint32_t X() const;

        void Y(uint32_t y);
        uint32_t Y() const;
        
    private:
        uint32_t mX; 
        uint32_t mY;
};



#endif