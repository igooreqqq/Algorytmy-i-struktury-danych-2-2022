#pragma once
#include <iostream>
#include <vector>

using namespace std;


class KolejkaPrio
{
    vector<int> vec;

    public:
        int parent(int i);
        int leftChild(int i);
        int rightChild(int i);
        void heapUp(int i);
        void heapDown(int i);
        void insert(int x);
        int removeRootElem();
        void print();
        int getRootElem();
};