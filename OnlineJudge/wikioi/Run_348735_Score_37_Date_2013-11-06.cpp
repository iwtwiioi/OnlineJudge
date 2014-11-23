#include <iostream>
#include <cmath>
#include <algorithm>
#define ull unsigned long long
using namespace std;
bool is(ull n)
{
    if(n == 2 || n == 3) return 1;
    if(n < 2) return 0;
    for(ull i = 3; i <= sqrt(n); i += 2) if(!(n%i)) return 0;
    return 1;
}
ull a[100000];
int main()
{
    ull k, n, t;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    t = a[n-k]-a[k-1];
    if(!is(t) || k > (n>>1))
    	cout << "NO\n";
    else
        cout << "YES\n";
    cout << t;
	return 0;
}
	