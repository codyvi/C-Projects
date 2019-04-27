#include <iostream>

using namespace std;


int ball(int bPower, int act[], int toR[], int iSoldiers, int &SoldiersParados)
{
    int iTemp;
    int iCounter = 0;
    bool TodosVivos = 1;

    for(int i = 0; i < iSoldiers && TodosVivos; i++)
    {
        if(act[i] != 0)
        {
            TodosVivos = 0;
            iTemp = act[i];
            act[i] -= bPower;

            if(act[i] < 0)
            {
                act[i] = 0;
            }

            if(act[i] == 0)
            {
                iCounter++;
                TodosVivos = 1;
            }

            bPower -= (iTemp-act[i]);
        }
    }

    if(act[iSoldiers - 1] == 0)
    {
        for(int i = 0; i < iSoldiers; i++) 
        {
           act[i] = toR[i];
        }

        SoldiersParados = iSoldiers;
        iCounter = 0;
    }
    SoldiersParados -= iCounter;
    return SoldiersParados; 
}

int main()
{

    int iSoldiers, iQ, iTmp;

     cin >> iSoldiers >> iQ;

    int arrSoldiers[iSoldiers]; 
    int arrGolpes[iQ];
    int iarrAux[50];

    for(int i = 0; i < iSoldiers; i++)
    {
        cin >> iTmp;
        arrSoldiers[i] = iTmp;
    }

    for(int i = 0; i < iQ; i++)
    {
        cin >> iTmp;
        arrGolpes[i] = iTmp;
    }
    
    for(int i = 0; i < iSoldiers; i++) 
    {
        iarrAux[i] = arrSoldiers[i];
    }

    int SoldadosParados = iSoldiers;
   
    for(int i = 0; i < iQ; i++)
    {
        cout << ball(arrGolpes[i], iarrAux, arrSoldiers, iSoldiers, SoldadosParados) << endl;
    }

    return 0; 

}
