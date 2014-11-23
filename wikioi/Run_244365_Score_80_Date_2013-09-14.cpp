#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct self
{
    int x,y;
    long long c;
    bool operator <(const self &b) const {return c < b.c;}
}s[100001];
int a,b,m,n;
long long z=0;
int f[100001];
int find(int i){while(f[i]!=i) i=f[i]; return i;} 
long long kruskal()
{
	long long z=0;
	int y=0;
	for(int k=1;k<=n;k++)
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
	}
	sort(s+1,s+n+1);
	z=kruskal();
	printf("%lld\n",z);
	return 0;
}