#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
const int MAXH = 4000;
struct p
{
	int l, r;
	bool operator<(const p &b) const{return l*r < b.r*b.l;}
}peo[MAXN];
int acount[MAXH] = {0};
int bcount[MAXH] = {0};
int tcount[MAXH] = {0};
int ans[MAXH] = {0};
int bn = 0, cn = 0, an = 0;
void time(int o)
{
	memset(tcount, 0, sizeof(tcount));
	int t, i1, tn = -1;
	while(o > 0)
	{
		tn++;
		t = o%10;
		o/=10;
		for(i1 = 0; i1 < cn; i1++)
		{
			tcount[i1+tn] = tcount[i1+tn] + t*acount[i1];
		}
	}
	for(i1 = 0; i1 < cn+tn+1; i1++)
	{
		tcount[i1+1]+=tcount[i1]/10;
		tcount[i1]%=10;
		acount[i1]=tcount[i1];
	}
	if(!acount[cn+tn]) cn+=tn;
	else cn+=tn+1;
}
inline void equal()
{
	for(int i = 0; i < bn; i++)
		ans[i] = bcount[i];
	an = bn;
}

void chu(int o)
{
	memset(bcount, 0, sizeof(bcount));
	int t=0, a;
	for(int i = cn-1; i >= 0; i--)
	{
		a = acount[i] + t*10;
		bcount[i] = a/o;
		t = a - bcount[i]*o;
	}
	bn = cn;
	if(bn!=1)
		while(!bcount[bn-1]) bn--;
}

bool mmax()
{
	if(an < bn) return 0;
	if(an > bn) return 1;
	for(int i = an - 1; i >= 0; i--)
		if(bcount[i] > ans[i]) return 0;
	return 1;
}

int n, a, b, i, j;
//long long ans = -1;
int main()
{
/*
	cin >> a;
	while(a > 0)
	{
		acount[cn++]=a%10;
		a/=10;
	}
	while(cin>>b)
	{
	chu(b);
	for(i = bn-1; i >= 0; i--)
		cout<<bcount[i];
	}
	*/
	cin >> n;
	for(i = 0; i <= n; i++) cin >> peo[i].l >> peo[i].r;
	sort(peo+1, peo+n+1);
	int temp = peo[0].l;
	while(temp > 0)
	{
		acount[cn++]=temp%10;
		temp/=10;
	}

	for(i = 1; i <= n; i++)
	{
		chu(peo[i].r);
		if(!mmax()) equal();
		time(peo[i].l);
	}
	for(i = an-1; i >= 0; i--)
		cout<<ans[i];
	return 0;
}

