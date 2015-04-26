//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<3>/lab3.h
/// @brief lab 3 for CS 14 Spring 2015
///
/// @author Owen Li [oli001@ucr.edu]
/// @date April 24, 2015
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
#ifndef LAB3_H_
#define LAB3_H_

#include <iostream>

using namespace std;

template<typename T>
class TwoStackFixed
{
    private:
        T* data;
        int size;
        int top1;
        int top2;
        bool isFullStack1()
        {
            if(data[0] != T())
            {
                return true;
            }
            
            return false;
        }
        
        bool isFullStack2()
        {
            if(data[size - 1] != T())
            {
                return true;
            }
            
            return false;
        }
        
        bool isEmptyStack1()
        {
            if(data[top1] == T())
            {
                return true;
            }
            
            return false;
        }
        
        bool isEmptyStack2()
        {
            if(data[top2] == T())
            {
                return true;
            }
            
            return false;
        }
    public:
        TwoStackFixed(int size, int maxTop)
        {
            this->size = size;
            data = new T[size];
            top1 = maxTop - 1;
            top2 = maxTop;
        }
        
        void pushStack1(T value)
        {
            if(isFullStack1())
            {
                cout << "Overflow." << endl;
            }
            
            else
            {
                int i = top1;
                while(data[i] != T())
                {
                    --i;
                }
                
                data[i] = value;
            }
        }
        
        void pushStack2(T value)
        {
            if(isFullStack2())
            {
                cout << "Overflow." << endl;
                return;
            }
            
            else
            {
                int i = top2;
                while(data[i] != T())
                {
                    ++i;
                }
                
                data[i] = value;
            }
        }
        
        T popStack1()
        {
            if(isEmptyStack1())
            {
                cout << "Underflow." << endl;
                return T();
            }
            
            else
            {
                int i = top1;
                while(data[i] != T())
                {
                    --i;
                }
                
                ++i;
                T popped = data[i];
                data[i] = T();
                return popped;
            }
        }
        
        T popStack2()
        {
            if(isEmptyStack2())
            {
                cout << "Underflow." << endl;
                return T();
            }
            
            else
            {
                int i = top2;
                while(data[i] != T())
                {
                    ++i;
                }
                
                --i;
                T popped = data[i];
                data[i] = T();
                return popped;
            }
        }
        
        void print()
        {
            for(auto i = 0; i < size; ++i)
            {
                if(data[i] == T())
                {
                    cout << "  ";
                }
                
                else
                {
                    cout << data[i] << ' ';
                }
            }
        }
};

#endif