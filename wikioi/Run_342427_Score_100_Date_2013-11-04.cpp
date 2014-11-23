#include <iostream>
using namespace std;
int gcd(int a, int b, int& x, int& y)
{
    if(!b) {x = 1, y = 0; return a;}
	int d = gcd(b, a%b, y, x);
	y -= a/b*x;
    return d;
}
int main()
{
	int a, b, x, y, d;
	cin >> a >> b;
	d = gcd(a, b, x, y);
    while(x < 0) x += b/d;
	cout << x;
	return 0;
}