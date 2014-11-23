#include <iostream>
#include <cmath>
using namespace std;
bool prime[5050];
int m, ans = 0;
int main()
{
    cin >> m;
    int i, j, t;
    for(i = 2; i <= m>>1; i++)
    {
        j = 2; t = i<<1;
        while(t<=m) 
            prime[t] = 1, t = i*(++j);
    }
    for(i = 4; i <= m; i++)
        if(prime[i])
        	ans += i;
    cout << ans;
    return 0;
}
    