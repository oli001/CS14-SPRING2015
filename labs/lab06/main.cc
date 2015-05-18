//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<6>/main.cc
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
#include "selectionsort.h"

int main()
{
    list<int> a;
    a.push_back(2);
    a.push_back(4);
    a.push_back(5);
    a.push_back(1);
    a.push_back(8);
    a.push_back(9);
    
    list<int>::iterator ait = a.begin();
    cout << "pre:  ";
    while(ait != a.end())
    {
        cout << *ait << ' ';
        ++ait;
    }
    cout << endl;
    selectionsort(a);
    ait = a.begin();
    cout << "post: ";
    while(ait != a.end())
    {
        cout << *ait << ' ';
        ++ait;
    }
    cout << endl;
    
    list<pair<int, int>> b;
    b.push_back(make_pair(1, 2));
    b.push_back(make_pair(3, -1));
    b.push_back(make_pair(-1, 3));
    b.push_back(make_pair(0, 0));
    b.push_back(make_pair(2, 3));
    b.push_back(make_pair(1, 2));
    b.push_back(make_pair(1, -2));
    b.push_back(make_pair(8, 10));
    auto bit = b.begin();
    cout << "pre: ";
    while(bit != b.end())
    {
        cout << "(" << bit->first << " , " << bit->second << ") ";
        ++bit;
    }
    cout << endl;
    selectionsort(b);
    bit = b.begin();
    cout << "post: ";
    while(bit != b.end())
    {
        cout << "(" << bit->first << " , " << bit->second << ") ";
        ++bit;
    }
    cout << endl;
    
    list<pair<int, int>> c;
    c.push_back(make_pair(10, 2));
    c.push_back(make_pair(-3, -1));
    c.push_back(make_pair(-8, 0));
    c.push_back(make_pair(1, 1));
    c.push_back(make_pair(1, 1));
    c.push_back(make_pair(0, 0));
    c.push_back(make_pair(10, 2));
    c.push_back(make_pair(5, 5));
    c.push_back(make_pair(5, -5));
    c.push_back(make_pair(0, 0));
    c.push_back(make_pair(10, 2));
    auto cit = c.begin();
    cout << "pre: ";
    while(cit != c.end())
    {
        cout << "(" << cit->first << " , " << cit->second << ") ";
        ++cit;
    }
    cout << endl;
    selectionsort(c);
    cit = c.begin();
    cout << "post: ";
    while(cit != c.end())
    {
        cout << "(" << cit->first << " , " << cit->second << ") ";
        ++cit;
    }
    cout << endl;
    
    list<pair<int, int>> d;
    d.push_back(make_pair(-1, 3));
    d.push_back(make_pair(0, 0));
    d.push_back(make_pair(1, -2));
    d.push_back(make_pair(1, 2));
    d.push_back(make_pair(1, 2));
    d.push_back(make_pair(2, 3));
    d.push_back(make_pair(3, -1));
    d.push_back(make_pair(8, 10));
    auto dit = d.begin();
    cout << "pre: ";
    while(dit != d.end())
    {
        cout << "(" << dit->first << " , " << dit->second << ") ";
        ++dit;
    }
    cout << endl;
    selectionsort(d);
    dit = d.begin();
    cout << "post: ";
    while(dit != d.end())
    {
        cout << "(" << dit->first << " , " << dit->second << ") ";
        ++dit;
    }
    cout << endl;
    
    vector<pair<int, int>> e;
    e.push_back(make_pair(-1, -100));
    e.push_back(make_pair(-1, 100));
    e.push_back(make_pair(-1, 50));
    e.push_back(make_pair(-1, 0));
    e.push_back(make_pair(-1, 5));
    auto eit = e.begin();
    cout << "pre: ";
    while(eit != e.end())
    {
        cout << "(" << eit->first << " , " << eit->second << ") ";
        ++eit;
    }
    cout << endl;
    selectionsort(e);
    eit = e.begin();
    cout << "post: ";
    while(eit != e.end())
    {
        cout << "(" << eit->first << " , " << eit->second << ") ";
        ++eit;
    }
    cout << endl;
    
    
    return 0;
}