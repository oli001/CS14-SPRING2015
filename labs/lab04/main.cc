//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<4>/main.cc
/// @brief lab 4 for CS 14 Spring 2015
///
/// @author Owen Li [oli001@ucr.edu]
/// @date May 3, 2015
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
#include <queue>
#include <stack>

using namespace std;
#include "lab4.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "Incorrect Usage." << endl;
        exit(-1);
    }
    
    int k = stoi(argv[1],nullptr);
    
    cout << "pre-order: " << endl;
    
    copPredorder(k, 2, 1);
    copPredorder(k, 3, 1);
    
    cout << endl << "post-order: " << endl;
    
    copPostorder(k, 2, 1);
    copPostorder(k, 3, 1);
    
    
    cout << endl << "sorted: " << endl;
    priority_queue<pair<int, int>> pq;
    copInorder(k, 2, 1, pq);
    copInorder(k, 3, 1, pq);
    
    stack<pair<int,int>> printOut;
    
    while(!pq.empty())
    {
        printOut.push(pq.top());
        pq.pop();
    }
    
    while(!printOut.empty())
    {
        cout << (printOut.top()).first << ' ' << (printOut.top()).second 
            << endl;
        printOut.pop();
    }
    
    return 0;
}