//-----------------------------------------------------------------------
// File : Matrix.h
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
// Description: Header file for Matrix
//
//-----------------------------------------------------------------------

// class Matrix definition
// Discription:
// This class inlcude the elements of 2*2 matrix and some methods 
// such as (inverse, assign, det, print, find singular) are defined for the matrix 
//
//
// Data members:
//  the four elements of the matrix 2*2
//  are defined as 2 arrays of two floats each - x (1st column) and y (second column)
//
//
// Methods:
// first the constructor, copy constructor, constructor that takes the matrix elements as a list of entries.
// There methods to find the inverse of the matrix, find the determinant, find if the matrix is singular,
// assign new values and print the matrix.
//

class Matrix
{
public:
  //Matrix operator+(const Matrix& y);
  // required to be a friend
  friend Matrix operator+(const Matrix& x, const Matrix& y);
    // operator built as a friend
  friend Matrix operator-(const Matrix& x, const Matrix& y);
    // operator built as a friend
  friend Matrix operator*(const Matrix& x, const Matrix& y);
    // required to be a friend
  friend Matrix operator*(const double r, const Matrix& x);
    // operator built as a friend
  friend Matrix operator/(const Matrix& x, const Matrix& y);
    // required to be a friend
  friend ostream& operator<<(ostream& os, const Matrix& m);
  // required to be a friend
  friend ofstream& operator<<(ofstream& os, const Matrix& m);
    // required to be a friend
  friend istream& operator>>(istream &is, Matrix& m);
    // assignment "=" operator    
  Matrix& operator=(const Matrix& m);

  Matrix();
  Matrix(double a, double b, double c, double d);
  Matrix(const Matrix& m);
  void inverse();
  double det();
  bool isSingular();
  void assign(double a, double b, double c, double d);
  void print();
 private:
  double x[2];
  double y[2];
};
