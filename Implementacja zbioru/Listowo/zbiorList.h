#pragma once
#include<iostream>
#include <vector>

using namespace std;

class setList
{
    vector<int> vec;

    public:
        int getSize();  
        void printSet(); 
        void insert(int x);
        void withdraw(int x);
        bool isInSet(int x); 
        void clearSet();
        setList operator+(setList& obj);  
        setList operator*(setList& obj);   
        setList operator-(setList& obj);
        bool operator==(setList& obj);  
        bool operator<=(setList& obj);
};