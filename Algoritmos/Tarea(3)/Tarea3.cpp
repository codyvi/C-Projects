#include <iostream> 

using namespace std; 

int main()
{
    int a[100000];
    for(int i = 0; i < 5; i++)
    {
        cout << "Dame los numeros del arreglo: ";
        cin >> a[i];
    }

    int b[100][100];

    int sumatoria = 0;
    /*
     0   1   2   3

0    1   3   6  10
1    3   2   5   9
2    6   5   3   7
3    10  9   7   4
    */
    

 int n = 5;

 int k = 0; 

/*
 while(k < n)
 {
     b[k][k] = a[k];
     k++;
     sumatoria +=a[k];
     b[0][k] = b[k][0] = sumatoria;
     b[1][k] = b[k][1] = sumatoria -1;
     b[2][k+1] = b[k+1][2] = sumatoria+1;
 }

   */

for(int i = 0; i<n; i++)
{
    b[i][i] = a[i];
    for(int j = 0; j < n; j++)
    {
        if(i!=j)
        {
            b[i][j]= b[j][i] = a[i]+b[i-1][j];
        }
    }
}

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

}