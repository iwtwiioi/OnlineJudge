#include <cstdio>
#include <cmath>
#define ull unsigned long long
using namespace std;
bool is(ull n)
{
    if(n == 2 || n == 3) return 1;
    if(n < 2) return 0;
    for(ull i = 3; i <= sqrt(n); i+=2) if(!(n%i)) return 0;
    return 1;
}
int main()
{
    ull n;
    scanf("%d", &n);
    if(is(n))
    	printf("Yes\n");
    else
        printf("No\n");
	return 0;
}
	