#include "Arduino.h"
#include "stdio.h"


#include "Tactil.h"


//*******************  PUBLIC ****************************************/
Tactil::~Tactil()
{
    
}

Tactil::Tactil(TFT_eSPI *tft) {
 // this->message_ = "tactil creada";
 this->tft = tft;
}

uint8_t Tactil::estaPulsada()
{
    if(this->tft->getTouch(&this->coordX,&this->coordY))
    {
        this->message_ = "tactil";
        return true;
    }
    else
    {
        this->tft->getTouch(&this->coordX,&this->coordY);
        return false;
    }
}

/**
   * The subscription management methods.
   */


void Tactil::Attach(IObserver *observer) {
    this->list_observer_.push_back(observer);
  }

  void Tactil::Detach(IObserver *observer) {
    this->list_observer_.erase(std::remove(this->list_observer_.begin(), this->list_observer_.end(), observer), this->list_observer_.end());
  }

  void Tactil::Notify() {
    std::vector<IObserver *>::iterator iterator = this->list_observer_.begin();
    while (iterator != this->list_observer_.end()) {
      (*iterator)->Update(this->message_, this->coordX, this->coordY);
      ++iterator;
    }
}

//SETTERS



//GETTERS


//METHODS

void Tactil::HowManyObserver() {
    Serial.print("\nObservadores:");
    Serial.println(this->list_observer_.size());
  }