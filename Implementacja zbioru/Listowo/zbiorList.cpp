#include "zbiorList.h"

int setList::getSize()
{
    return vec.size();
}

bool setList::isInSet(int x)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == x)
            return true;
    }

    return false;
}

void setList::insert(int x)
{
    if(!isInSet(x))
    {
        vec.push_back(x);
    }
}

void setList::withdraw(int x)
{
    auto it = vec.begin();

    for(int i = 0; i < vec.size(); i++)
    {
        if(vec[i] == x)
        {
            vec.erase(it);
        }
        it++;
    }
}

void setList::clearSet()
{
    vec.clear();
}

void setList::printSet()
{
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}

setList setList::operator+(setList &obj)
{
    setList lista3;

    for(int i = 0; i < vec.size(); i++)
    {
        lista3.vec.push_back(vec[i]);
    }

    for(int i = 0; i < obj.vec.size(); i++)
    {
        if(!lista3.isInSet(obj.vec[i]))
            lista3.vec.push_back(obj.vec[i]);
    }

    return lista3;
}

setList setList::operator*(setList &obj)
{
    setList lista3;

    for(int i = 0; i < vec.size(); i++)
    {
        if(obj.isInSet(vec[i]))
        {
            lista3.vec.push_back(vec[i]);
        }
    }

    return lista3;
}

setList setList::operator-(setList &obj)
{
    setList lista3;

    for(int i = 0; i < vec.size(); i++)
    {
        lista3.vec.push_back(vec[i]);
    }

    for(int i = 0; i < lista3.vec.size(); i++)
    {
        if(obj.isInSet(lista3.vec[i]))
        {
            lista3.withdraw(lista3.vec[i]);
        }
    }

    return lista3;
}

bool setList::operator==(setList &obj)
{
    if(vec.size() == obj.vec.size())
    {
        for(int i = 0; i < vec.size(); i++)
        {
            if(!obj.isInSet(vec[i]))
            {
                return false;
            }
        }
    }

    else if(vec.size() != obj.vec.size())
    {
        return false;
    }

    return true;
}

bool setList::operator<=(setList &obj)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(!obj.isInSet(vec[i]))
            return false;
    }

    return true;
}