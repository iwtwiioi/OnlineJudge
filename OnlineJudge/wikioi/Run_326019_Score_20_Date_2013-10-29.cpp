#include <iostream>
#include <algorithm>
using namespace std;
const int MAXE = 1000005;
struct ed
{
	long long l, r, c;
	bool operator<(const ed &a)const {return l < a.l;}
}edge[MAXE];
long long n, f[MAXE], ans = -1;
int i, j;

int main()
{
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> edge[i].l >> edge[i].r >> edge[i].c;
	sort(edge, edge+n);
	for(i = 0; i < n; i++) f[i] = edge[i].c;
	for(i = 1; i < n; i++)
		for(j = 0; j < i; j++)
			if(edge[i].l >= edge[j].r)
				f[i] = max(f[i], f[j]+edge[i].c);
	for(i = 0; i < n; i++) if(ans < f[i]) ans = f[i];
	cout << ans << endl;

	return 0;
}