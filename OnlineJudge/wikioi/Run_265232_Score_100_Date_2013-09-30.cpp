#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 35,
		  MAXV = 20005;
int f[MAXV] = {0}, w[MAXN] = {0}, v, n;
int main()
{
	cin >> v >> n;
	for(int i = 0; i < n; i++)
		cin >> w[i];
	for(int i = 0; i < n; i++)
		for(int j = v; j >= 1; j--)
			if(j-w[i] >= 0) f[j]=max(f[j], f[j-w[i]]+w[i]);
	cout << v-f[v];
	return 0;
}

