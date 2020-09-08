// resistor.h
//#include <cstdlib>
#ifndef RESISTOR_H
#define RESISTOR_H
#include <string>
class Resistor
{
  public:
    Resistor();
    Resistor(double newResistance, std::string newLabel);
    ~Resistor(); // implement virtual func in composition?
    void setVoltage(double newVolt);
    inline double getVoltage() const {return voltage;};
    inline double getCurrent() const {return current;};
    inline std::string getResistorLabel() const {return label;};
    inline double getResistance() const {return resistance;};
    inline void setResistance(double newR) {resistance=newR;};
    inline void setCurrent(double newC) {current=newC;};

  protected:

  private:
    double voltage;
    double current;
    std::string label;
    double resistance;
};
#endif
