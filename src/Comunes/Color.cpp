#include "Arduino.h"
#include "stdio.h"


#include "Color.h"


//*******************  PUBLIC ****************************************/
Color::~Color()
{
    
}

Color::Color(uint32_t color) {
    this->mColor = color;
}
Color::Color() {
}

//SETTERS

void Color::aColor(uint32_t color)
{
    this->mColor = color;
}

//GETTERS

uint32_t Color::aColor() const
{
    uint32_t color;
    color = this->mColor;
    return color;
}

//METHODS

