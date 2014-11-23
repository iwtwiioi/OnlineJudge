#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,ed;
int mp[16][16],f[16][1<<16];
int main()
{
    memset(f,127/3,sizeof(f));
    scanf("%d",&n);ed=(1<<(n+1))-1;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            scanf("%d",&mp[i][j]);
    for(int k=0;k<=n;k++)
        for(int i=0;i<=n;i++)
           for(int j=0;j<=n;j++)
               mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    f[0][0]=0;
    for(int i=0;i<=ed;i++)
       for(int now=0;now<=n;now++)
           for(int from=0;from<=n;from++)
           {
			   if((i|(1<<now))!=i)continue;
               f[now][i]=min(f[now][i],f[from][i-(1<<now)]+mp[from][now]);
               f[now][i]=min(f[now][i],f[from][i]+mp[from][now]);
		   }
	printf("%d\n",f[0][ed]);
    return 0;
}