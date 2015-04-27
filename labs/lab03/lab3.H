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

#include <iostream>
#include <stack>

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
                cout << "Overflow of first stack." << endl;
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
                cout << "Overflow of second stack." << endl;
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
                cout << "Underflow of first stack." << endl;
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
                cout << "Underflow of second stack." << endl;
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

template<typename T>
class TwoStackOptimal
{
    private:
        T* data;
        int size;
        int top1;
        int top2;
        bool isFullStack1()
        {
            if(data[0] != T() && data[size - 1] != T())
            {
                return true;
            }
            
            return false;
        }
        
        bool isFullStack2()
        {
            if(data[0] != T() && data[size - 1] != T())
            {
                return true;
            }
            
            return false;
        }
        
        bool isEmptyStack1()
        {
            int i = top1;
            while(i >= 0)
            {
                if(data[i] != T())
                {
                    return false;
                }
                --i;
            }
            
            return true;
        }
        
        bool isEmptyStack2()
        {
            int i = top2;
            while(i < size)
            {
                if(data[i] != T())
                {
                    return false;
                    ++i;
                }
            }
            return true;
        }
    public:
        TwoStackOptimal(int size)
        {
            this->size = size;
            data = new T[size];
            top1 = size/2;
            top2 = top1 + 1;
        }
        
        void pushStack1(T value)
        {
            if(isFullStack1())
            {
                cout << "Overflow of first stack." << endl;
                return;
            }
            
            if(data[size - 1] != T())
            {
                int i = top2;
                while(data[i] != T())
                {
                    ++i;
                }
                
                int j = i;
                while(j > 0)
                {
                    data[j] = data[j - 1];
                    --j;
                }
                
                data[0] = value;
                top1 = top1 + 1;
                return;
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
                cout << "Overflow of second stack." << endl;
                return;
            }
            
            if(data[size - 1] != T())
            {
                int i = top1;
                while(data[i] != T())
                {
                    --i;
                }
                
                int j = i;
                while(j < size - 1)
                {
                    data[j] = data[j + 1];
                    ++j;
                }
                
                data[size - 1] = value;
                top2 = top2 - 1;
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
                cout << "Underflow of first stack." << endl;
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
                cout << "Underflow of second stack." << endl;
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

template<typename T>
void move(stack<T>& source, stack<T>& destination)
{
    int orig = source.top();
    destination.push(orig);
    source.pop();
}

template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
    if(n == 1)
    {
        move(A, C);
    }
    
    else
    {
        showTowerStates(n - 1, A, C, B);
        move(A,C); 
        showTowerStates(n - 1, C, B, A);
    }
}


