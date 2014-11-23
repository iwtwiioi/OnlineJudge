#include <iostream>
#include <algorithm>
using namespace std;
int d[20], s = 0, n, k, c[11], f[11][11]; //c[i]代表数值为i的有多少中变的方法
unsigned long long ans = 1;
int main()
{
    cin >> n >> k;
	int i, j, u, v;
	for(i = 1; i <= k; i++)
	{
		cin >> u >> v;
		f[u][v]++; 
        //cout << "f["<<u<<"]["<<v<<"]++\n";
	}
	for(k = 1; k <= 10; k++)
		for(i = 1; i <= 10; i++)
			for(j = 1; j <= 10; j++)
        		if(i!=j && f[i][k] && f[k][j])
					f[i][j] = 1;
	for(i = 1; i <= 10; i++)
		for(j = 1; j <= 10; j++)
			if(i!=j && f[i][j])
				c[i]++;
    //cout << c[2] << "  " << c[3] << endl;
	while(n)
	{
		k = n%10;
		ans *= (c[k]+1);
		n /= 10;
	}
    cout << ans;
    return 0;
}