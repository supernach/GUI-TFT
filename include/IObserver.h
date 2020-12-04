#ifndef IObserver_h
#define IObserver_h

#include "Arduino.h"

//PATRON OBSERVER. INTERFAZ SUJETO OBSERVADOR(BOTONES)

class IObserver {
    public:
        virtual ~IObserver(){};
        virtual void Update(const String &message_from_subject, uint16_t coordX, uint16_t coordY) = 0;
};


#endif