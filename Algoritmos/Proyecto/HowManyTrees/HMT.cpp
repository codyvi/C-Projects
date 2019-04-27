#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

unsigned long long int binomialCoeff(int n, int k) 
{ 
    unsigned long long int C[n + 1][k + 1]; 
    int i, j; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <= min(i, k); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
  
    return C[n][k]; 
} 

unsigned long long int catalan(unsigned int n) 
{ 
	unsigned long long int c = binomialCoeff(2*n, n); 
	
	return c/(n+1);
} 

unsigned long long int countBST(unsigned int n) 
{ 
	unsigned long long int count = catalan(n); 

	return count; 
} 

int main()
{
  	int iN;
  	cin >> iN;
    cout << countBST(iN) << " BTrees" << endl;
}