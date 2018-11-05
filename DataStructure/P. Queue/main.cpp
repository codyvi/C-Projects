#include <iostream>
using namespace std;
#include "Priority.h"

int main(){
    Priority myPriority;
    Priority myP2(false);

    if(myPriority.empty())
    {
      cout << "Esta vacia!" << endl;
    }

    cout << "El tamaño de la Lista es de: " << myPriority.size() << endl;

    myPriority.push(14);  
    myPriority.push(10);
    myPriority.push(8);
    myPriority.push(25);
    myPriority.push(73);
    myPriority.push(5);
    myPriority.push(43);
    myPriority.push(17);
    myPriority.push(43);
    myPriority.push(23);

    cout << "El tamaño de la Lista es de: " << myPriority.size() << endl;

    myP2.push(14);
    myP2.push(10);
    myP2.push(8);
    myP2.push(25);
    myP2.push(73);
    myP2.push(5);
    myP2.push(43);
    myP2.push(17);
    myP2.push(43);
    myP2.push(23);
    

    while(!myPriority.empty()){
        cout << myPriority.top() << " ";
        myPriority.pop();
    }

    cout << endl;
    
     while(!myP2.empty()){
        cout << myP2.top() << " ";
        myP2.pop();
    }

    cout << endl;


    return 0;
}