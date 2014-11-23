#include <iostream>
#include <algorithm>
using namespace std;
struct z
{
	int l,r;
}edge[105];
bool cmp(const z &a, const z &b){return a.r < b.r;}
int n, i, a, b, ans=0, j, v[105]={0};
int main()
{
	cin>>n;
	for(i = 0; i < n; i++){cin>>a>>b; edge[i].l=min(a,b); edge[i].r=max(a,b);}
	sort(edge, edge+n, cmp);
	for(i = 0; i < n; i++)
		if(!v[i])
		{
			for(j = i + 1; j < n; j++)
				if(!v[j] && edge[j].l < edge[i].r)
				{
					v[j]=1;
					ans++;
				}
		}
	cout<<n-ans<<endl;
      return 0;
}

