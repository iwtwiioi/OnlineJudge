#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long ans = 0;
int a, b, prime[10000], c = 0;
int main()
{
	int i, j, ok;
	cin >> a >> b;
    int t = min(a, b); b = max(a, b); a = t;
    prime[++c] = 2;
	for(i = 3; i <= sqrt(b)+1; i++)
    {
        ok = 1;
        for(j = 2; j <= sqrt(i); j++) if(i%j == 0) {ok = 0; break;}
    	if(ok) prime[++c] = i;
    }
    for(i = 1; i <= c; i++)
        if(a % i == 0) ans += prime[i];
    for(i = 1; i <= c; i++)
        if(b % i == 0) ans += prime[i];
	cout << ans << endl;
	return 0;
}