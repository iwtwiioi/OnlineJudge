#include <iostream>
using namespace std;
int gcd(int a, int b){if(!(a%b)) return b; return gcd(b, a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}
int main()
{
    int n, ans;
    cin >> n; cin >> n; ans = n;
    while(cin >> n) ans = lcm(ans, n);
    cout << ans;
	return 0;
}