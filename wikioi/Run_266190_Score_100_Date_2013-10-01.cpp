#include <iostream>
#include <algorithm>
using namespace std;
const int MAXE = 105;
struct ed
{
	int l, r;
	bool operator<(const ed& a) const {return l < a.l;}
}edge[MAXE];
int n, i, j, f[MAXE], ans=0;
int main()
{
	cin >> n;
	int a, b;
	for(i = 1; i <= n; i++)
	{
		cin >> a >> b;
		edge[i].l = min(a, b);
		edge[i].r = max(a, b);
        f[i]=1;
	}
	sort(edge+1, edge+n+1);
	for(i = 2; i <= n; i++)
		for(j = 1; j < i; j++)
			if(edge[i].l >= edge[j].r)
				if(f[i] < f[j] + 1)
					f[i] = f[j] + 1;
    for(i = 1; i <= n; i++)
        if(ans < f[i]) ans = f[i];
	cout << ans << endl;
	return 0;
}

