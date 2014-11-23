#include <iostream>
#include <string>
#include <cstring>
#define F(i,n,m) for(i=(n);i<(m);i++)
#define M(a) memset(a,0,sizeof(a))
using namespace std;string r,d[6],t;int a[210][210],f[210][40],k,s,n,p,m,y,i,j,l;int main(){cin>>n;while(n--){cin>>p>>k;r="";while(p--){cin>>t;r+=t;}m=r.size();cin>>s;F(i,0,s)cin>>d[i];M(a);for(j=m-1;j>=0;j--)for(i=j;i>=0;i--){F(l,0,s){y=0;if(r.find(d[l],i)==i&&d[l].size()<j-i)y=1;if(y)break;}if(y)a[i][j]=a[i+1][j]+1;else a[i][j]=a[i+1][j];}M(f);F(i,0,m)f[i][1]=a[0][i];F(l,2,k+1)F(i,l-1,m)F(j,l-2,i)f[i][l]=max(f[i][l],f[j][l-1]+a[j+1][i]);cout<<f[m-1][k];}return 0;}
