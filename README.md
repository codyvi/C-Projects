/*
    SpinTheMatrix.cpp
    This program spins a
    matrix of four columns and
    four rows clockwise the number
    of times the user gives.
    David Alonso Cantú Martínez
    A00822455
    Version 1.0
*/


/*
1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 15
*/

#include <iostream>
#include <math.h>

using namespace std;

//Constants
    const int ROWS = 4;
    const int COLS = 4;


/*
    GetValues
    Void used to get the amount of spins
    from the user and the numbers of the matrix
    parameters:
    Spins: Integer to store the number of Spins
    Numbers: Matrix to store the numbers that the user gives
    returns:
    nothing
*/

void GetValues(int &Spins, int Numbers[ROWS][COLS])
{
    //cout << "Give me the number of spins (between -10,000 and 10,000): ";
    cin >> Spins;

    if(Spins <= -10000 || Spins >= 10000)
    {
        //cout << "Give me another number of spins: ";
        cin >> Spins;
    }


    for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                //cout <<"Give me a number: ";
                cin >> Numbers[i][j];
            }
        }

}

void PrintValues(int Spins, int Numbers[ROWS][COLS])
{
    int Matrix2[ROWS][COLS];


    int Spins2 = 0;

    //cout << "Number of Spins: " << Spins << endl;

    Spins2 = Spins%4;

    //cout << endl;

    if(Spins2 < 0)
    {
        Spins2 += 4;
    }

        for (int r = 0; r < Spins2; r++)
        {
            for (int i = 0, y = 3; i < ROWS; i++, y--)
                {
                    for (int x = 0, z = 0; x < COLS; x++, z++)
                    {
                        Matrix2[z][y] = Numbers[i][x];
                    }
                }

            for (int i = 0; i < ROWS; i++)
                {
                    for(int j = 0; j < COLS; j++)
                    {
                        Numbers[i][j] = Matrix2[i][j];
                    }
                }
        }

        for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    cout << Numbers[i][j];
                    if (j <3)
                    {
                        cout << " ";
                    }
            }
            cout << endl;
        }

}



int main()
{
    int Spins;


    int Numbers[ROWS][COLS];

    Spins = 0;

    GetValues(Spins, Numbers);

    PrintValues(Spins, Numbers);
}
