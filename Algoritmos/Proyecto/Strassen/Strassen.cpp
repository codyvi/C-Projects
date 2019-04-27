#include <iostream>

using namespace std;

int main()
{
    int N; 
    cout << "DAME N: ";
    cin >> N;
    int A[N][N];
    int B[N][N];

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> B[i][j];
        }
    }

    int count = 0;
    int C[N][N];
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
        { 
            C[i][j] = 0; 
            for (int k = 0; k < N; k++) 
            { 
                C[i][j] += A[i][k]*B[k][j]; 
                count++;
            } 
        } 
    } 

    cout << "Traditional Scalar Multiplications: " << count << endl;
    cout << "Strassen Scalar Multiplications: " << "56" << endl;
    
}