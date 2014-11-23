#include <iostream>
#include <cmath>
#include <algorithm>
#define ull unsigned long long
using namespace std;
bool is(ull n)
{
    if(n == 2 || n == 3) return 1;
    if(n < 2) return 0;
    for(ull i = 3; i <= sqrt(n); i+=2) if(!(n%i)) return 0;
    return 1;
}
ull a[10005];
int main()
{
    ull k, n;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    n = a[n-k]-a[k-1];
    if(is(n))
    	cout << "YES\n";
    else
        cout << "NO\n";
    cout << n;
	return 0;
}
	