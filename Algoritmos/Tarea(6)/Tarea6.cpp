#include <iostream>
#include <vector>
using namespace std;
int contComp=0;
//&function
void Une(vector<int> &d, int inicio, int m, int fin)
{
    int i, j, k, l[fin-inicio+1];
    i=inicio;
    k=0;
    j=m+1;
    while(i<=m && j<=fin)
    {
        contComp++;
        if(d[i]<d[j])
        {
            l[k]=d[i];
            k++;
            i++;
        }
        else
        {
            l[k]=d[j];
            k++;
            j++;
        }
    }

    while(i<=m)
    {
        l[k]=d[i];
        k++;
        i++;
    }

    while(j<=fin)
    {
        l[k]=d[j];
        k++;
        j++;
    }

    for(int i=inicio; i<=fin; i++)
    {
        d[i]=l[i-inicio];
    }
}

void MergeSort(vector<int> &d, int inicio, int fin){
    int mid;
    if(inicio<fin)
    {
        mid=(inicio+fin)/2;
        MergeSort(d, inicio, mid);
        MergeSort(d, mid+1, fin);
        Une(d, inicio, mid, fin);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> datos(n);
    for (int i=0; i<n; i++){
        cin>>datos[i];
    }
    MergeSort(datos, 0, n-1);
    cout << contComp << endl;
    for (int i=0; i<n; i++){
     cout<<datos[i]<< " ";
     }
}