#include "kopiec.h"
#include "kopiec.cpp"

int main()
{
    KolejkaPrio kolejka;

    kolejka.insert(16);
    kolejka.insert(7);
    kolejka.insert(6);
    kolejka.insert(15);
    kolejka.insert(3);
    kolejka.insert(10);
    kolejka.insert(20);
    kolejka.insert(8);
    kolejka.insert(5);
    kolejka.insert(2);

    cout << endl;
    kolejka.print();

    cout << endl;
    cout << endl;

    cout << "Kolejka po usunieciu korzenia " << kolejka.removeRootElem() << endl;

    kolejka.print();

    cout << endl;

    cout << "Nowy korzen " << kolejka.getRootElem() << endl;
    
    return 0;
}