//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<3>/main.cc
/// @brief lab 3 for CS 14 Spring 2015
///
/// @author Owen Li [oli001@ucr.edu]
/// @date April 22, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: <Dingwen Tao>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>

using namespace std;
#include "lab3.H"

int main()
{
    TwoStackFixed<char> b(12, 6);
    b.pushStack1('a');
    b.pushStack1('b');
    b.pushStack1('c');
    b.pushStack1('d');
    b.pushStack2('a');
    b.pushStack2('b');
    b.pushStack2('c');
    b.pushStack2('d');
    
    b.print();
    cout << endl;
    
    return 0;
}
