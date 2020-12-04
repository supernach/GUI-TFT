#include "Arduino.h"

#include "Coordenada.h"

Coordenada::~Coordenada()
{
    
}

Coordenada::Coordenada()
{
    this->mX = 1;
    this->mY = 1;
}

Coordenada::Coordenada(uint32_t x, uint32_t y)
{
    this->mX = x;
    this->mY = y;
}

void Coordenada::X(uint32_t x)
{
    this->mX = x;
}

void Coordenada::Y(uint32_t y)
{
    this->mY = y;
}

uint32_t Coordenada::X() const
{
    return this->mX;
}

uint32_t Coordenada::Y() const
{
    return this->mY;
}