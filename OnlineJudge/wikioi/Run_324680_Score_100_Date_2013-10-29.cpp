#include <iostream>

using namespace std;
const int MAXV = 10010;
int n, m, p, w, h, f[MAXV];
int main()
{
	cin >> m >> n;
	int i, j, k;
	for(i = 1; i <= n; i++)
	{
		cin >> p >> w >> h;
		for(k = 1; k <= h; k++)
			for(j = m; j >= p; j--)
				f[j] = max(f[j], f[j-p]+w);
	}
	cout << f[m];
	return 0;
}
