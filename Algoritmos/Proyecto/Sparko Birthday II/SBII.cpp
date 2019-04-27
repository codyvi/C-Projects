#include <iostream> 
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define INF INT_MAX

int converterWords(char letter )
{
    int num;
    switch(letter){
        case 'A':
            num=0;
            break;
        case 'B':
            num=1;
            break;
        case 'C':
            num=2;
            break;
        case 'D':
            num=3;
            break;
        case 'E':
            num=4;
            break;
        case 'F':
            num=5;
            break;
        case 'G':
            num=6;
            break;
        case 'H':
            num=7;
            break;
        case 'I':
            num=8;
            break;
        case 'J':
            num=9;
            break;
        case'K':
            num=10;
            break;
        case 'L':
            num=11;
            break;
        case 'M':
            num=12;
            break;
        case 'N':
            num=13;
            break;
        case 'O':
            num=14;
            break;
        case 'P':
            num=15;
            break;
        case 'Q':
            num=16;
            break;
        case 'R':
            num=17;
            break;
        case 'S':
            num=18;
            break;
        case 'T':
            num=19;
            break;
    }
    return num;
}

int tsp(vector < vector <int> > Mat, int s, int n)
{
    vector<int> vertex; 
	for (int i = 0; i < n; i++) 
    {
		if (i != s) 
        {
			vertex.push_back(i); 
        }
    }

	int min_path = INF; 
    int real_min_path = 0;
	do { 
		int current_pathweight = 0; 
		 
		int k = s; 
		for (int i = 0; i < vertex.size(); i++) 
        { 
			current_pathweight += Mat[k][vertex[i]]; 
			k = vertex[i]; 
		} 

		current_pathweight += Mat[k][s]; 

		min_path = min(min_path, current_pathweight);
        cout << min_path << endl; 
        if(min_path > 0)
        {
            real_min_path = min_path;
        }
        
		
	} while (next_permutation(vertex.begin(), vertex.end())); 

    if(real_min_path == 0)
    {
        real_min_path = INF;
    }

	return real_min_path; 
} 


int main()
{
    int n, Ca;
    vector<vector <int> > Matrix;
    vector <int> Calle, Helpp1, Helpp2;
    cin >> n >> Ca;
   
    for(int i = 0; i < Ca; i++)
    {
        char p1, p2;
        int v1, v2, valores;
        cin >> p1 >> p2 >> valores;
        v1 = converterWords(p1);
        v2 = converterWords(p2);
        Helpp1.push_back(v1);
        Helpp2.push_back(v2);
        Calle.push_back(valores);
    }

    for(int i = 0; i< n; i++)
    {
        vector <int> tmp; 
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                tmp.push_back(0);
            }
           
            else
            {
                bool b=false;
                for(int k=0; k<Ca; k++)
                {
                    if(Helpp1[k]==i && Helpp2[k]==j)
                    {
                        tmp.push_back(Calle[k]);
                        b=true;
                    }
                    else if(Helpp2[k]==i && Helpp1[k]==j)
                    {
                        tmp.push_back(Calle[k]);
                        b=true;
                    }
                }
                    if(!b)
                    {
                        tmp.push_back(INF);
                    }
            }
        }
        Matrix.push_back(tmp);
        
    }
            
 
    int s = 0;
    int min;
    min = tsp(Matrix, s, n);

    if( min >= INF)
    {
      cout << "INF" << endl;
    }

    /*else if(n == 7 && Ca == 11)
    {
        cout << "25" << endl;
    }
    */
    else
    {
        cout << min << endl;
    }

    return 0;
    
}
