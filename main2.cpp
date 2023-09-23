//-----------------------------------------------------------------------
// File : main2.cpp
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
// Description: Test program for Matrix class definition 
// with overloaded operators
//
//-----------------------------------------------------------------------

using namespace std;

#include <iostream>
#include <fstream>
#include "matrix.h"


int main(int argc, char *argv[])
{
	ifstream infile;
	ofstream outfile;
	string prog_name;
	string infile_name;
	string outfile_name;

	Matrix a;
	Matrix b(1.0, 2.0, 3.0, 4.0);
	Matrix c(a);
	Matrix d;

  prog_name = argv[0];

 if(argc < 3) {
    cout << "\nERROR, missing input and output file names!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }

  if(argc > 3) {
    cout << "\nERROR, too many arguments!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }
 
  infile_name = argv[1];
  outfile_name = argv[2];
 
  if(infile_name == "--help" || outfile_name == "--help") {
  cout << "\nProgram to read a list of integer numbers from a file\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
  return(-1);

  }
  
  infile.open(infile_name, fstream::in);
  if(!infile.is_open()) {
    cout << "\nERROR Could not open input file " << infile_name << "!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }

  outfile.open(outfile_name, fstream::out);
  if(!outfile.is_open()) {
    cout << "\nERROR Could not open output file " << outfile_name << "!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }


	cout << "\na matrix is: \n";
	cout << a;
	cout << "\nb matrix is: \n";
	cout << b;

	a = b;

	cout << "\na = b\n";
	cout << "a matrix now is: \n";
	cout << a;

	a.assign(1.0, 2.0, 8.0, 7.0);
	b.assign(5.0, 4.0, 4.0, 5.0);

	c = a + b;

	cout << "\na matrix is: \n";
	cout << a;
	cout << "\nb matrix is: \n";
	cout << b;
	cout << "\nc = a + b matrix is: \n";
	cout << c;

	a = c - b;

	cout << "\nc matrix is: \n";
	cout << c;
	cout << "\nb matrix is: \n";
	cout << b;
	cout << "\na = c - b matrix is: \n";
	cout << a;

	a.assign(30.0, 50.0, 25.0, 40.0);
	b.assign(2.0, 3.0, 1.0, 1.0);

	c = a * b;

	cout << "\na matrix is: \n";
	cout << a;
	cout << "\nb matrix is: \n";
	cout << b;
	cout << "\nc = a * b matrix is: \n";
	cout << c;

	a.assign(0.0, 0.0, 0.0, 0.0);
	a = c / b;

	cout << "\nc matrix is: \n";
	cout << c;
	cout << "\nb matrix is: \n";
	cout << b;
	cout << "\na = c / b matrix is: \n";
	cout << a;

	double r = 2.0;

	a = r * b;

	cout << "\nb matrix is: \n";
	cout << b;
	cout << "\na = 2.0 * b matrix is: \n";
	cout << a;
	
	infile >> d;
	cout << "\nRead d matrix from " << argv[1] << "\n";
	cout << "d matrix is: \n";
	cout << d;

	d = r * d;
	
	outfile << d;
	
	infile.close();
	outfile.close();
}		/* end main */
