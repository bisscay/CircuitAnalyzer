// header.h
#ifndef HEADER_H
#define HEADER_H
#include "circuit.h"
#include "resistor.h"

// inherit by extension from circuit class
// circuit with single component

// Unit Class
class Unit: public Circuit 
{
  public:
    Unit();
    Unit(double resistance, std::string label);
    ~Unit();
    virtual double calcCompR();
    inline virtual void setCompC(double newC) {};
    //virtual std::string getCircuitLabel();
    void setR(double newR);
    double getR();
    // current through unit component
    double getS();
    // get voltage accross resistor
    double getV();
    // set voltage accross resistor
    void setV(double newV);
    // set current through resistor
    void setC(double newC);
    //double getCircuitLabel();

  private:
  // resistor object as a component
  Resistor unitR;
};
// Series Class
class Series: public Circuit
{
  public:
    Series();
    //Series(Circuit *c1, Circuit *c2);
    Series(Unit c1, Unit c2);
    ~Series();
    virtual double calcCompR();
    void seriesR(Unit c1, Unit c2);
    Unit unitS();
    inline virtual void setCompC(double newC);
    
    //virtual std::string getCircuitLabel();

  private:
  // attributes of the abstract base class type Circuit as components
  // each componenet is a circuit
  
    //Unit c2(Resistor r2);
    Circuit *pC1;
    Circuit *pC2;
    Unit seiresUnit;
};
// Parallel class
class Parallel
{
  public:
    Parallel();
    Parallel(Unit c1, Unit c2);
    ~Parallel();
    virtual double calcCompR();
    void parallelR(Unit c1, Unit c2);
    Unit unitP();
    inline virtual void setCompC(double newC) {};
    
  private:
    Circuit *pC1;
    Circuit *pC2;
    Unit parallelUnit;
};
#endif