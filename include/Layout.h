#ifndef Layout_h
#define Layout_h



#include "Arduino.h"
#include "Boton.h"


const uint32_t BACKGROUND = TFT_SKYBLUE;

extern TFT_eSPI tft;


//extern Tactil *tactil;
extern Tactil tactil;

extern Texto label;
extern Boton btnOK;
extern Boton btnCancel;



class  Layout {
public:
	Layout();
	~Layout();

	void Update(uint8_t orden);
	uint8_t getActualizar();

	void ColorFondo(uint32_t colorFondo);
	uint32_t ColorFondo() const;
	



private:
	//std::vector<Boton *> botones;

	uint8_t actualizar;
	Color mColorFondo;
};
#endif