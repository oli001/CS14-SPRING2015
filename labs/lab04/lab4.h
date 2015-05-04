//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<4>/lab4.h 
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

using namespace std;

void copPredorder(int k, int m, int n)
{
    if(m + n >= k)
    {
        return;
    }
    
    cout << m << ' ' << n << endl;
    copPredorder(k, 2*m - n, m);
    copPredorder(k, 2*m + n, m);
    copPredorder(k, m + 2*n, n);
}

void copPostorder(int k, int m, int n)
{
    if(m + n >= k)
    {
        return;
    }
    
    copPostorder(k, 2*m - n, m);
    copPostorder(k, 2*m + n, m);
    copPostorder(k, m + 2*n, n);
    
    cout << m << ' ' << n << endl;
}

void copInorder(int k, int m, int n, priority_queue<pair<int, int>>& pq)
{
    if(m + n >= k)
    {
        return;
    }
    
    pair<int, int> temp;
    temp.first = m;
    temp.second = n;
    pq.push(temp);
    copInorder(k, 2*m - n, m, pq);
    copInorder(k, 2*m + n, m, pq);
    copInorder(k, m + 2*n, n, pq);
}