#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> miPila;
    miPila.push(10);
    miPila.push(20);
    miPila.push(30);

    cout << "Tamaño: " << miPila.size() << endl;
    while(!miPila.empty())
    {
        cout << miPila.top() << endl;
        miPila.pop();
    }

}
