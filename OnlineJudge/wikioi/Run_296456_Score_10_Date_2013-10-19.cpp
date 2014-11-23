#include <iostream>
#define fin cin
#define fout cout
using namespace std;
const int MAXN = 200010;
short pay[MAXN], color[MAXN];
unsigned int dp[MAXN], ans = 0;
int n, k, p, i, j;
int main()
{
	fin >> n >> k >> p;
	for(i = 1; i <= n; i++)
		fin >> color[i] >> pay[i];
	int ok = 0, pl;
	for(i = n-1; i > 0; i--)
	{
		ok = 0;
		pl = -1;
		if(pay[i] <= p) ok = 1;
		for(j = i+1; j <= n; j++)
		{
			if(pay[j] <= p) ok = 1;
			if(color[j] == color[i])
			{
				dp[i] = dp[j] + 1;
				break;
			}
		}
		if(!ok)
		{
			for(; j <= n; j++)
				if(color[j] == color[i] && pay[j] <= p)
				{
					pl = j;
					break;
				}
		}
		if(ok) ans += dp[i];
		else if(pl != -1) ans += dp[pl]+1;
	}
	fout << ans;
	return 0;
}
