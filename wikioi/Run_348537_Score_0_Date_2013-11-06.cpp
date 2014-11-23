#include <cstdio>
#include <cmath>
using namespace std;
bool is(int n)
{
    if(n == 3 || n == 2) return 1;
    for(int i = 3; i <= sqrt(n); i += 2) if(!(n%i)) return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int i, j;
    for(i = 2; i < n; i += 2) if(is(i)) printf("%d\n", i);
	return 0;
}