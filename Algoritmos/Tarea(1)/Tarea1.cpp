#include <iostream> 
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Dame el string: " ;
    cin >> s;
    int l = 0, r = s.length()-1;
    int nodoM, li;
    nodoM = (l+r)/2;
    while(l<r)
    {
        if(s[nodoM+1] != s[nodoM] && s[nodoM-1] != s[nodoM])
        {
            cout << s[nodoM] << endl;
            return 0;
        }

        if(s[nodoM] == s[nodoM+1])
        {
            li = nodoM;
            if(li%2==0)
            {
                l = nodoM+1;
            }
            else
            {
                r = nodoM-1;
            }
        }

        else if(s[nodoM] == s[nodoM-1])
        {
            li = nodoM-1;
            if(li%2==0)
            {
                l = nodoM+1;
            }
            else
            {
                r = nodoM-1;
            }
        }
        
        nodoM = (r+l)/2;
    }

    cout << s[nodoM] << endl;
}