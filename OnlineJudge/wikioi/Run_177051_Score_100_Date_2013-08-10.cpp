#include <iostream>
using namespace std;
long a[70][70]={0},n,m,x1,x2,y1,y2,x,y;
int main()
{
	cin>>n>>m>>x1>>y1>>x2>>y2;
    y1+=2;y2+=2;a[x2][y2]=1;
    for(x=x2-1;x>x1;x--)
        for(y=3;y<m+3;y++)
        	a[x][y]=a[x+1][y-2]+a[x+1][y+2]+a[x+2][y-1]+a[x+2][y+1];
    y=y1;
    cout<<(a[x1][y1]=a[x+1][y-2]+a[x+1][y+2]+a[x+2][y-1]+a[x+2][y+1])<<endl;
    return 0;
}
