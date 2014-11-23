#include <cstdio>
using namespace std;
int gcd(int a, int b)
{
	return (a%b?gcd(b, a%b):b);
}
int main()
{
    int n, a, b;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d%d", &a, &b);
        printf("%d",gcd(a, b));
    }
    return 0;
}