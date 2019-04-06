#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int c; 
    int n;
    cin >> c;
    
    while(c)
    {
        cin >> n;
        int triang[n][n];
        int m = n-1;
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j>k)
                {
                    triang[k][j]=0;
                }

            	else
                {
	                cin>>triang[k][j];
                }
            }
        }

       for (int h=m-1; h>=0; h--) 
        { 
            for (int s=0; s<=h; s++) 
            { 
         
                if (triang[h+1][s] > triang[h+1][s+1]) 
                {
                    triang[h][s] += triang[h+1][s]; 
                }
            
                else
                {
                    triang[h][s] += triang[h+1][s+1]; 
                }
            } 
        } 

        
        cout << "La suma es: " << triang[0][0] << endl;;
        c--;
    }

}