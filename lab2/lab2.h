#include <iostream>

using namespace std;

template <class Type>
struct Node
{

    Type data;
    
    Node<Type> *next;
    
    Node(Type data) : data(data), next(0) {}

};

template<class Type>
class List
{
     private:
        Node<Type> *head;
    public:
        List();
        ~List();
        void display() const;
        void push_front(Type value);
        void elementSwap(int pos);
        
};

template<class Type>
List<Type>::List()
{
    head = NULL;
}

template<class Type>
List<Type>::~List()
{
    Node<Type> *previous;
    Node<Type> *current = head;
    while(current != NULL)
    {
        previous = current;
        current = current->next;
        delete previous;
    }
}

template<class Type>
void List<Type>::display() const
{
    Node<Type> *current = head;
    if(head == NULL)
    {
        return;
    }
    
    else if(head->next == NULL)
    {
        cout << current->data;
    }
    
    else
    {
        while(current->next != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << current->data;
    }
}

template<class Type>
void List<Type>::push_front(Type value)
{
    Node<Type> *current;
    current = new Node<Type>(value);
    
    if(head == NULL)
    {
        head = current;
    }
    else
    {
        current->next = head;
        head = current;
    }
}
    
    

template<class Type>
void List<Type>::elementSwap(int pos)
{
    if(head == NULL || head->next ==NULL)
    {
        cout << "Error" << endl;
        return;
    }
    
    if(pos == 0)
    {
        Node<Type>* temp = head->next;
        head->next = temp->next;
        temp->next = head;
        head = temp;
        return;
    }
    
    else
    {
        Node<Type> *current = head;
        int h = 0;
        
        while(current->next != NULL)
        {
            current = current->next;
            ++h;
        }
        
        if(pos >= h)
        {
            cout << "Error" << endl;
            return;
        }
        
        Node<Type> *current1 = head;
        Node<Type> *current2 = head;
        Node<Type> *current3 = head;
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < pos - 1)
        {
            current1 = current1->next;
            ++i;
        }
        while(j < pos)
        {
            current2 = current2->next;
            ++j;
        }
        while(k < pos + 1)
        {
            current3 = current3->next;
            ++k;
        }
        
        if(current3->next == NULL)
        {
            current1->next = current3;
            current2->next = NULL;
            current3->next = current2;
            return;
        }
        
        current1->next = current3;
        current2->next = current3->next;
        current3->next = current2;
    }
}