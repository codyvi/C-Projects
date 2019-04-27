#include <iostream>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <cmath>

using namespace std;

float median(float arr[], int n) 
{ 
    if (n % 2 == 0) 
    {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2; 
    }

    else
    {
        return arr[n / 2]; 
    }
} 


float getMedian(float arr1[], float arr2[], int n) 
{ 
   
    if (n <= 0) 
    {
        return -1; 
    }
    
    if (n == 1) 
    {
        return (arr1[0] + arr2[0]) / 2; 
    }

    if (n == 2) 
    {
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2; 
    }

    float m1 = median(arr1, n); 
  
    float m2 = median(arr2, n); 
  
    if (m1 == m2) 
    {
        return m1; 
    }
  
    if (m1 < m2) 
    { 
        if (n % 2 == 0) 
        {
            return getMedian(arr1 + n / 2 - 1, arr2, n - n / 2 + 1); 
        }

        return getMedian(arr1 + n / 2, arr2, n - n / 2); 
    } 
  
    if (n % 2 == 0) 
    {
        return getMedian(arr2 + n / 2 - 1, arr1, n - n / 2 + 1); 
    }

    return getMedian(arr2 + n / 2, arr1, n - n / 2); 
} 

int main() 
{ 
    int cases;
    cin >> cases;
    float arr1[100];
    float arr2[100];
    for(int i = 0; i < cases; i++)
    {
        int n; 
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> arr1[j];
        }

        for(int k = 0; k < n; k++)
        {
            cin >> arr2[k];
        }

        float test = getMedian(arr1, arr2, n); 
        cout << "Median case " << i+1<<": " << setprecision(2) << fixed <<test << endl;
    }
    return 0; 
} 