#include <iostream>
using namespace std;
const int MAXN = 200010;
short pay, color;
unsigned int dp[52][MAXN], ans = 0, kz[MAXN]; //dp[i][j]是1~j客栈中i颜色客栈数量 kz[i]表示i最近的符合客栈
int n, k, p, i, j;
int main()
{
	cin >> n >> k >> p;
	for(i = 1; i <= n; i++)
    {
		cin >> color >> pay;
        for(j = 0; j < k; j++)
            dp[j][i] = dp[j][i-1] + (color == j); // 更新颜色相同或不相同的d[j][i]值，不同就为原来那个，同就为d[j][i-1]+1
        if(pay <= p) // 本客栈符合的  更新kz[i]为符合i客栈 因为dp[color][i]中包含的是全部（包含本身）所以要-1
            ans += dp[color][kz[i] = i] - 1;
        else //不符合，就用kz[i-1]即上一个满足的那个客栈，因为不包含自己，所以不用-1，还要更新kz[i]自己
            ans += dp[color][kz[i] = kz[i-1]];
    }
	cout << ans;
	return 0;
}