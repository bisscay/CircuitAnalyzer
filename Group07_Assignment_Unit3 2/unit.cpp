// unit.cpp
#include "header.h"
#include <cstdlib>
// Default constructor
Unit::Unit()
{
  // Cstr
}
// Generic constructor
Unit::Unit(double r, std::string l):unitR(r, l)
{
  // Cstr
}
// Destructor
Unit::~Unit ()
{
  // Dstr
}

double Unit::getR()
{
  return unitR.getResistance();
}

void Unit::setR(double newR)
{
  unitR.setResistance(newR);
}

// return the resistance value of the mono circuit
double Unit::calcCompR()
{
  
  return unitR.getResistance();
}
// return the current through a mono circuit
double Unit::getS()
{
  return unitR.getCurrent();
}
// get voltage drop accross resistor
double Unit::getV()
{
  return unitR.getVoltage();
}
// assign voltage accross a mono circuit
void setV(double newV) 
{
  //unitR.setVoltage(newV);
}
// assign current through a mono circuit
void Unit::setC(double newC)
{
  unitR.setCurrent(newC);
}

//
/*std::string Unit::getCircuitLabel()
{
  return unitR.getResistorLabel();
}*/