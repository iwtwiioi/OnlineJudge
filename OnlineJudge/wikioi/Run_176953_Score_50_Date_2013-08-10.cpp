#include <iostream>
using namespace std;
int a[70][70]={0},n,m,x1,x2,y1,y2;
void dfs(int x, int y)
{
    if(x>x2||y>m+2||y<2||a[x][y])return;
    dfs(x+1,y-2);dfs(x+1,y+2);
    dfs(x+2,y-1);dfs(x+2,y+1);
    a[x][y]=a[x+1][y-2]+a[x+1][y+2]+a[x+2][y-1]+a[x+2][y+1];
}
int main()
{
	cin>>n>>m>>x1>>y1>>x2>>y2;
    y1+=1;y2+=1;a[x2][y2]=1;
    dfs(x1,y1);
    cout<<a[x1][y1]<<endl;
    return 0;
}