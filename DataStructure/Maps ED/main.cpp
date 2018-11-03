#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, int> miMap;
    int n, edad;
    string nom;

    cout << "Dame n: ";
    cin >> n;

    for(int i = 1; i <=n; i++)
    {   cout << "Dame tu nombre y edad: ";
        cin >> nom >> edad;
        pair<string, int> miPar(nom, edad);
        miMap.insert(miPar);
    }

    cout << "Dar el nombre a buscar: ";
    cin >> nom;
    map<string, int>::iterator it = miMap.find(nom);
    if(it != miMap.end())
    {
        cout << it->second << endl;
    }
    else
    {
        cout << "No esta" << endl;
    }
}
