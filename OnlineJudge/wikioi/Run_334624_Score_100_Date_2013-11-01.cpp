#include <iostream>
using namespace std;
unsigned long long f[99];
int main()
{
    int n;
    cin >> n;
    f[1] = 1; f[2] = 2;
    for(int i = 3; i <= n; i++) f[i] = f[i-1]+f[i-2];
    cout << f[n];
	return 0;
}