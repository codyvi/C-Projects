#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(){
    LinkedList<string> miLista;
    LinkedList<string> miLista2;

    miLista.addFirst("HOLA");
    miLista.addLast("ADRIAN");
    miLista.addFirst("AMA");
    miLista += "c";

    miLista.print();

    miLista2 = miLista;

    miLista2.print();

    if(miLista == miLista2){
        cout << "son iguales" << endl;
    }

    miLista2 += miLista;
    miLista2.print();


    /* miLista.print();
    miLista.add("PELOS", 2);
    miLista.print();
    miLista.deleteFirst();
    miLista.print();
    miLista.deleteLast();
    miLista.print();
    cout << miLista.set("ADIOS", 1) << endl;
    miLista.print();
    miLista.del(2);
    miLista.print();
    miLista.deleteAll();
    miLista.print();
    miLista.addFirst("M�XICO");
    miLista.print(); */
    //miLista.print();
    //miLista.change(1,2);
    //miLista.reverse();
    //miLista.print();
    /*
    LinkedList<int> *tuLista = new LinkedList<int>();
    tuLista->addFirst(100);
    tuLista->addLast(5);
    tuLista->addFirst(20);
    tuLista->addLast(40);
    tuLista->print();
    delete tuLista;*/

    return 0;
}
