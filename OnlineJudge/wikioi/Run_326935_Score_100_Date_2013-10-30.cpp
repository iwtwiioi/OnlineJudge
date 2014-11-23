#include <iostream>
#include <algorithm>
using namespace std;
const int MAXV = 10005;
int N, V, f[MAXV];
int w1, w2, v1, v2;

int main()
{
	cin >> N >> V;
	int i, j;
	for(i = 1; i <= N; i++)
	{
		cin >> v1 >> w1 >> v2 >> w2;
		for(j = V; j >= min(v1, v2); j--)
		{
			if(j-v1 >= 0) f[j] = max(f[j], f[j-v1]+w1);
			if(j-v2 >= 0) f[j] = max(f[j], f[j-v2]+w2);
		}

	}
	cout << f[V];
	return 0;
}
