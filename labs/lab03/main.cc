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
#include <stack>

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
    
    cout << "Created 12 length stack and push both stacks a, b, c, d: " << endl;
    b.print();
    cout << endl;
    cout << "Pushing until overflow: " << endl;
    b.pushStack1('a');
    b.pushStack2('a');
    b.pushStack1('x');
    b.pushStack2('z');
    b.pushStack1('x');
    b.pushStack2('x');
    
    cout << "Popping back on stack 1: " << b.popStack1() << endl;
    cout << "Popping back on stack 2: " << b.popStack2() << endl << endl;
    
    TwoStackOptimal<char> x(12);
    x.pushStack1('a');
    x.pushStack1('b');
    x.pushStack1('c');
    x.pushStack1('d');
    x.pushStack1('e');
    x.pushStack1('f');
    x.pushStack1('g');
    x.pushStack1('h');
    x.pushStack2('a');
    x.pushStack2('b');
    x.pushStack2('c');
    x.pushStack2('d');
    
    
    cout << "Pushing stack 1 and 2 to fill the entire array: ";
    x.print();
    cout << endl;
    
    cout << "Overflowing stack 1 and 2: " << endl;
    x.pushStack1('i');
    x.pushStack2('e');
    x.print();
    cout << endl;
     
    cout << "Popping back on stack 1: " << x.popStack1() << endl;
    cout << "Popping back on stack 2: " << x.popStack2() << endl;
    
    // stack<int> A;
    // stack<int> B;
    // stack<int> C;

    // A.push(3);
    // A.push(2);
    // A.push(1);
    
    // showTowerStates(3, A, B, C);
    // while(!C.empty())
    // {
    //     cout << C.top() << ' ';
    //     C.pop();
    // }
    
    // cout << endl;
    
    cout << "Unable to finish hanoi towers. " << endl;
    
    return 0;
}
