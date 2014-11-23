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
		for(j = i+1; j <= n; j++)
		{
			if(color[j] == color[i])
			{
				dp[i] = dp[j] + 1;
				break;
			}
		}
        if(pay[i] <= p) ans += dp[i];
        else 
        {
            for(j = i+1; j <= n; j++)
			{
                if(pay[j] <= p) ok = 1;
                if(color[j] == color[i])
                    break;
            }
            if(j == n && ok) ans += 1;
        	else if(j != n)
                ans += dp[j]+1;
        }
	}
	fout << ans;
	return 0;
}