#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105, V = 1005;
int f[V], w, m, j, v;
int main()
{
	cin >> m >> w;
	while(cin >> v >> w)
		for(j = m; j >= v; j--)
			f[j] = max(f[j], f[j-v]+w);
	cout << f[m];
	return 0;
}