#include "kopiec.h"

int KolejkaPrio::parent(int i)
{
    return (i - 1) / 2;
}

int KolejkaPrio::leftChild(int i)
{
    return ((2 * i) + 1);
}

int KolejkaPrio::rightChild(int i)
{
    return ((2 * i) + 2);
}

void KolejkaPrio::heapUp(int i)
{
    while(i > 0 && vec[parent(i)] < vec[i])
    {
        swap(vec[parent(i)], vec[i]);
        i = parent(i);
    }
}

void KolejkaPrio::heapDown(int i)
{
    int maxIndex = i;

    int lChild = leftChild(i);

    if(lChild <= vec.size() && vec[lChild] > vec[maxIndex])
    {
        maxIndex = lChild;
    }

    int rChild = rightChild(i);

    if(rChild <= vec.size() && vec[rChild] > vec[maxIndex])
    {
        maxIndex = rChild;
    }

    if(i != maxIndex)
    {
        swap(vec[i], vec[maxIndex]);
        heapDown(maxIndex);
    }
}

int KolejkaPrio::removeRootElem()
{
    int root = vec[0];

    vec[0] = vec[vec.size() - 1];
    vec.pop_back();
    heapDown(0);

    return root;
}

void KolejkaPrio::insert(int x)
{
    vec.push_back(x);

    auto it = vec.begin();

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == x)
        {
            heapUp(i);
        }
        it++;
    }
}

int KolejkaPrio::getRootElem()
{
    return vec[0];
}

void KolejkaPrio::print()
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(i == 0)
        {
            cout << vec[i] << " : ";
            continue;
        }
            
        
        if(i % 2 != 0)
            cout << vec[i] << " ";

        if(i % 2 == 0)
            cout << vec[i] << " : ";
    }
}