//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<5>/main.cc
/// @brief assignment 3 for CS 14 Spring 2015
///
/// @author Owen Li [oli001@ucr.edu]
/// @date May 10, 2015
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
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>

using namespace std;
#define nil 0

#include "lab5.h"

int main()
{
    BST<int> a;
    a.insert(50);
    a.insert(20);
    a.insert(10);
    a.insert(40);
    a.insert(35);
    a.insert(45);
    a.insert(60);
    a.insert(70);
    
    cout << "Part 1" << endl;
    a.displayMinCover();
    
    int buffer[100];
    
    cout << "Part 2" << endl;
    a.findSumPath(80, buffer);
    cout << endl;
    
    map<int, int> m;
    int hd = 0;
    cout <<"Part 3" << endl;
    a.vertSum(hd, m);
    cout << endl;
    
    return 0;
}