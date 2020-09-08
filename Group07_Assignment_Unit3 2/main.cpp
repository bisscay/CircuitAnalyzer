// main.cpp
#include <stdio.h>
#include <iostream>
#include "header.h"


/*
Pseudo-code
User selects a circuit to be modeled
Based on the selected option, a circuit model is generated
    Each component is represened in a top down approach as a unit class
    A Circuit Base class is defined with pure virutal methods for component resistance, voltage drop and current through
    Unit, Series and Parallel are concrete derived classes of the ciruict abstract class
    Unit class contains resistor class as a composition
    When a Parallel relation is encountered, Unit representations are passed 
    Using circuit analysis (KVL and KCL),
    A method is defined from a pure virtual function in the abstract class to derive resultant resistance of the passed unit components
    A method is defined to calculate the voltage drop accross each component
    - the voltage drop of resistance in parallel is equal,
    - get resultant resistance of parallel resistance and multiply by total circuit current to get voltage drop 
    - Vdrop = totalCurrent * (Ra//Rb)
    A method is defined to derive the current through each component
    - Ia = Vdrop/Ra; Ib = Vdrop/Rb;
    A method is defined for a string representation of passed components
    When a Series relation is encountered, Unit representations are passed 
    Using circuit analysis (KVL and KCL),
    define a method from abstract class for resultant resistance
    - method is defined by calculating parallel resistance
    define a method from abstract class for current through components
    - current through a resistance in series is equal to the total current of the circuit
    define a method from abstract class for voltage drops 
    - the voltage drop of each component is the components resitance divided by the total circuit current
    The final circuit composition will encompass all components in series
  Generated model resolves the total resistance of the mono circuit parameters that make up the model
  Resultant resistance is stored in circuit base class
Accept voltage accross the entire circuit from user
  total voltage is stored in the base class
    on storing voltage, total current through the circuit is calculated using Ohm's law
    total current is stored in circuit
Provide interface for circuit analysis to user
Accept users choice
When case 1
  Get the stored total resistance of the circuit
When case 2
  Get the total stored voltage value from base class
When case 3
  Return the total current through circuit
When case 4
  Output hardcoded circuit representation to user (will be generated in next version) 
When case 5
  Get total resistance of each resistor circuit that makes up the model
    access the stored resistance of each resistor instance 
When case 6 (to be implemented in next version)
  Get total current through each resistor circuit that makes up the model
    access the stored resistance of each resistor instance
    (in next version, value of current through will be calculated when specific circuit "parallel/series" accepts a resistor
  resolved current will then be assigned to current attribute in resistor object for later access)
When case 7 
  Get total voltage drop accross each resistor circuit that makes up the model
    access the stored resistance of each resistor instance
  (in next version, voltage drop value will be calculated when specific circuit "parallel/series" accepts a resistor
  resolved drop will then be assigned to voltage attribute in resistor object for future access)
  
When case 8
  Step out of considered circuit model and prompt user to make another choice
If case 1 or 2
  continue analysis
If case 3
  Exit application
  
Faced issues in deriving component based xtics;

*/


using std::cout;
using std::endl;

// declear methods for circuit modeling
double model1(Unit u1, Unit u2, Unit u3, Unit u4, Unit u5, Unit u6, Unit u7);
double model2(Unit u1, Unit u2, Unit u3, Unit u4, Unit u5, Unit u6, Unit u7, Unit u8, Unit u9, Unit u10, Unit u11, Unit u12, Unit u13, Unit u14);
// user interface method decleration
void userInterface();

