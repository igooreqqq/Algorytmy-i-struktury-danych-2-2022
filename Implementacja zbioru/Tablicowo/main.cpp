#include "zbiorTab.h"
#include "zbiorTab.cpp"


int main()
{
	setArr zbior;
	setArr zbior2;
	
    zbior.insert(5);
	zbior.insert(8);
	zbior.insert(2);

    cout << "Zbior1 po dodaniu elementow: " << endl;
    zbior.printSet();

	zbior2.insert(5);
	zbior2.insert(2);
    zbior2.insert(15);

    cout << "Zbior2 po dodaniu elementow: " << endl;
    zbior2.printSet();

    cout << "Zbior2 po usunieciu elementu 15: " << endl;
    zbior2.withdraw(15);
    zbior2.printSet();

    cout << "Czy w zbiorze1 jest element 8?" << endl;
    if(zbior.isInSet(8))
        cout << "Element 8 jest w zbiorze." << endl;
    else
        cout << "Elementu 8 nie ma w zbiorze." << endl;

	cout << "Czy w zbiorze2 jest element 8?" << endl;
    if(zbior2.isInSet(8))
        cout << "Element 8 jest w zbiorze2." << endl;
    else
        cout << "Elementu 8 nie ma w zbiorze2." << endl;

    cout << "Rozmiar zbioru1: " << zbior.getSize() << endl;
    cout << "Rozmiar zbioru2: " << zbior2.getSize() << endl;

	setArr zbiorSuma = zbior + zbior2;
    cout << "Suma zbioru1 i zbioru2: " << endl;
    zbiorSuma.printSet();

    setArr zbiorIloczyn = zbior * zbior2;
    cout << "Czesc wspolna zbioru1 i zbioru2: " << endl;
    zbiorIloczyn.printSet();

    setArr zbiorMinus = zbior - zbior2;
    cout << "Roznica zbioru1 i zbioru2: " << endl;
    zbiorMinus.printSet();

    cout << "Czy zbiory sa sobie rowne? " << endl;
    if(zbior == zbior2)
        cout << "Zbiory sa sobie rowne." << endl;
    else
        cout << "Zbiory nie sa sobie rowne" << endl;

    cout << "Czy zbior2 jest podzbiorem zbioru1?" << endl;
    if(zbior2 <= zbior)
        cout << "Tak" << endl;
    else
        cout << "Nie" << endl;

    zbior.clearSet();
    zbior2.clearSet();

    if(zbior.getSize() == 0)
        cout << "Zbior1 zostal wyczyszczony." << endl;
    else
        cout << "Zbior1 nie zostal wyczyszczony." << endl;

    if(zbior2.getSize() == 0)
        cout << "Zbior2 zostal wyczyszczony." << endl;
    else
        cout << "Zbior2 nie zostal wyczyszczony." << endl;

    return 0;
}