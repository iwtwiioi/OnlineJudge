#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool is(int n)
{
    if(n == 2 || n == 3) return 1;
    if(n < 2) return 0;
    for(int i = 3; i <= sqrt(n); i+=2) if(!(n%i)) return 0;
    return 1;
}
int a[10005];
int main()
{
    int k, n;
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
	