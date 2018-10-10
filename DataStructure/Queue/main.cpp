#include <iostream>
#include "Queue.h"

using namespace std;


int main()
{
    Queue<int> miFila;

    miFila.push(10);
    miFila.push(20);
    miFila.push(30);

    cout << "Tam: " << miFila.size() << endl;

    while(!miFila.empty())
    {
        cout << miFila.front() << endl;
        miFila.pop();
    }

    return 0;
}
