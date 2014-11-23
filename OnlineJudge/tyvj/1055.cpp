#include <iostream>
#include <algorithm>
using namespace std;
 
const int MAXN = 500;
const int INF = 1000000000;
int w[MAXN], n, f[MAXN][MAXN], sum[MAXN];
int i, j, k;
 
int main()
{
    cin >> n;
    for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) f[i][j] = INF;
    for(i = 1; i <= n; i++) {cin >> w[i]; f[i][i] = 0; sum[i] += sum[i-1]+w[i];}
    for(j = 1; j <= n; j++)
        for(i = j; i > 0; i--)
            for(k = i; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
    cout << f[1][n] << endl;
    return 0;
}
