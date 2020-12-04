#ifndef ISubject_h
#define ISubject_h

#include "Arduino.h"
#include "IObserver.h"


//PATRON OBSERVER. INTERFAZ SUJETO OBSERVADO(TACTIL)

class ISubject {
    public:
        virtual ~ISubject(){};
        virtual void Attach(IObserver *observer) = 0;
        
        virtual void Detach(IObserver *observer) = 0;
        
        virtual void Notify() = 0;
};


#endif