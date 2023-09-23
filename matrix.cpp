//-----------------------------------------------------------------------
// File : Matrix.cpp
//
// Programmer: Michael Lindsay
//
// Program #: HW#3
//
// Due Date: 3/14/2022
//
// Course: EGRE 347, Spring 2022
//
// Pledge: I have neither given nor received unauthorized aid on this program.
//
// Description: functions and overloading function 
//
//-----------------------------------------------------------------------
using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include "matrix.h"


// a default constructor that initializes the matrix entries to 0.0
Matrix::Matrix()
{
  x[0] = 0.0;
  y[0] = 0.0;
  x[1] = 0.0;
  y[1] = 0.0;
}

// a constructor that takes the matrix elements as a list of arguments
Matrix::Matrix(double a, double b, double c, double d)
{
  x[0] = a;
  y[0] = b;
  x[1] = c;
  y[1] = d;
}

// a standard copy constructor 
Matrix::Matrix(const Matrix& m)
{
  x[0] = m.x[0];
  x[1] = m.x[1];
  y[0] = m.y[0];
  y[1] = m.y[1];
}

// void Matrix:: inverse() 
// 
// Summary of the function: 
// 
//    inverse the matrix 
// 
// Parameters   :  none ()
// 
// Return Value : none Void
// 
// Description: 
// 
//    This function check if the matrix singular or no if so retrun error message on the screen
//    else inverse the matrix by using the inverse formula 
//    
//   The determinant = | a   b | = ad - bc
//                     | c   d | 
//   The Inverse = 1/ determinant* | d   -b |
//                                 | -c   a | 
void Matrix::inverse()
{
  double det_a = det();

  if(det_a == 0) {
    cout << "Error: matrix is singluar - it does not have an inverse\n";
    return;
  }

  det_a = 1.0/det_a;

  double temp = x[0];
  x[0] = det_a * y[1];
  y[1] = det_a * temp;

  temp = x[1];
  x[1] = -1.0 * det_a * x[1];
  y[0] = -1.0 * det_a * y[0];

}

// double Matrix:: det() 
// 
// Summary of the function: 
// 
//    calculate the determinant of the matrix
// 
// Parameters   : none ()
// 
// Return Value : none Void 
// 
// Description: 
//   
//   The determinant = | a   b | = ad - bc
//                     | c   d | 
//   a = x[0], b = y[0] , c = x[1], d = y[1]  
//                             
double Matrix::det()
{
  return(x[0]*y[1]-y[0]*x[1]);
}

// bool Matrix:: isSingular() 
// 
// Summary of the function: 
// 
//  This function find if the matrix is singular or not 
// 
// Parameters   : none ()
// 
// Return Value :  true(1) or false(0) 
// 
// Description: 
// 
//    function that returns a bool that is true if the determinant is zero – false otherwise 
//   
//
bool Matrix::isSingular()
{
  if(det() == 0)
    return true;
  else
    return false;
}

void Matrix::assign(double a, double b, double c, double d)
{
  x[0] = a;
  y[0] = b;
  x[1] = c;
  y[1] = d;
}

// Void Matrix:: print() 
// 
// Summary of the function: 
//  
//     Print the matrix to the screen 
// 
// Parameters   : none ()
// 
// Return Value : none Void
// 
// Description: 
//
//  Display the elements of the matrix in matrix 2 by 2 configuration 
// 
//  
void Matrix::print()
{
  cout << showpoint << setprecision (4);
  cout << "\t---\t\t\t---\n";
  cout << "\t|\t" << x[0] << "\t" << y[0] << "\t  |\n";
  cout << "\t|\t\t\t  |\n";
  cout << "\t|\t" << x[1] << "\t" << y[1] << "\t  |\n";
  cout << "\t---\t\t\t---\n";
}


// double Matrix:: equal operator 
// 
// Summary of the function: 
// 
//    sets each part of thw 2x2 matrix equal to the other 
// 
// Parameters   : A constant matrix of 
// 
// Return Value :  *this 
// 
// Description: 
//   
//   The equal operator = F1| a   b | = F2| a   b |
//                          | c   d | =   | c   d |
//   
//                             
Matrix& Matrix::operator=(const Matrix& m)
{
  x[0] = m.x[0];      // same as this->p1 = m.p1
  x[1] = m.x[1];      // same as this->p2 = m.p2
  y[0] = m.y[0];      // same as this->p1 = m.p1
  y[1] = m.y[1];      // same as this->p2 = m.p2
  

  return *this;
}

// double Matrix:: Addition operator  
// 
// Summary of the function: 
// 
//    Adds two functions toghter  
// 
// Parameters   : const Matrix& x and const Matrix& y
// 
// Return Value : return total 
// 
// Description: 
//   
//        The sub operator = F1| a   b | + F2| a   b | = F3| a   b |
//                             | c   d |     | c   d |     | c   d |

//                             
Matrix operator+(const Matrix& x, const Matrix& y)
{
  Matrix temp1, temp2, total;
  temp1 = x;
  temp2 = y;

  //element 1
  total.x[0]=temp1.x[0] + temp2.x[0];
  //element 2
  total.x[1]=temp1.x[1] + temp2.x[1];
  //element 3
  total.y[0]=temp1.y[0] + temp2.y[0];
  //element 4
  total.y[1]=temp1.y[1] + temp2.y[1];


  return total;
}


