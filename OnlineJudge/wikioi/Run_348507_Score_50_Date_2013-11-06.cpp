#include <iostream>
#include <cmath>
using namespace std;
bool is(int n)
{
    if(n == 3) return 1;
    int i;
    for(i = 3; i <= sqrt(n); i+=2) if(!(n%i)) return 0;
}
int main()
{
    int n;
    cin >> n;
    int i, j;
    if(n == 1) cout << 2;
    else
    {
    	for(i = 3, j = 2; j <= n; i += 2) if(is(i)) j++;
    	cout << i-2;
    }
	return 0;
}