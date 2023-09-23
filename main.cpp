//-----------------------------------------------------------------------
// File : main.cpp
//
// Programmer: Robert Klenke
//
// Program #: Homework #3
//
// Due Date: March 14th, 2022
//
// Course: EGRE 347, Spring 2022
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: Test program for original Matrix class definition
//
//-----------------------------------------------------------------------
using namespace std;

#include <fstream>
#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[])
{
  Matrix a;
  Matrix b(1.0, 2.0, 3.0, 4.0);
  Matrix c(b);

  cout << "\na matrix is: \n";
  a.print();
  cout << "|a| = " << a.det() << "\n";
  if(a.isSingular())
    cout << "a is a singluar matrix\n";
  else
    cout << "a is not a singluar matrix\n";

  cout << "\nb matrix is: \n";
  b.print();
  cout << "|b| = " << b.det() << "\n";
  if(b.isSingular())
    cout << "b is a singluar matrix\n";
  else
    cout << "b is not a singluar matrix\n";

  cout << "\nc matrix is: \n";
  c.print();
  cout << "|c| = " << c.det() << "\n";
  if(c.isSingular())
    cout << "c is a singluar matrix\n";
  else
    cout << "c is not a singluar matrix\n";

  cout << "\nc matrix inverse is: \n";
  c.inverse();
  c.print();

  a.assign(0.0, 1.0, 0.0, 1.0);
  cout << "\na matrix is: \n";
  a.print();
  cout << "\na matrix inverse is: \n";
  a.inverse();
  a.print();

  b.assign(4.0, 3.0, 3.0, 2.0);
  cout << "\nb matrix is: \n";
  b.print();
  cout << "b matrix inverse is: \n";
  b.inverse();
  b.print();


}    /* end main */
