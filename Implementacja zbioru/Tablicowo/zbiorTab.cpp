#include "zbiorTab.h"

bool setArr::checkRangeCorrectness(int x)
{
	if((x >= 0) && (x <= universeSize))
		return true;

	cout << "Podana liczba" << x << " nie spelnia wymagan." << endl;
	return false;
}

void setArr::clearSet()
{
	for(int i = 0; i < universeSize; i++)
	{
		table[i] = false;
	}
}

setArr::setArr()
{
	this -> table = new bool [universeSize];
	clearSet();
}

void setArr::insert(int x)
{
	if(checkRangeCorrectness(x))
		table[x] = true;
}

void setArr::withdraw(int x)
{
	if(checkRangeCorrectness(x))
		table[x] = false;
}

bool setArr::isInSet(int i)
{
	return table[i];
}

int setArr::getSize()
{
	size = 0;

	for(int i = 0; i < universeSize; i++)
	{
		if(table[i])
			size++;
	}

	return size;
}

setArr setArr::operator+(setArr &object)
{
	setArr object3;

	for(int i = 0; i < universeSize; i++)
	{
		object3.table[i] = table[i] || object.table[i];
	}

	return object3;
}

setArr setArr::operator-(setArr &object)
{
	setArr object3;

	for(int i = 0; i < universeSize; i++)
	{
		object3.table[i] = table[i] &~ object.table[i];
	}

	return object3;
}

setArr setArr::operator*(setArr &object)
{
	setArr object3;

	for(int i = 0; i < universeSize; i++)
	{
		object3.table[i] = table[i] && object.table[i];
	}

	return object3;
}

bool setArr::operator==(setArr &object)
{
	for(int i = 0; i < universeSize; i++)
	{
		if(table[i] == object.table[i])
			continue;
		else
			return false;
	}

	return true;
}

bool setArr::operator<=(setArr &object)
{
	for(int i = 0; i < universeSize; i++)
	{
		if(table[i] == true)
		{
			if(object.table[i] == true)
				continue;
			else
				return false;
		}
	}

	return true;
}

void setArr::printSet()
{
	for(int i = 0; i < universeSize; i++)
	{
		if(table[i]) cout << i << endl;
	}
}
