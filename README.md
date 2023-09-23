Below is the content formatted for a `README.md` file:

```markdown
# NMEA GPS Sentence Parser

**Page: 1 of 3**  
**EGRE 347 Applied Object Oriented Programming**  
**Homework #3 – C++ Operator Overloading**  

> This homework must be your own (individual) work as defined in the course syllabus and discussed in class.

You have been provided with an implementation of a 2x2 Matrix class. The `Matrix` class is defined in the header file called `matrix.h` and implementation of the current Matrix class methods is in the `matrix.cpp` file. In addition, there is a `main.cpp` file that tests the initial implementation of the Matrix class, along with an appropriate Makefile.

## Assignment Requirements

1. Add overloaded operators for the following:
   - Assignment operator `=`
   - Matrix addition `+`
   - Matrix subtraction `-`
   - Matrix multiplication `*`
   - Matrix division `/`
   - Multiplication operator `*` for multiplying a matrix by a scalar double quantity.

2. Implement an insertion operator `<<` for:
   - Printing the matrix using `cout`
   - The `cout` insertion operator output for the Matrix should result in exactly the same output as the `print()` method.
   - Printing the matrix to a file.

3. Implement an extraction operator `>>` for reading a matrix from a file. The input file format should resemble:
```
-10.0 20.0
-30.0 40.0
```

4. Use the provided `main2.cpp` to test your implementation. Ensure your Matrix class implementation complies with the interface used in this main file. **You are not permitted to change the `main2.cpp` file in any way.**

## Sample Output

```
a matrix is:
--- ---
| 0.0000 0.0000 |
| |
| 0.0000 0.0000 |
--- ---
... [continue with the rest of the output]
```

## File Output Example
```
-20.0 40.0
-60.0 80.0
```

## Submission

1. Create a git bundle file named `hw3.bundle` containing all your source files.
2. Ensure you have a working Makefile to compile your solution in C++. Your solution should compile without any errors or warnings.
3. Include a screenshot of the test program being executed on YOUR Raspberry Pi computer. **Failure to include this screenshot will result in your program receiving a maximum grade of 50%.**
4. Submit by attaching the git bundle file to the assignment submission page.
5. Ensure adherence to the class policy regarding late submissions. No late submissions are permitted unless prior arrangement has been made with the instructor.
```

You can copy and paste the content above into a `README.md` file for your assignment.