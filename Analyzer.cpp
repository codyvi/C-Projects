/*
	Analyzer.cpp
    This program has eight different functions
    that are used for getting things from a file
    David Alonso Cantu
	A00822455
	18/11/2017
	Version 1.0
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits.h>

using namespace std;

/*
	GetLinee 
    This function gets the lines that are in the
    file and store it on a counter
    parameters: 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void GetLinee(string sMyfile, string sLine)
{
    //Declaring variables
 	int iCounter = 0;
    ifstream fMyfile (sMyfile.c_str());
	//opening the file
    if (fMyfile.is_open())
    {
        while ( getline(fMyfile,sLine) )
        {
         	//counting lines
            iCounter++;
        }
		//dipslaying the number of lines
        cout << iCounter << endl;

        fMyfile.close();
    }

}

/*
	Blankspace 
    This function gets the number of blankspaces that are in the
    file and store it on a counter
    parameters: 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void Blankspace(string sMyfile, string sLine)
{
 	//declaring variables 
    int iCounter = 0;
 	//oppening the file
    ifstream fMyfile (sMyfile.c_str());
    char c;
    if (fMyfile.is_open())
    {
        while(!fMyfile.eof())
        {
            fMyfile.get(c);

            if(c == ' ')
            {
             	//counting spaces
                iCounter++;
            }

        }
     
     	//displaying the number of spaces
        cout<< iCounter << endl;

        fMyfile.close();
    }
}

/*
	Vowels
    This function gets the number of vowels that are in the
    file and store it on a counter
    parameters: 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void Vowels(string sMyfile, string sLine)
{
	//declaring variables
    char c;
    int iCounter = 0;
 	//openning the file
    ifstream fMyfile (sMyfile.c_str());
    if (fMyfile.is_open())
    {

        while(fMyfile.get(c))
        {
            if (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' ||c == 'A' ||c == 'E' ||c== 'I' ||c == 'O' ||c == 'U' )
            {
             	//counting if the character is a vowel
                iCounter++;
            }

        }	
		//displaying the number of vowels
        cout << iCounter << endl;
        fMyfile.close();
    }


}

/*
	Consonants
    This function gets the number of consonants that are in the
    file and store it on a counter
    parameters: 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/


void Consonants(string sMyfile, string sLine)
{
	//declaring variables 
    char c;
    int iCounter = 0;
 	//opening the file
    ifstream fMyfile (sMyfile.c_str());
    if (fMyfile.is_open())
    {

        while(fMyfile.get(c))
        {
            if (c == 'b' || c == 'c' ||c == 'd' ||c == 'f' ||c == 'g' ||c  == 'h' ||c == 'j' ||c == 'k' ||c == 'l' ||c == 'm' || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' ||c == 'x' || c== 'y' ||c == 'z')
            {
             	//counting if the character is a consonant
                iCounter++;
            }

            else if (c == 'B' || c == 'C' ||c == 'D' ||c == 'F' ||c == 'G' ||c  == 'H' ||c == 'J' ||c == 'K' ||c == 'L' ||c == 'M' || c == 'N' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'V' || c == 'W' ||c == 'X' || c== 'Y' ||c == 'Z')
            {
             	//counting if the character is a consonant
                iCounter++;
            }
        }

		//diplaying the number of consonants
        cout << iCounter << endl;
        fMyfile.close();
    }


}

/*
	Longest
    This function gets the longest word in the file
    parameters: 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void Longest (string sFileName, string sLine)
{
 	//opem file
    ifstream fFile (sFileName.c_str());
    int iBig = INT_MIN;
    int iCounter = 0;

 	if (fFile.is_open())
    {
     	while (getline (fFile, sLine))
        {
         	for (int i=0; i<sLine.length(); i++)
            {
                if (sLine.at(i) >= 'a' && sLine.at(i) <= 'z' || sLine.at(i) >= 'A' && sLine.at(i) <= 'Z')
                {
                   	iCounter++;

					if (i == sLine.length()-1)
                    {
                    	if (iCounter >= iBig)
                        {
                        	iBig = iCounter;
                        }
                    	iCounter = 0;
                    }
                }

                else
                {
                    if (iCounter >= iBig)
                    {
                        iBig = iCounter;
                    }
                    iCounter=0;
                }
            }
        }
        cout << iBig << endl;
     	fFile.close();
    }
}

/*
	Shortest
    This function gets the smallest word in
    the file 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void Shortest(string sMyfile, string sLine)
{
	//openning the file
    ifstream fMyfile (sMyfile.c_str());
    if (fMyfile.is_open())
    {

        string word;
        string shortest;
        string aux;
        int iAnt=0;
        int iMenor = INT_MAX;

        while( !fMyfile.eof())
        {
            getline(fMyfile,aux);

            for (int i =0; i < aux.length(); i++)
            {

                if(aux[i]!=' ')
                {
                    iAnt++;
                    if(i==aux.length()-1)
                    {

                        if (iMenor >iAnt)
                        {
                           iMenor = iAnt;
                        }
                        iAnt =0;
                    }

                }
                else
                {

                    if (iMenor > iAnt)
                    {
                        iMenor = iAnt;
                    }

                    iAnt =0;
                }

            }
        }
        cout << iMenor << endl;

        fMyfile.close();

    }


}

/*
	Word
    This function counts how many times a word
    is found in the file 
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void Word (string sMyfile, string sLine)
{
	//oppening the file 
    ifstream fMyfile (sMyfile.c_str());
	if( fMyfile.is_open() )
	{
        string word;
		cin >> word ;

		int iCounter = 0 ;
		string candidate ;
		while( fMyfile >> candidate ) // for each candidate word read from the file
		{
			if( word == candidate )
            {
             	//counting the times the word is found
                ++iCounter ;
            }
		}
	
    //displaying the word
	cout <<  iCounter << endl;
	fMyfile.close();
	}


}

/*
	Paragraph
    This function gets the number of paragraphs that are in a file
    sMyfile. The variable used to get the file name from the user
    sLine: It is used to get the lines
    retuns:
	none
*/

