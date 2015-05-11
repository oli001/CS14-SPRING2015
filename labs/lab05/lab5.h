//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab<5>/lab5.h
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

#ifndef BST_H
#define BST_H

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

// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    class Node 
    { // binary tree node
        int size(Node* x)
        {
            if(x == 0)
            {
                return 0;
            }
            
            if(x->left == 0 && x->right == 0)
            {
                return 1;
            }
            
            return 1 + size(x->right) + size(x->left);
        }
        
        int nodeHeight(const Node* x)
        {
            int height = 0;
            if(x) 
            {
                if (x->left || x->right) 
                {
                    int leftHeight = 0;
                    int rightHeight = 0;
                    if (x->left) 
                    {
                        leftHeight = nodeHeight(x->left);
                    }
                    if (x->right) 
                    {
                        rightHeight = nodeHeight(x->right);
                    }
                    if (leftHeight > rightHeight) 
                    {
                        height = leftHeight + 1;
                    } 
                    else 
                    {
                        height = rightHeight + 1;
                    }
                }
            }
            return height;
        }
        public:
            Value value;
            Node* left;
            Node* right;
            Node(const Value v = Value()): value(v), left(nil), right(nil) {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            
            int height() 
            {
                // returns the height of the subtree rooted at this node
                return nodeHeight(this);
            }
            
            int size() 
            {
                if(this = 0)
                {
                    return 0;
                }
                // returns the size of the subtree rooted at this node,
                return size(this);
                
            }
    }; 
    // Node
    // const Node* nil; // later nil will point to a sentinel node.
    int size(Node* x)
    {
        if(x == 0)
        {
            return 0;
        }
        
        if(x->left == 0 && x->right == 0)
        {
            return 1;
        }
        
        return 1 + size(x->right) + size(x->left);
    }
    int count;
    Node* root;
    
    void preorder(Node* x) const
    {
        if(x == 0)
        {
            return;
        }
        
        print_node(x);
        preorder(x->left);
        preorder(x->right);
        
    }
    
    void postorder(Node* x) const
    {
        if(x == 0)
        {
            return;
        }
        
        print_node(x);
        postorder(x->right);
        postorder(x->left);
    }
    
    void inorder(Node* x) const
    {
        if(x == 0)
        {
            return;
        }
        
        if(x->left == 0)
        {
            print_node(x);
        }
        
        inorder(x->left);
        if(x->left != 0)
        {
            print_node(x);
        }
        inorder(x->right);
        
    }
    
    void makeVector(vector<Node*>& mak, Node* x)
    {
        if(x == 0)
        {
            return;
        }
        
        if(x->left == 0)
        {
            mak.push_back(x);
        }
        
        makeVector(mak, x->left);
        if(x->left != 0)
        {
            mak.push_back(x);
        }
        
        makeVector(mak, x->right);
    }
    
    void DFS(vector<Node*>& v, int& count, Node* x) 
    {
        if(x->left)
        {
            if(x->left->left || x->left->right)
            {
                DFS(v, count, x->left);
            }
            
            else
            {
                ++count;
                v.push_back(x);   
            }
        }
        
        if(x->right)
        {
            if(x->right->left || x->right->right)
            {
                DFS(v, count, x->right);
            }
            
            else
            {
                if(v.back() == x)
                {
                    return;
                }
                ++count;
                v.push_back(x);   
            }
        }
        
        else
        {
            return;
        }
    }
    
    void findSumPath(Node* n, int sum, int buffer[], int& bufferSize)
        {
            if (n == 0)
            {
                return;
            }
            
            else
            {
                int subSum = sum - n->value;
                buffer[bufferSize] = n->value;
                ++bufferSize;
                /* If we reach a leaf node and sum becomes 0 then print*/
                if (n->left == NULL && n->right == NULL)
                {
                    if( subSum == 0)
                    {
                        for(int i = 0; i < bufferSize; ++i)
                        {
                            cout << buffer[i] << ' ';
                        }
                        
                        for(int i = 0; i < bufferSize; ++i)
                        {
                            buffer[i] = 0;
                        }
                        
                        bufferSize = 0;
                    }
                    
                    else
                    {
                        for(int i = 0; i < bufferSize; ++i)
                        {
                            buffer[i] = 0;
                        }
                        
                        bufferSize = 0;
                    }
                }
                
                if(n->left)
                {
                    findSumPath(n->left, subSum, buffer, bufferSize);
                }
                if(n->right)
                {
                    findSumPath(n->right, subSum, buffer, bufferSize);
                }
            }
        }
    public:
        int size() 
        {
            if(root == 0)
            {
                return 0;
            }
            // size of the overall tree.
            return size(root);
        }
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) const
        {
            // Print the node’s value.
            cout << n->value << endl;
        }
        
        bool search ( Value x ) 
        {
            // search for a Value in the BST and return true iff it was found.
            Node* curr = root;
            while(curr != 0)
            {
                if(x == curr->value)
                {
                    return true;
                }
                
                else if(x < curr->value)
                {
                    curr = curr->left;
                }
                
                else if(x > curr->value)
                {
                    curr = curr->right;
                }
            }
            
            return false;
        }
        
        void preorder()const 
        {
            // Traverse and print the tree one Value per line in preorder.
            preorder(root);
        }
        
        void postorder()const 
        {
            // Traverse and print the tree one Value per line in postorder.
            postorder(root);
        }
        
        void inorder()const 
        {
            // Traverse and print the tree one Value per line in inorder.
            inorder(root);
        }
        
        Value& operator[] (int n) 
        {
            // returns reference to the value field of the n-th Node.
            vector<Node*> use;
            makeVector(use, root);
            
            return ((use.at(n))->value);
            
        }
        
        BST() : count(0), root(nil) {}
        
        void insert( Value X ) { root = insert( X, root ); }
        
        Node* insert( Value X, Node* T ) 
        {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) 
            {
                T = new Node( X ); // the only place that T gets updated.
            } 
            else if ( X < T->value ) 
            {
                T->left = insert( X, T->left );
            } 
            else if ( X > T->value ) 
            {
                T->right = insert( X, T->right );
            } 
            else 
            {
                T->value = X;
            }
            // later, rebalancing code will be installed here
            return T;
        }
        
        void remove( Value X ) { root = remove( X, root ); }
        
        Node* remove( Value X, Node*& T ) 
        {
        // The normal binary-tree removal procedure ...
        // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                    T->right = remove( X, T->right );
                } 
                
                else if ( X < T->value ) 
                {
                    T->left = remove( X, T->left );
                } 
                
                else 
                { // X == T->value
                    if ( T->right != nil ) 
                    {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value
                        T->right = remove( T->value, T->right );
                    } 
                
                    else if ( T->left != nil ) 
                    {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value
                        T->left = remove( T->value, T->left );
                    } 
                
                    else 
                    { // *T is external
                        delete T;
                        T = nil; // the only updating of T
                    }
                }
            }   
            // later, rebalancing code will be installed here
            return T;
        }
        void okay( ) { okay( root ); }
        
        void okay( Node* T ) 
        {
            // diagnostic code can be installed here
            return;
        }
        
        int rootHeight()
        {
            Node* temp = root;
            return temp->height();
        }
        
        void minCover()
        {
            int count = 0;
            vector<Node*> v;
            DFS(v, count, root);
        }
        
        void displayMinCover()
        {
            int count = 0;
            vector<Node*> v;
            DFS(v, count, root);
            for(auto it = v.begin(); it != v.end(); ++it)
            {
                cout << (*it)->value << ' ';
            }
            
            cout << endl << count << endl;
        }
        
        void findSumPath(Node* n, int sum, int buffer[])
        {
            int bufferSize = 0;
            findSumPath(n, sum, buffer, bufferSize);
        }
        
        void findSumPath(int sum, int buffer[])
        {
            findSumPath(root, sum, buffer);
        }
        
         void vertSum(Node* node, int hd, map<int, int>& m)
         {
            if(node == NULL)
            {
             return;
            }
            
            vertSum(node->left, hd - 1, m);
            m[hd] += node->value;
            vertSum(node->right, hd + 1, m);
         }
         
         void vertSum(int hd, map<int, int>& m)
         {
             vertSum(root, hd, m);
             for(auto it = m.begin(); it != m.end(); ++it)
             {
                 cout << it->second << ' ';
             }
         }
        
}; // BST


#endif