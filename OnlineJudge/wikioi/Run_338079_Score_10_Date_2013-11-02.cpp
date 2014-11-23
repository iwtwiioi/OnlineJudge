#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	return (a%b?gcd(b, a%b):b);
}
int main()
{
    int n, a, b;
    cin >> n;
    while(cin >> a >> b)
        cout << gcd(a, b) << endl;
    return 0;
}