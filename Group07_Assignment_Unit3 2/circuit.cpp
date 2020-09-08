// circuit.cpp
// Abstract base class
#include <cstdlib>
#include "circuit.h"

Circuit::Circuit():totalV(0.0),totalC(0.0),totalR(0.0)
{
  // Cstr
}

Circuit::~Circuit()
{
  // Dstr
}

void Circuit::setTotalV(double newV)
{
  totalV = newV;
  //calculate and assign total current
  setTotalC(getTotalV() / getTotalR());
}

/*
Circuit::Circuit(Circuit* c1, Circuit* c2)
{
  // Cstr
  pc1=c1;
  pc2=c2;
}*/
