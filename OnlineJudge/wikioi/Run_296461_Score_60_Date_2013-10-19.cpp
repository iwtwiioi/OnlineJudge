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
	bool ok = 0;
	for(i = 1; i <= n; i++)
	{
		ok = 0;
		if(pay[i] <= p) ok = 1;
		for(j = i+1; j <= n; j++)
		{
			if(pay[j] <= p) ok = 1;
			if(color[i] == color[j] && ok)
				ans++;
		}
	}
	fout << ans;
	return 0;
}
