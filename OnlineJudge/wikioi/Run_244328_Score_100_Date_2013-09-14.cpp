#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct self{int x,y;long long c;};
self s[1000001];
int a,b,m,n;
long long z=0;
int f[1000001];
int use[1000001];

int find(int i)
{
return f[i]==i?i:f[i]=find(f[i]);
} 

int cmp(self a1,self a2)
{
return a1.c<a2.c;
}

long long kruskal()
{
long long z=0;
int y=0;
for(int k=1;k<=n;k++)
if(use[k])
{
int l=find(s[k].x);
int r=find(s[k].y);
if(l!=r)
{
f[l]=r;
z+=s[k].c;
y++;
if(y==m-1)return z;
}

} 
return z;
}

int main()
{
scanf("%d %d",&m,&n);
for(a=1;a<=n;a++)
{
f[a]=a;
scanf("%d %d %d",&s[a].x,&s[a].y,&s[a].c);
use[a]=1;
}
sort(s+1,s+n+1,cmp);

if(n<m-1)
{
printf("-1\n");
return 0;
}

z=kruskal();
printf("%lld\n",z);
return 0;
}