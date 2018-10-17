#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#include "BST.h"

int main()
{
    BST miArbol,miArbol2, A, B;

    miArbol.add(12);
    miArbol.add(100);
    miArbol.add(45);
    miArbol.add(50);
    miArbol.add(8);
    miArbol.add(10);
    miArbol.add(-5);
    miArbol.add(65);
    miArbol.add(13);
    
    miArbol2.add(12);
    miArbol2.add(100);
    miArbol2.add(45);
    miArbol2.add(50);
    miArbol2.add(8);
    miArbol2.add(10);
    miArbol2.add(-5);
    miArbol2.add(65);
    miArbol2.add(13);

    // cout<<"1"<<endl;
    // miArbol.print(1);
    // cout<<"2"<<endl;
    // miArbol.print(2);
    // cout<<"3"<<endl;
    // miArbol.print(3);
    // cout<<"4"<<endl;
    // miArbol.print(4);
    // cout<<"5"<<endl;
    // miArbol.print(5);

    // if(miArbol.search(100)){
    //  cout<<"Encontro"<<endl;
    // } else{
    //  cout <<" No encontro"<<endl;
    // }

    cout<<endl<<miArbol.count()<<endl;

    cout<<miArbol.height()<<endl;
    cout<<"Los ancestros de 50 son: ";
    miArbol.ancestors(50);
    cout<<"Los ancestros de 12 son: ";
    miArbol.ancestors(12);
    cout<<"Los ancestros de 102 son: ";
    miArbol.ancestors(102);

    cout<<"El nivel del dato 50 es: "<<miArbol.whatLevelamI(50)<<endl;
    cout<<"El nivel del dato 102 es: "<<miArbol.whatLevelamI(102)<<endl;
    cout<<"El nivel del dato 12 es: "<<miArbol.whatLevelamI(12)<<endl;


    cout<< "El pariente más cercano de 13 y 65 es: " <<miArbol.nearstRelative(13,65)<<endl;

    cout<<miArbol.maxWidth()<<endl;

    if(miArbol == miArbol2)
    {
        cout << "Los arboles son iguales" << endl;
    }

    else
    {
        cout << "Mis arboles no son iguales" << endl;
    }

    return 0;
}
