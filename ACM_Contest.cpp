/*
    ACM_Contest.cpp
    This program get the info from
    the user of the teams, and then
    arrange them counting points and the
    time it took it to solve it
    David Alonso Cantú Martínez
    A00822455
    Version 1.0
*/
#include <iostream>
#include <string.h>
using namespace std;

/*
    Struct Equipo
    This struct gets the team name,
    the number of correct points, and the
    time
*/


struct Equipo
{
    string sTeamName;
    int iACC = 0;
    int iTime = 0;
};

/*
    Struct Correctas
    This struct gets the team name,
    the char of the correct problem, and the
    time
*/


struct Correctas
{
    string sTeamName;
    int iTime = 0;
    char cCorrecta;
};

/*
    Struct Incorrectas
    This struct gets the team name, and
    a char of the incorrect problem
*/

struct Incorrectas
{
    string sTeamName;
    char cInorrecta;
};

int main()
{
    int iNumberOfTeams; //Used to save the number of teams in the contest
    int iNumberOfProblems; //Used to save the number of problems in the contest
    int iNumberOfSolutions; //Used to save the number of solutions sent
    Equipo Eq[20]; //Array to save the teams
    struct Correctas *Corr; //Array to save the correct problems sent
    struct Incorrectas *Incorr; //Array to save the incorrect problem sents
    int iCountW = 0; //Counter of Wrong answers
    int iCountA = 0; //Counter of Correct answers
    string sTemporal; //Temporal
    char cProblemaTemporal; //Temporal
    char cResolucionTemporal; //Temporal
    int iTimeTemp; //Temporal
    int iTemp; //Temporal


    //cout << "Enter the Number of Teams: ";
    cin >> iNumberOfTeams;
    //cout << "Enter the Number of Problems: ";
    cin >> iNumberOfProblems;

    for(int i = 0; i < iNumberOfTeams; i++)
    {
        //cout << "Enter the Team Names: "
        cin >> Eq[i].sTeamName;
    }

    //cout << "Give me the number of solutions sent: ";
    cin >> iNumberOfSolutions;
    Corr = new struct Correctas[iNumberOfSolutions];
    Incorr = new struct Incorrectas[iNumberOfSolutions];

    for(int i = 0; i < iNumberOfSolutions; i++)
    {
        cin >> sTemporal;
        cin >> cProblemaTemporal;
        cin >> iTimeTemp;
        cin >> cResolucionTemporal;

        if(cResolucionTemporal == 'A')
        {
            Corr[iCountA].sTeamName = sTemporal;
            Corr[iCountA].cCorrecta = cProblemaTemporal;
            Corr[iCountA].iTime = iTimeTemp;
            iCountA++; //Counting the Correct Ones
        }

        else
        {
            Incorr[iCountW].sTeamName = sTemporal;
            Incorr[iCountW].cInorrecta = cProblemaTemporal;
            iCountW++; //Counting the wrong ones
        }
    }

    /*
        Nested loop used to check if one team sent a correct
        answer after an incorrect one,and if it happened
        sum the +20 of penalization
    */

    for(int i = 0; i<iCountA; i++)
    {

        for(int j = 0; j<iCountW; j++)
        {

            if(Corr[i].sTeamName == Incorr[j].sTeamName && Corr[i].cCorrecta == Incorr[j].cInorrecta)
            {

                Corr[i].iTime +=20;
            }
        }
    }

    for(int i = 0; i<iCountA; i++)
    {

        for(int j = 0; j<iNumberOfTeams; j++)
        {

            if(Eq[j].sTeamName == Corr[i].sTeamName)
            {

                Eq[j].iTime += Corr[i].iTime;
                Eq[j].iACC += 1;
            }
        }
    }

   struct Equipo TeamTemp; //Temporal
   for(int i = 0; i<iNumberOfTeams; i++)
   {
       for(int j=1; j<iNumberOfTeams; j++)
       {
           if(Eq[j-1].iACC < Eq[j].iACC ||(Eq[j-1].iACC == Eq[j].iACC && Eq[j-1].iTime > Eq[j].iTime ))
           {

               TeamTemp = Eq[j];
               Eq[j] = Eq[j-1];
               Eq[j-1] = TeamTemp;
           }
       }
   }


    for(int i=0; i < iNumberOfTeams; i++)
    {
        cout << i+1 << " " << "-" << " ";
        cout << Eq[i].sTeamName << " ";
        cout << Eq[i].iACC << " ";
        if(Eq[i].iTime == 0)
        {
            cout << "-";
        }
        else
        {
            cout << Eq[i].iTime;
        }
        cout << endl;
    }

    return 0;
}
