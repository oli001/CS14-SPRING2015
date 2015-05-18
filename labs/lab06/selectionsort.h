//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<6>/selectionsort.h
/// @brief assignment 3 for CS 14 Spring 2015
///
/// @author Owen Li [oli001@ucr.edu]
/// @date May 17, 2015
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
#include <utility>
#include <list>
#include <map>
#include <vector>

using namespace std;

template<typename T>
bool operator<(T& lhs, T&rhs)
{
    return lhs.first < rhs.first;
}

template<typename L>
void selectionsort(L &l)
{
    auto first = l.begin();
    auto it = l.begin();
    auto min = l.begin();
    int copies = 0;
    int moves = 0;
    
    while(first != l.end())
    {
        ++it;
        
        if(*it < *min && it != l.end())
        {
            min = it;
        }
        
        if(it == l.end())
        {
            if(min != first && *min != *first)
            {
                swap(*min, *first);
                moves += 3;
            }
            ++first;
            it = first;
            min = first;
        }
    }
    
    cout << "copies: " << copies << " moves: " << moves << endl;
}