// series.cpp
#include "header.h"
#include <cstdlib>
// Default Constructor
Series::Series()
{
  // Cstr
}
// Generic Constructor with Unit Unit Parameters
Series::Series(Unit c1, Unit c2)
{
  pC1 = &c1;
  pC2 = &c2;
}
// Destructor
Series::~Series()
{
  // Dstr
}
//
/*
std::string Series::getCircuitLabel()
{
  return ("(" + pC1->getCircuitLabel() + "-" + pC2->getCircuitLabel() + ")");
}*/

// components are ciruits and have resistors class as component
// hence; series operation for resistance is
// return resultant resistance in series
double Series::calcCompR() 
{
  return seiresUnit.getR();
}
// access current attribute of a mono circuit
void Series::setCompC(double newC) 
{
  seiresUnit.setC(newC);
}
// calculate resultant resistance in series
void Series::seriesR(Unit c1, Unit c2)
{
  pC1 = &c1;
  pC2 = &c2;
  seiresUnit.setR(pC1->calcCompR() + pC2->calcCompR());
  // when circuits are combined in series
  // current through each component is the total current
  // access total current in base class
  // assign total current to a unitcomponent in series class
  pC1->setCompC(getTotalC());
  pC2->setCompC(getTotalC());
}

/*
void Series::compXtic(Unit c1, Unit c2)
{
  pC1 = &c1;
  pC2 = &c2;

	double voltResult = 0;
	voltResult = getTotalC() * pC1->calcCompR();
	pC1->setV(voltResult);
	pC1->setS(getTotalC());

	voltResult = getTotalC() * pC2->calcCompR();
	pC2->setV(voltResult);
	pC2->setS(getTotalC());
}
*/

// return unit component of series
Unit Series::unitS()
{
  return seiresUnit;
}
