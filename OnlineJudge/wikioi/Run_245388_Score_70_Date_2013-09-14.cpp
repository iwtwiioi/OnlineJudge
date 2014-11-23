#include <iostream>
#include <algorithm>
using namespace std;
struct z
{
	int l,r;
}node[105];
bool cmp(const z &a, const z &b){return a.l < b.l;}
int n, i, a, b, ans=0, j;
int main()
{
	cin>>n;
	for(i = 0; i < n; i++){cin>>a>>b; node[i].l=min(a,b); node[i].r=max(a,b);}
	sort(node, node+n, cmp);
	for(i = 0, j = 1; j < n; j++)
	{
		if((node[i].r < node[j].r && node[i].r > node[j].l) || (node[i].l == node[j].l && node[i].r == node[j].r)) ans++;
		else if(node[i].l < node[j].r && node[i].r > node[j].r){i=j;ans++;}
		else i = j;
	}
	cout<<n-ans<<endl;
      return 0;
}

