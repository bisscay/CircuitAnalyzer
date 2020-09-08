// circuit.h
// abstract base class with pure virtual function
// what are the missing functionalities to be implemented
#ifndef CIRCUIT_H
#define CIRCUIT_H
class Circuit
{
  public:
    Circuit();
    Circuit(Circuit* c1,  Circuit* c2);
    virtual ~Circuit();
    virtual double calcCompR() = 0;
    virtual void setCompC(double newC) = 0;
    void setTotalV(double newV);
    inline void setTotalR(double newR) {totalR = newR;};
    inline void setTotalC(double newC) {totalC = newC;};
    inline double getTotalV() const {return totalV;};
    inline double getTotalR() const {return totalR;};
    inline double getTotalC() const {return totalC;};
    //inline void setVoltage(newVolt) {newVolt};
    /*
    virtual double calcCompR1() = 0;
    virtual double calcCompR2() = 0;
    */
    
    // circuit representation
    //virtual std::string getCircuitLabel() = 0;
    
  private:
  Circuit *pc1;
  Circuit *pc2;
  double totalV;
  double totalC;
  double totalR;
};

#endif
