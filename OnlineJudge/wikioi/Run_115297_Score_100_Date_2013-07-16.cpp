#include <iostream>
using namespace std;
const int N=15,M=15;
int n,m,X,Y;
int f[N+2][M+2]={0};
void dfs(int i, int j)
{
    if((i==X&&j==Y)||
       (i==X-2&&(j==Y-2||j==Y-1||j==Y+1))||
       (i==X+1&&(j==Y-2||j==Y+1||j==Y+2))|| 
       (i==X-1&&(j==Y-2||j==Y+2))||
       (i==X+2&&(j==Y-1||j==Y+1)))
        return;
    if(j-1>0 && !f[i][j-1]){dfs(i,j-1);}
    if(i-1>0 && !f[i-1][j]){dfs(i-1,j);}
    f[i][j] = f[i][j-1] + f[i-1][j];
}
int main()
{
    f[1][1] = 1;
    cin>>n>>m>>X>>Y;
    X++;Y++;
    dfs(n+1,m+1);
    cout<<f[n+1][m+1]<<endl;
    return 0;
}