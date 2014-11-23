#include <iostream>
using namespace std;
int n,m,X,Y;
int ans = 0;
void dfs(int i, int j)
{
    if(i == 0 && j == 0){ans++;return;}
    if(i<0||j<0||(i==X&&j==Y)||
      (i==X-2&&(j==Y-2||j==Y-1||j==Y+1))||
      (i==X+1&&(j==Y-2||j==Y+1||j==Y+2))|| 
      (i==X-1&&(j==Y-2||j==Y+2))||
      (i==X+2&&(j==Y-1||j==Y+1)))
        return;
    dfs(i,j-1);dfs(i-1,j);
}
int main()
{
    cin>>n>>m>>X>>Y;
    dfs(n,m);
    cout<<ans<<endl;
    return 0;
}