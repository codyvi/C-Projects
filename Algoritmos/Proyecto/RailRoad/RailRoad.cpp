#include <cstring> 
#include <iostream> 

using namespace std;

const int tammax=1010;

int N,M,check;
int a[tammax],b[tammax],c[2*tammax];
int sol[tammax][tammax];

void DFS(int x, int y, int z)
{
    if(check)
    {
        return;
    }

    if(sol[x][y] != 0)
    {
        return;
    }

    if(z == N+M && z != 0)
    {
        check = 1; 
        return;
    }

    if(x<N && a[x]==c[z])
    {
        DFS(x+1,y,z+1);
    }

    if(y<M && b[y]==c[z])
    {
        DFS(x,y+1,z+1);
    }

    sol[x][y]=1;
}

int main()
{
    while(cin >> N >> M)
    {
        if(N==0 && M==0)
        {
            break;
        }

        for(int i = 0; i <N; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < M; i++)
        {
            cin >> b[i];
        }

        for(int i = 0; i < N+M; i++)
        {
            cin >> c[i]; 
        }
        memset(sol,0,sizeof(sol));
        check = 0;
        DFS(0,0,0);
        if(check)
        {
            cout << "possible" << endl;
        }

        else
        {
            cout << "not possible" << endl;
        }
        
    }

    return 0;
}