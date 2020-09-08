// parallel.cpp
#include "header.h"
#include <cstdlib>
Parallel::Parallel()
{
  // Cstr
}
// Generic Constructor
Parallel::Parallel(Unit c1, Unit c2)
{
  pC1 = &c1;
  pC2 = &c2;
}
Parallel::~Parallel()
{
  // Dstr
}
// return resultant resistance in parallel
double Parallel::calcCompR() 
{
  return parallelUnit.getR();
}
// return unit component of parallel
Unit Parallel::unitP() 
{
  return parallelUnit;
}
// calculate resultant resistance in Parallel
void Parallel::parallelR(Unit c1, Unit c2)
{
  pC1 = &c1;
  //pC1->calcCompR();
  pC2 = &c2;
  double x = (pC1->calcCompR() * pC2->calcCompR()) / (pC1->calcCompR() + pC2->calcCompR());
  parallelUnit.setR(x);
}
/*
std::string Series::getCircuitLabel()
{
  return ("(" + pC1->getCircuitLabel() + "|" + pC2->getCircuitLabel() + ")");
}*/
/*
void Parallel::compXtic(Unit c1, Unit c2)
{
  pC1 = &c1;
  pC2 = &c2;
  
	pC1->setV(getTotalV());
	pC2->setV(getTotalV());

	currResult = getTotalV() / pC1->calcCompR();
	pC1->setS(currResult);

	currResult = getTotalV() / pC2->calcCompR();
	pC2->setS(currResult);
}
*/