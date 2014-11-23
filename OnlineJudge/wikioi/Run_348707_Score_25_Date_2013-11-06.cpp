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
    ull k, n;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
   	int maxi = n-1, mini = 0;
    for(int i = 2; i <= k;)
        if(a[n-i] != a[maxi])
            maxi = n-i, i+=1;
    for(int i = 2; i <= k;)
        if(a[i-1] != a[mini])
            mini = i-1, i+=1;
    n = a[maxi]-a[mini];
    if(is(n))
    	cout << "YES\n";
    else
        cout << "NO\n";
    cout << n;
	return 0;
}
	