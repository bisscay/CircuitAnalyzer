// resistor.cpp
// Resistor class definition
#include <cstdlib>
#include "resistor.h"

// Default constructor
Resistor::Resistor ():voltage(0.0), current(0.0)
{
  // Cstr
}
// Generic constructor
Resistor::Resistor (double newResistance, std::string newLabel):voltage(0.0), current(0.0)
{
  setResistance(newResistance);
  //cout<<resistance;
  label = newLabel;
}
// Destructor
Resistor::~Resistor ()
{
  // Dstr
}
// set the voltage and calculate current
void Resistor::setVoltage (double newVolt)
{
  voltage = newVolt;
  // calc resultant current through resistor
  current = voltage/resistance;
}
