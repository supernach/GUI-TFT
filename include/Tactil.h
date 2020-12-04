#ifndef Tactil_h
#define Tactil_h



#include "Arduino.h"
#include "stdio.h"

#include "TFT_eSPI.h"
#include "ISubject.h"





class  Tactil : public ISubject {
public:
	
	Tactil(TFT_eSPI *tft);
	~Tactil();

	uint8_t estaPulsada();

	void Attach(IObserver *observer);
	void Detach(IObserver *observer);
	void Notify();

	


private:
	void HowManyObserver();
	
	std::vector<IObserver *> list_observer_;
  	char *message_;
	uint16_t coordX = 0;
	uint16_t coordY = 0;

	TFT_eSPI *tft;
	
	  
	
};
#endif