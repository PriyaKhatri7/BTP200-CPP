/* ------------------------------------------------------
Final Project Milestone 5
Module: Car and Motorcycle
Filename: ms5_CarMotorcycleTester.cpp
Version 0.9
Author	Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/27  Preliminary release
-----------------------------------------------------------
comment out car or motorcycle include and functions to test
individually.
*/
#include <iostream>
#include "Car.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Motorcycle.h"

using namespace std;
using namespace sdds;
void  MotorcycleTest(Vehicle*);
void  CarTest(Vehicle*);
int main() {
    cout << "Milestone 5, Car and Motorcycle: " << endl;
    CarTest(new Car);
    MotorcycleTest(new Motorcycle);
    return 0;
}
void  MotorcycleTest(Vehicle* V) {
    cout << "Motorcycle Test:" << endl << endl << "Invalid object printout: " << endl;
    cout << *V << endl;
    cout << "Testing Console Entry, Enter the following: " << endl
        << "ab12<ENTER>" << endl
        << "Harley Davidson<ENTER>" << endl
        << "yes<ENTER>" << endl
        << "y<ENTER>" << endl;
    cin >> *V;
    V->setCsv(true);
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << "Console Printout: " << endl << *V << endl;
    cout << "Testing CSV Entry, Enter the following: " << endl
        << "12,AA22,Honda CD80,0<ENTER>" << endl;
    V->setCsv(true);
    cin >> *V;
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << endl << "Console Printout: " << endl << *V << endl;
    delete V;
}
void  CarTest(Vehicle* V) {
    cout << "Car Test:" << endl << endl << "Invalid object printout: " << endl;
    cout << *V << endl;
    cout << "Testing Console Entry, Enter the following: " << endl
        << "abc123<ENTER>" << endl
        << "Chevy Volt<ENTER>" << endl
        << "yes<ENTER>" << endl
        << "y<ENTER>" << endl;
    cin >> *V;
    V->setCsv(true);
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << "Console Printout: " << endl << *V << endl;
    cout << "Testing CSV Entry, Enter the following: " << endl
        << "12,GVAA123,Nissan Leaf,0<ENTER>" << endl;
    V->setCsv(true);
    cin >> *V;
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << endl << "Console Printout: " << endl << *V << endl;
    delete V;
}