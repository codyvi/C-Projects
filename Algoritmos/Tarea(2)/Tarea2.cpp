#include <iostream>
#include <string>

using namespace std;

int main()
{
    int size;
    //cout << "Dame el size del string: ";
    cin >> size;

    string s; 
    //cout << "Dame el string: ";
    cin >> s;

    int unos = 0;
    int ceros = 0;
    int resta = 0;

   //cout << s;

    for(int i = 0; i <size; i++)
    {
        if(s[i] == '1')
        {
           unos++;
        }

        else
        {
            ceros++;
        }
    }

    if(ceros > unos)
    {
        resta = ceros - unos;
    }

    else
    {
        resta = unos - ceros;
    }

    cout << resta << endl;

    return 0;
}