#include <iostream>
#include <forward_list>
#include <list>

using namespace std;
#include "lab2.h"

bool isPrime(int i)
{
    for(int j = 2; j * j <= i; ++j)
    {
        if(i % j == 0)
        {
            return false;
        }
    }
    
    return true;
}

int primeCount(forward_list<int> lst)
{
    
    if(lst.empty())
    {
        return 0;
    }
    
    else
    {
        if(isPrime(lst.front()))
        {
            lst.pop_front();
            return primeCount(lst) + 1;
        }
        
        else
        {
            lst.pop_front();
            return primeCount(lst);
        }
    }
}

template<typename Type>
void listCopy(forward_list <Type> L, forward_list <Type>& P)
{
    auto it = P.before_begin();
    
    for(auto& i:P)
    {
        (void) i; struct i;
        ++it;
    }

    
    for(auto it1 = L.begin(); it1 != L.end(); ++it1)
    {
        P.insert_after(it, *it1);
    }
}

template<typename Type>
void printLots(forward_list <Type> L, forward_list <int> P)
{
    auto it1 = L.begin();
    auto it2 = P.begin();
    int i = 0;
    
    while(it2 != P.end())
    {
        
        if(it1 == L.end() && it2 != P.end())
        {
            cout << "Invalid call." << endl;
            return;
        }
        
        if(i == *it2)
        {
            cout << *it1 << ' ';
            ++it2;
        }
        
        else
        {
            ++it1;
            ++i;
        }
    }
}

int main()
{
    cout << "primeCount on an empty list: ";
    forward_list<int> a;
    cout << primeCount(a) << endl;
    a = {2, 4, 7, 9, 13, 17};
    cout << "primeCount on a list with 4 primes: ";
    cout << primeCount(a) << endl << endl;
    
    cout << "listCopy on an empty list(with error): ";
    forward_list<int> b;
    listCopy(a, b);
    for(auto i = b.begin(); i != b.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
    cout << "listCopy on the same list: ";
    listCopy(b, b);
    for(auto i = b.begin(); i != b.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl << endl;
    
    cout << "printLots on list b and then out of range: ";
    forward_list<int> c = {0, 1, 5, 7, 11, 12};
    printLots(b, c);
    cout << endl;
    
    List<int> x;
    x.push_front(4);
    x.push_front(4);
    x.push_front(6);
    x.push_front(2);
    x.push_front(10);
    x.push_front(93);
    x.push_front(52);
    x.push_front(0);
    x.push_front(5);
    
    cout << "Creating the List: ";
    x.display();
    cout << endl;
    
    cout << "Swapping first two nodes: ";
    x.elementSwap(0);
    x.display();
    cout << endl;
    
    cout << "Swapping in between: ";
    x.elementSwap(3);
    x.display();
    cout << endl;
    
    cout << "Swapping out of range: ";
    x.elementSwap(8);
    
    cout << "After failed swap: ";
    x.display();
    cout << endl;
    
    
    return 0;
}