// Sub operator
// 
// Summary of the function: 
// 
//    calculate the determinant of the matrix
// 
// Parameters   : const Matrix& x and const Matrix& y
// 
// Return Value : return sub 
// 
// Description: 
//        The sub operator = F1| a   b | - F2| a   b | = F3| a   b |
//                             | c   d |     | c   d |     | c   d |
//   
//                             
Matrix operator-(const Matrix& x, const Matrix& y)
{
  Matrix temp1, temp2, sub;
  temp1 = x;
  temp2 = y;

  //element 1
  sub.x[0]=temp1.x[0] - temp2.x[0];
  //element 2
  sub.x[1]=temp1.x[1] - temp2.x[1];
  //element 3
  sub.y[0]=temp1.y[0] - temp2.y[0];
  //element 4
  sub.y[1]=temp1.y[1] - temp2.y[1];



  return sub;
}


// Mult operator of another Matrix
// 
// Summary of the function: 
// 
//    calculate the determinant of the matrix
// 
// Parameters   : const Matrix& x, const Matrix& y
// 
// Return Value : Matrix mult 
// 
// Description: 
//        The mult operator = F1| a   b | * F2| a   b | = F3| a   b |
//                              | c   d |     | c   d |     | c   d |
//   
//         
Matrix operator*(const Matrix& x, const Matrix& y)
{
  Matrix temp1, temp2, mult;
  temp1=x;
  temp2=y;
  //element 1
  mult.x[0]=temp1.x[0] * temp2.x[0];
  //element 2
  mult.x[1]=temp1.x[1] * temp2.x[1];
  //element 3
  mult.y[0]=temp1.y[0] * temp2.y[0];
  //element 4
  mult.y[1]=temp1.y[1] * temp2.y[1];

  

  return mult;
}


// Mult operator of a single multication factor
// 
// Summary of the function: 
// 
//    calculate the of the matrix of multication factor
// 
// Parameters   : const double r, const Matrix& x
// 
// Return Value : Matrix mult 
// 
// Description: 
//        The mult operator =  F1| a   b | * R  = F3| a   b |
//                               | c   d |          | c   d |
//   
//                           
Matrix operator*(const double r, const Matrix& x)
{
  Matrix temp, mult;
  temp = x;
  double r_val = r;

  //element 1
  mult.x[0]=temp.x[0] * r_val;
  //element 2
  mult.x[1]=temp.x[1] * r_val;
  //element 3
  mult.y[0]=temp.y[0] * r_val;
  //element 4
  mult.y[1]=temp.y[1] * r_val;
 

  return mult;
}


// Division operator of two diffrent matrxies
// 
// Summary of the function: 
// 
//     calculate the of the matrix of multication factor
// 
// Parameters   : const Matrix& x and const Matrix& y
// 
// Return Value : Matrix div 
// 
// Description: 
//        The division operator = F1| a   b | / F2| a   b | = F3| a   b |
//                                  | c   d |     | c   d |     | c   d |
//   
//              
Matrix operator/(const Matrix& x, const Matrix& y)
{
  Matrix temp1, temp2, div;
  temp1 = x;
  temp2 = y;

  //element 1
  div.x[0]=temp1.x[0] / temp2.x[0];
  //element 2
  div.x[1]=temp1.x[1] / temp2.x[1];
  //element 3
  div.y[0]=temp1.y[0] / temp2.y[0];
  //element 4
  div.y[1]=temp1.y[1] / temp2.y[1];



  return div;
}



// Extractraction operator of an ostream
// 
// Summary of the function: 
// 
//     Pulls out the values for a 
// 
// Parameters   : ostream& os and const Matrix& m
// 
// Return Value : os 
// 
// Description: 
//   out puts values t the termnial screen rather in acordding mannor
//  ---           ---
//  | x[0]  y[0]    |
//  |               |
//  | x[1]  y[1]    |
//   ---         ---  
//                             
ostream& operator<<(ostream& os, const Matrix& m)
{
  os << showpoint << setprecision (4);
  os << "\t---\t\t\t---\n";
  os << "\t|\t" << m.x[0] << "\t" << m.y[0] << "\t  |\n";
  os << "\t|\t\t\t  |\n";
  os << "\t|\t" << m.x[1] << "\t" << m.y[1] << "\t  |\n";
  os << "\t---\t\t\t---\n";
  return os;
}


// Extractraction operator of an ostream
// 
// Summary of the function: 
// 
//     Pulls out the values for a 
// 
// Parameters   : ofstream& os and const Matrix& m
// 
// Return Value : os 
// 
// Description: 
//   out puts values t the termnial screen rather in acordding mannor

//  x[0]  y[0]
//  x[1]  y[1]    
//                                 
ofstream& operator<<(ofstream& os, const Matrix& m)
{
  os << showpoint << setprecision (3);
  os << m.x[0] << " " << m.y[0]<<endl;
  os << m.x[1] << " " << m.y[1]<<endl;

  return os;
}


// Insertision operator of an ostream
// 
// Summary of the function: 
// 
//     Pulls out the values for a 
// 
// Parameters   : istream& is, Matrix& m
// 
// Return Value : is 
// 
// Description: 
//  takes values from an extrental file designated during the command line
//  from this point it sets them to the correct values through the private domain
//  it is allowed to do this because of it being a friend fucntion
//                        
//                             
istream& operator>>(istream& is, Matrix& m)
{
  //Matrix temp;
  is >> m.x[0];
  is >> m.y[0];
  is >> m.x[1];
  is >> m.y[1];
  return is;
}



