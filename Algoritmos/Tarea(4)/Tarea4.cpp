#include <iostream>
#include <math.h>

using namespace std;


int algo(int iArr[], int N)
{
    if(N <= 0)
    {
        return 0;
    }
    
    if(iArr[0] % 2 != 0)
    {
         return iArr[0] + algo(iArr + 1, N - 1);
    }

    else
    {

         return algo(iArr + 1, N - 1);
    }
}

int main()
{
    int iArr[] = {1,4,3,5,7,8,11};

    /*  
    
        Arreglo: 1 4 3 5 7 8 11
        Valores Impares: 1, 3, 5, 7, 11
        Suma: 27

    */

  
   
   int n = sizeof(iArr) / sizeof(iArr[0]); 
   int Suma = 0;
   for(int i = 0; i < n; i++)
   {
       if(iArr[i]%2 != 0)
       {
           Suma += iArr[i];
           cout << iArr[i];
       }
   }

   cout << "La suma de los numeros impares del arreglo es: " << Suma << endl;
   cout << "La suma de todos los numeros impares del arreglo (recuriva) es: "<< algo(iArr, n) << endl;
    
   return 0;

}
