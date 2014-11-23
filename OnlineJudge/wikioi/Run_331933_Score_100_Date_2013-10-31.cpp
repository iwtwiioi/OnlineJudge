#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long ans = 0;
int a, b;
int main()
{
	int i, j, ok;
	cin >> a >> b;
    int t = min(a, b); b = max(a, b); a = t;
	for(i = a+1; i < b; i++)
    {
        ok = 1;
        for(j = 2; j <= sqrt(i); j++) if(i%j == 0) {ok = 0; break;}
    	if(ok) ans += i;
    }
	cout << ans;
	return 0;
}