int main()
{
  userInterface();
  return 0;
}
// user interface definition
// return void
void userInterface()
{
  using std::cout;
  using std::cin;
  using std::endl;
  int option, display;
  double volt;
  Circuit*c = (new Series);
  Unit u1(50,"R1");
  Unit u2(25,"R2");
  Unit u3(30,"R3");
  Unit u4(150,"R4");
  Unit u5(75,"R5");
  Unit u6(100,"R6");
  Unit u7(40,"R7");
  Unit u8(60,"R8");
  Unit u9(50,"R9");
  Unit u10(20,"R10");
  Unit u11(40,"R11");
  Unit u12(30,"R12");
  Unit u13(70,"R13");
  Unit u14(80,"R14");
  // prompt user to select a cirucit
  do
  {
    cout << "Select a number to access a ciruit in menue or 3 to END analysis\n"
    << "1.\tCircuit 1\n"
    << "2.\tCircuit 2\n" 
    << "3.\tEnd\n"
    << endl;
    cin >> option;
  
    if (option == 1) {
      // model circuit 1
	    c->setTotalR(model1(u1, u2, u3, u4, u5, u6, u7));
      cout << "Applied Voltage: ";
      cin >> volt;
      // assign total voltage
      c->setTotalV(volt);
      while (display != 8)
      {
        cout << "\nPick an Option: "
            << "\n1. Total Resistance"
            << "\n2. Total Voltage"
            << "\n3. Total Current"
            << "\n4. A string representing the circuit"
            << "\n5. Resistance R1 - R7"
            << "\n6. Current through each resistor R1 - R7"
            << "\n7. Voltage drop accross each resistor R1 - R7"
            << "\n8. Exit Application" << endl;
        cin >> display;
        switch(display)
        {
          case 1: cout << "Total Resistance: " << c->getTotalR();
                  break;
          case 2: cout << "Total Voltage: " << c->getTotalV();
                  break;
	        case 3: cout << "Total Current: " << c->getTotalC();
                  break;
          // String Representation hardcoded but can be infered as circuit is being modeled
          case 4: cout << "String Representation: " << "(((R3 - (R1 | R2)) - ((R4|R5) | R6)) - R7)";
                  break;
          case 5: cout << "R1: " << u1.getR() << " Ohms\t"  << "R2: " << u2.getR() << " Ohms\t"
            		     << "R3: " << u3.getR() << " Ohms\t"  << "R4: " << u4.getR() << " Ohms\t"
            		     << "R5: " << u5.getR() << " Ohms\n"  << "R6: " << u6.getR() << " Ohms\t"
            		     << "R7: " << u7.getR() << " Ohms\t"  << "R8: " << u8.getR() << " Ohms\t"
            		     << "R9: " << u9.getR() << " Ohms\t"  << "R10: " << u10.getR() << " Ohms\n"
            		     << "R11: " << u11.getR() << " Ohms\t"  << "R12: " << u12.getR() << " Ohms\t"
            		     << "R13: " << u13.getR() << " Ohms\t"  << "R14: " << u14.getR() << " Ohms"  << endl;
                break;
          case 6: cout << "R1: " << u1.getS() << " Amps\t"  << "R2: " << u2.getS() << " Amps\t"
              		     << "R3: " << u3.getS() << " Amps\t"  << "R4: " << u4.getS() << " Amps\t"
              		     << "R5: " << u5.getS() << " Amps\n"  << "R6: " << u6.getS() << " Amps\t"
              		     << "R7: " << u7.getS() << " Amps\t"  << "R8: " << u8.getS() << " Amps\t"
              		     << "R9: " << u9.getS() << " Amps\t"  << "R10: " << u10.getS() << " Amps\n"
              		     << "R11: " << u11.getS() << " Amps\t"  << "R12: " << u12.getS() << " Amps\t"
              		     << "R13: " << u13.getS() << " Amps\t"  << "R14: " << u14.getS() << " Amps"  << endl;
              		break;
          case 7: cout << "R1: " << u1.getV() << " V\t"  << "R2: " << u2.getV() << " V\t"
              		     << "R3: " << u3.getV() << " V\t"  << "R4: " << u4.getV() << " V\t"
              		     << "R5: " << u5.getV() << " V\n"  << "R6: " << u6.getV() << " V\t"
              		     << "R7: " << u7.getV() << " V\t"  << "R8: " << u8.getV() << " V\t"
              		     << "R9: " << u9.getV() << " V\t"  << "R10: " << u10.getV() << " V\n"
              		     << "R11: " << u11.getV() << " V\t"  << "R12: " << u12.getV() << " V\t"
              		     << "R13: " << u13.getV() << " V\t"  << "R14: " << u14.getV() << " V"  << endl;
              		break;
          // Conditions for other cases to be implemented over time
          case 8: cout << "Exiting...";
                  break;
          default:
          cout << "Please pick a valid option from the list.";
        }
      }
    } else if (option == 2){
      // model circuit 2
	    c->setTotalR(model2(u1, u2, u3, u4, u5, u6, u7, u8, u9, u10, u11, u12, u13, u14));
      cout << "Applied Voltage: ";
      cin >> volt;
      // assign total voltage
      c->setTotalV(volt);
      do
      {
        cout << "\nPick an Option: "
            << "\n1. Total Resistance"
            << "\n2. Total Voltage"
            << "\n3. Total Current"
            << "\n4. A string representing the circuit"
            << "\n5. Resistance R1 - R7"
            << "\n6. Current through each resistor R1 - R7"
            << "\n7. Voltage drop accross each resistor R1 - R7"
            << "\n8. Exit Application" << endl;
        cin >> display;
        switch(display)
        {
	      case 1: cout << "Total Resistance: " << c->getTotalR();
                break;
        case 2: cout << "Total Voltage: " << c->getTotalV();
                break;
	      case 3: cout << "Total Current: " << c->getTotalC();
                break;
        case 4: cout << "String Representation: " << "(((R2 | (R1 - ((R3|R4) | R5))) - (((R6 | R7) | R8) | R9)) – (((R10 - R11) | (R12 - R13)) | R14))";
                break;
        case 5: cout << "R1: " << u1.getR() << " Ohms\t"  << "R2: " << u2.getR() << " Ohms\t"
            		     << "R3: " << u3.getR() << " Ohms\t"  << "R4: " << u4.getR() << " Ohms\t"
            		     << "R5: " << u5.getR() << " Ohms\n"  << "R6: " << u6.getR() << " Ohms\t"
            		     << "R7: " << u7.getR() << " Ohms\t"  << "R8: " << u8.getR() << " Ohms\t"
            		     << "R9: " << u9.getR() << " Ohms\t"  << "R10: " << u10.getR() << " Ohms\n"
            		     << "R11: " << u11.getR() << " Ohms\t"  << "R12: " << u12.getR() << " Ohms\t"
            		     << "R13: " << u13.getR() << " Ohms\t"  << "R14: " << u14.getR() << " Ohms"  << endl;
                break;
        case 6: cout << "R1: " << u1.getS() << " Amps\t"  << "R2: " << u2.getS() << " Amps\t"
            		     << "R3: " << u3.getS() << " Amps\t"  << "R4: " << u4.getS() << " Amps\t"
            		     << "R5: " << u5.getS() << " Amps\n"  << "R6: " << u6.getS() << " Amps\t"
            		     << "R7: " << u7.getS() << " Amps\t"  << "R8: " << u8.getS() << " Amps\t"
            		     << "R9: " << u9.getS() << " Amps\t"  << "R10: " << u10.getS() << " Amps\n"
            		     << "R11: " << u11.getS() << " Amps\t"  << "R12: " << u12.getS() << " Amps\t"
            		     << "R13: " << u13.getS() << " Amps\t"  << "R14: " << u14.getS() << " Amps"  << endl;
            		break;
        case 7: cout << "R1: " << u1.getV() << " V\t"  << "R2: " << u2.getV() << " V\t"
            		     << "R3: " << u3.getV() << " V\t"  << "R4: " << u4.getV() << " V\t"
            		     << "R5: " << u5.getV() << " V\n"  << "R6: " << u6.getV() << " V\t"
            		     << "R7: " << u7.getV() << " V\t"  << "R8: " << u8.getV() << " V\t"
            		     << "R9: " << u9.getV() << " V\t"  << "R10: " << u10.getV() << " V\n"
            		     << "R11: " << u11.getV() << " V\t"  << "R12: " << u12.getV() << " V\t"
            		     << "R13: " << u13.getV() << " V\t"  << "R14: " << u14.getV() << " V"  << endl;
            		break;
        case 8: cout << "Exiting...";
                break;
        default:
        cout << "Please choose from the options provided.";
            }
      } while (display != 8);
    }
  } while(option != 3);
  delete c; // deallocating memory
}
// modeling circuit 1
// return a double of overall circuit resistance
double model1(Unit u1, Unit u2, Unit u3, Unit u4, Unit u5, Unit u6, Unit u7)
{
  // from top down, represent each component
  Parallel p1;
  Parallel p2;
  Parallel p3;
  Series s1;
  Series s2;
  Series s3;
  // calculate first two resistance in parallel
  p1.parallelR(u1, u2);
  // use the unit result of parrallel and calculate resistor 3 in series
  //cout << p1.calcCompR() << endl;
  s1.seriesR(u3,p1.unitP());
  //cout << s1.calcCompR() << endl;
  // represent next three resistors to be made parallel in series
  // make parallel
  p2.parallelR(u4, u5);
  //cout << p2.calcCompR() << endl;
  p3.parallelR(p2.unitP(), u6);
  //cout << p3.calcCompR() << endl;
  // make new parrallel result in series with previous
  s2.seriesR(s1.unitS(), p3.unitP());
  //cout << s2.calcCompR() << endl;
  // include last resistor in series
  s3.seriesR(s2.unitS(), u7);
  //cout << s3.calcCompR() << endl;
  return s3.calcCompR();
  
  // return string representation of circuit
  //s3.getCircuitLabel();
  
}
// modeling circuit 2
// return a double of overall circuit resistance
double model2(Unit u1, Unit u2, Unit u3, Unit u4, Unit u5, Unit u6, Unit u7, Unit u8, Unit u9, Unit u10, Unit u11, Unit u12, Unit u13, Unit u14)
{
  // from top down, represent each component
  Parallel p1;
  Parallel p2;
  Parallel p3;
  Parallel p4;
  Parallel p5;
  Parallel p6;
  Parallel p7;
  Parallel p8;
  Series s1;
  Series s2;
  Series s3;
  Series s4;
  Series s5;
  // R3//R4//R5
  p1.parallelR(u3, u4);
  p2.parallelR(u5, p1.unitP());
  // R1 in series
  s1.seriesR(u1, p2.unitP());
  // R2 in parallel
  p3.parallelR(u2, s1.unitS());
  // R6//R7//R8//R9
  p4.parallelR(u6, u7);
  p5.parallelR(u8, p4.unitP());
  p6.parallelR(u9, p5.unitP());
  // R6//R7//R8//R9 in series
  s2.seriesR(s2.unitS(), p6.unitP());
  // R10 R11 in series
  s3.seriesR(u10, u11);
  // R12 R13 in series
  s4.seriesR(u12, u13);
  // (R10 R11) (R12 R13) R14 in parallel
  p7.parallelR(s3.unitS(), s4.unitS());
  p8.parallelR(p7.unitP(), u14);
  // (R10 R11) (R12 R13) R14 parallel in series
  s5.seriesR(s2.unitS(), p8.unitP());
  //cout << s5.calcCompR();
  return s5.calcCompR();
}
