#ifndef Color_h
#define Color_h



#include "Arduino.h"
#include "stdio.h"



class  Color {
public:
	Color(uint32_t color);
	Color();
	~Color();

	void aColor(uint32_t color);
	uint32_t aColor() const;


private:
	uint32_t mColor;
};
#endif