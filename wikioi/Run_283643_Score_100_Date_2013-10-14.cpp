#include <iostream>
using namespace std;
int f[201][7];
int main()
{
    int n, p, i, j;
    cin >> n >> p;
    f[0][0] = 1;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= p; j++)
        	if(i >= j) f[i][j] = f[i-j][j] + f[i-1][j-1];
    cout << f[n][p] << endl;
    return 0;
}
