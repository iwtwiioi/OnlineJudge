#include <iostream>
#include <algorithm>
using namespace std;
struct z
{
      int l,r;
}node[105];
bool cmp(const z &a, const z &b){return a.l < b.l;}
int n, i, a, b, ans=0;
int main()
{
      cin>>n;
      for(i = 0; i < n; i++){cin>>a>>b; node[i].l=min(a,b); node[i].r=max(a,b);}
      sort(node, node+n, cmp);
	for(i = 0; i < n; i++)
	{
		if(node[i].l < node[i+1].l && node[i].r < node[i+1].r){ans++;i++;}
		else if(node[i].l < node[i+1].l && node[i].r > node[i+1].r){node[i].r=node[i+1].r;ans++;}
	}
	cout<<n-ans<<endl;
      return 0;
}