void Paragraphs (string sMyfile, string sLine)
{
 	//opening the file 
    int iCounter = 0;
    int parg = 1;
    ifstream fMyfile (sMyfile.c_str());
    if (fMyfile.is_open())
    {
        while(getline(fMyfile, sLine))
        {
            if (sLine.length() == 0)
            {	
             	//counting blank lines
                iCounter++;
            }
            else if (iCounter > 0)
            {
             	//counting the paragraphs
                parg++;
                iCounter = 0;
            }
        }
     	//displaying the paragraphs
        cout<< parg << endl;
        fMyfile.close();
    }


}

/*
    Main It is in charge of all
    parameters:
    none
    returns:
    an integer value with the error number (0 = none)
*/



int main ()
{
    //Declaring the variables
    string sMyfile;
    getline (cin, sMyfile);
    ifstream fMyfile (sMyfile.c_str());
    string sLine;
    char cOpt;

    if (fMyfile.is_open())
    {
        cin >> cOpt;
        if (cOpt == '1')
        {
            GetLinee(sMyfile, sLine);
        }

        else if (cOpt == '2')
        {
            Blankspace(sMyfile, sLine);
        }

        else if (cOpt == '3')
        {
            Vowels(sMyfile, sLine);
        }

        else if (cOpt == '4')
        {
            Consonants(sMyfile, sLine);
        }

        else if (cOpt == '5')
        {
            Shortest(sMyfile, sLine);
        }

        else if (cOpt == '6')
        {
            Longest(sMyfile, sLine);
        }

        else if (cOpt == '7')
        {
            Word(sMyfile, sLine);
        }

        else if (cOpt == '8')
        {
            Paragraphs(sMyfile, sLine);
        }
    }

    else
    {
        //do nothing
    }

    return 0;
}
