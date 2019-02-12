#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

//&function

void Particion(vector<int> &d, int ini, int fin, int &pivote)
{
    int elempivote = d[ini], j = ini, x;
    for(int i = ini+1; i <= fin; i++)
    {
        contComp++;  
        if(d[i] < elempivote)
        {
            j = j+1;
            x = d[j];
            d[j] = d[i];
            d[i] = x;
        }
        
    }
    pivote = j;
    x = d[ini];
    d[ini] = d[pivote];
    d[pivote] = x;
	
}

void QuickSort(vector<int> &d, int ini, int fin)
{
    int pivote = ini;
    if(ini < fin)
    {
        Particion(d,ini,fin,pivote);
        QuickSort(d, ini, pivote-1);
        QuickSort(d, pivote+1, fin);
    }

}

int main()
{
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++)
    {
		cin>>datos[i];
	}
	QuickSort(datos, 0, n-1);
    cout << endl;
	cout << contComp<<endl;
	
	for (int i=0; i<n; i++){
		cout<<datos[i]<< " ";
	} 
	cout << endl;
	
}