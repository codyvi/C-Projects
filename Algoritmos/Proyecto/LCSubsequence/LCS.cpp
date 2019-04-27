#include <iostream>

using namespace std;

int getlcs(string s1, string s2, int t1, int t2)
{ 
   int DP[t1+1][t2+1]; 

   for (int i=0; i<=t1; i++) 
   { 
     for (int j=0; j<=t2; j++) 
     { 
       if (i == 0 || j == 0) DP[i][j] = 0; 
    
       else if (s1[i-1] == s2[j-1]) 
       {
         DP[i][j] = DP[i-1][j-1] + 1; 
       }
   
       else
       {
         DP[i][j] = ((DP[i-1][j] > DP[i][j-1]) ? DP[i-1][j] : DP[i][j-1]);
       } 
     } 
   } 
     
   return DP[t1][t2]; 
} 
  
int main() 
{ 
    int c;
    int cases = 1;
    cin >> c;
    while(c)
    {
        string s1, s2;
        cin >> s1 >> s2;
        
        int t1 = s1.length();
        int t2 = s2.length(); 
        
        cout << "Case " << cases << ": "<< getlcs( s1, s2, t1, t2 ) << endl;
        c--;
        cases++;
    }
    
    return 0; 
} 