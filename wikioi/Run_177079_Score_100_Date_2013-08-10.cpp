#include <iostream>
using namespace std;long a[70][70]={0},n,m,g,h,r,t,x,y;int main(){cin>>n>>m>>g>>r>>h>>t;r+=2;t+=2;a[h][t]=1;for(x=h-1;x>g;x--)for(y=3;y<m+3;y++)a[x][y]=a[x+1][y-2]+a[x+1][y+2]+a[x+2][y-1]+a[x+2][y+1];y=r;cout<<(a[g][r]=a[x+1][y-2]+a[x+1][y+2]+a[x+2][y-1]+a[x+2][y+1]);return 0;}
