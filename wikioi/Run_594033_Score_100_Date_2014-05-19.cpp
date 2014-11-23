#include <cstdio>
#define F(i,n) for(int i=0;i<n;++i)
#define W F(i,n)F(j,n)
int a[102][102],t,n,i,j;
int main(){scanf("%d",&n);W scanf("%d",&a[i][j]);W{scanf("%d",&t);a[i][j]+=t;}F(i,n){F(j,n) printf("%d ",a[i][j]);printf("\n");} return 0;}
