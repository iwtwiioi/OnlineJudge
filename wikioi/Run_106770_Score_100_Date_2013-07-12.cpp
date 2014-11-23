#include <iostream>
using namespace std;
int ans[100][100];
bool al[100][100];
int main()
{
    int n;
    cin>>n;
    int x=n-1,y=n-1;
    ans[x][y] = n*n;
    al[x][y] = 1;
    int i = ans[x][y] - 1;
    while(i > 0)
    {
        while(y-1 > -1 && !ans[x][y - 1]){ans[x][--y] = i--; al[x][y] = 1;}
        while(x-1 > -1 && !ans[x - 1][y]){ans[--x][y] = i--; al[x][y] = 1;}
        while(y+1 < n && !ans[x][y + 1]){ans[x][++y] = i--; al[x][y] = 1;}
        while(x+1 < n && !ans[x + 1][y]){ans[++x][y] = i--; al[x][y] = 1;}
    }
    for(int j = 0; j < n; j++)
    {
        cout<<ans[j][0];
        for(int k = 1; k < n; k++)
        	cout<<" "<<ans[j][k];
        cout<<endl;
    }
    int max = 0;
    for(int p = 0; p < n; p++)
        max += ans[p][p];
    for(int x1 = 0, y1 = n-1; y1 > -1; x1++, y1--)
        max += ans[x1][y1];
    max -= ans[n/2][n/2];
    cout<<max<<endl;
    return 0;
}