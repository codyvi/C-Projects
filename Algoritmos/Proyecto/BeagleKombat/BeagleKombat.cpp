#include <iostream>
#include <string>
#include <queue> 

using namespace std;

int main()
{

    int n, k, tmp;
    int suma = 0;
    char control; 
    int lenghtOfEqual = 0;
    cin >> n >> k;
    int iArrDamage[n];
    priority_queue <int> Golpes;
    string buttons;
    bool isDif = false; 
    bool isEqual = false;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp; 
        iArrDamage[i] = tmp;
    }

    cin >> buttons;
    Golpes.push(iArrDamage[0]);
    control = buttons[0];
    for(int i = 1; i < n; i++)
    {
        if(control == buttons[i])
        {
            Golpes.push(iArrDamage[i]);
        }

        else
        {
            if(Golpes.size() <= k)
            {
                while(!Golpes.empty())
                {
                    suma += Golpes.top();
                    //cout << Golpes.top() << endl;
                    Golpes.pop();
                }
            }    
            else
            {
                for(int j = 0; j < k; j++)
                {
                    suma += Golpes.top();
                    //cout << Golpes.top() << endl;
                    Golpes.pop();
                }

                while(!Golpes.empty())
                {
                    Golpes.pop();
                }
            }

            control = buttons[i];
            Golpes.push(iArrDamage[i]);
            
        }
    }

    for(int i = 0; i < k && !Golpes.empty(); i++)
    {
        suma += Golpes.top();
        Golpes.pop();
    }

    cout << suma << endl;
}

/*
7 3
1 5 16 18 7 2 10
baaaaca
*/

/*
7 2
1 5 16 18 7 2 10
baaaaca
*/